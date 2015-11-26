/*
    INTEL CORPORATION PROPRIETARY INFORMATION This software is supplied under the
    terms of a license agreement or nondisclosure agreement with Intel Corporation
    and may not be copied or disclosed except in accordance with the terms of that
    agreement.
    Copyright(c) 2015 Intel Corporation. All Rights Reserved.
*/

#pragma once
#ifndef LIBREALSENSE_TYPES_H
#define LIBREALSENSE_TYPES_H

#include "../include/librealsense/rs.h"

#include <cassert>                          // For assert
#include <cstring>                          // For memcmp
#include <vector>                           // For vector
#include <memory>                           // For shared_ptr
#include <sstream>                          // For ostringstream
#include <atomic>

//#define ENABLE_DEBUG_SPAM

#if defined(_DEBUG) || defined(DEBUG)
#define ENABLE_DEBUG_OUTPUT
#endif

#ifdef ENABLE_DEBUG_OUTPUT
#include <iostream> // For cout, cerr, endl. DO NOT INCLUDE ANYWHERE ELSE IN LIBREALSENSE 
#define DEBUG_OUT(...) std::cout << "[debug] " << __VA_ARGS__ << std::endl
#define DEBUG_ERR(...) std::cerr << "[error] " << __VA_ARGS__ << std::endl
#else
#define DEBUG_OUT(...) do {} while(false)
#define DEBUG_ERR(...) do {} while(false)
#endif

#define RS_STREAM_NATIVE_COUNT 4

namespace rsimpl
{
    enum class byte : uint8_t {};

    // Enumerated type support
    #define RS_ENUM_HELPERS(TYPE, PREFIX) const char * get_string(TYPE value); \
        inline bool is_valid(TYPE value) { return value >= 0 && value < RS_##PREFIX##_COUNT; } \
        inline std::ostream & operator << (std::ostream & out, TYPE value) { if(is_valid(value)) return out << get_string(value); else return out << (int)value; }
    RS_ENUM_HELPERS(rs_stream, STREAM)
    RS_ENUM_HELPERS(rs_format, FORMAT)
    RS_ENUM_HELPERS(rs_preset, PRESET)
    RS_ENUM_HELPERS(rs_distortion, DISTORTION)
    RS_ENUM_HELPERS(rs_option, OPTION)
    #undef RS_ENUM_HELPERS

    // World's tiniest linear algebra library
    struct float3 { float x,y,z; float & operator [] (int i) { return (&x)[i]; } };
    struct float3x3 { float3 x,y,z; float & operator () (int i, int j) { return (&x)[j][i]; } }; // column-major
    struct pose { float3x3 orientation; float3 position; };
    inline bool operator == (const float3 & a, const float3 & b) { return a.x==b.x && a.y==b.y && a.z==b.z; }
    inline float3 operator + (const float3 & a, const float3 & b) { return {a.x+b.x, a.y+b.y, a.z+b.z}; }
    inline float3 operator * (const float3 & a, float b) { return {a.x*b, a.y*b, a.z*b}; }
    inline bool operator == (const float3x3 & a, const float3x3 & b) { return a.x==b.x && a.y==b.y && a.z==b.z; }
    inline float3 operator * (const float3x3 & a, const float3 & b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
    inline float3x3 operator * (const float3x3 & a, const float3x3 & b) { return {a*b.x, a*b.y, a*b.z}; }
    inline float3x3 transpose(const float3x3 & a) { return {{a.x.x,a.y.x,a.z.x}, {a.x.y,a.y.y,a.z.y}, {a.x.z,a.y.z,a.z.z}}; }
    inline bool operator == (const pose & a, const pose & b) { return a.orientation==b.orientation && a.position==b.position; }
    inline float3 operator * (const pose & a, const float3 & b) { return a.orientation * b + a.position; }
    inline pose operator * (const pose & a, const pose & b) { return {a.orientation * b.orientation, a * b.position}; }
    inline pose inverse(const pose & a) { auto inv = transpose(a.orientation); return {inv, inv * a.position * -1}; }

    inline bool operator == (const rs_intrinsics & a, const rs_intrinsics & b) { return std::memcmp(&a, &b, sizeof(a)) == 0; }

    inline uint32_t pack(uint8_t c0, uint8_t c1, uint8_t c2, uint8_t c3)
    {
        return (c0 << 24) | (c1 << 16) | (c2 << 8) | c3;
    }

    // Static camera info
    struct stream_request
    {
        bool enabled;
        int width, height;
        rs_format format;
        int fps;
    };

    struct subdevice_mode;
    
    struct unpacker_setting
    {
        void (* unpacker)(byte * const dest[], const byte * source, const subdevice_mode & mode);
        std::vector<std::pair<rs_stream, rs_format>> outputs;

        bool provides_stream(rs_stream stream) const { for(auto & o : outputs) if(o.first == stream) return true; return false; }
        rs_format get_format(rs_stream stream) const { for(auto & o : outputs) if(o.first == stream) return o.second; throw std::logic_error("missing output"); }
    };

    struct native_pixel_format
    {
        uint32_t fourcc;
        int plane_count;
        int macropixel_width;
        size_t macropixel_size;
        std::vector<unpacker_setting> unpackers;

        size_t get_image_size(int width, int height) const
        {
            assert(width % macropixel_width == 0);
            return (width / macropixel_width) * height * macropixel_size * plane_count;
        }
        size_t get_crop_offset(int width, int crop) const
        {
            assert(plane_count == 1);
            return get_image_size(width, crop) + get_image_size(crop, 1);
        }
    };

    struct int2 { int x,y; };

    struct pad_crop_setting { int pad_crop, intrinsics_index; };

    struct subdevice_mode
    {
        int subdevice;                          // 0, 1, 2, etc...
        int width, height;                      // Resolution advertised over UVC
        const native_pixel_format * pf;         // Pixel format advertised over UVC
        int fps;                                // Framerate advertised over UVC
        int2 content_size;                      // Size of image content, may be different from UVC frame size
        std::vector<pad_crop_setting> pad_crop; // Acceptable padding/cropping values
        int (* frame_number_decoder)(const subdevice_mode & mode, const void * frame);
        bool use_serial_numbers_if_unique;  // If true, ignore frame_number_decoder and use a serial frame count if this is the only mode set
    };

    struct subdevice_mode_selection
    {
        const subdevice_mode * mode;
        size_t pad_crop_index;
        size_t unpacker_index;

        subdevice_mode_selection(const subdevice_mode * mode, size_t pad_crop_index, size_t unpacker_index) : mode(mode), pad_crop_index(pad_crop_index), unpacker_index(unpacker_index) {}

        const std::vector<std::pair<rs_stream, rs_format>> & get_outputs() const { return mode->pf->unpackers[unpacker_index].outputs; }
        int get_pad_crop() const { return mode->pad_crop[pad_crop_index].pad_crop; }
        int get_width() const { return mode->content_size.x + get_pad_crop() * 2; }
        int get_height() const { return mode->content_size.y + get_pad_crop() * 2; }
        size_t get_image_size(rs_stream stream) const;
        bool provides_stream(rs_stream stream) const { return mode->pf->unpackers[unpacker_index].provides_stream(stream); }
        int get_intrinsics_index(rs_stream stream) const { return mode->pad_crop[pad_crop_index].intrinsics_index; }
        rs_format get_format(rs_stream stream) const { return mode->pf->unpackers[unpacker_index].get_format(stream); }
        int get_framerate(rs_stream stream) const { return mode->fps; }
        void unpack(byte * const dest[], const byte * source) const;
    };

    struct interstream_rule // Requires a.*field + delta == b.*field OR a.*field + delta2 == b.*field
    {
        rs_stream a, b;        
        int stream_request::* field;
        int delta, delta2;
    };

    struct static_device_info
    {
        std::string name;                                                   // Model name of the camera
        int stream_subdevices[RS_STREAM_NATIVE_COUNT];                      // Which subdevice is used to support each stream, or -1 if stream is unavailable
        std::vector<subdevice_mode> subdevice_modes;                        // A list of available modes each subdevice can be put into
        std::vector<interstream_rule> interstream_rules;                    // Rules which constrain the set of available modes
        stream_request presets[RS_STREAM_NATIVE_COUNT][RS_PRESET_COUNT];    // Presets available for each stream
        bool option_supported[RS_OPTION_COUNT];                             // Whether or not a given option is supported on this camera
        pose stream_poses[RS_STREAM_NATIVE_COUNT];                          // Static pose of each camera on the device
        int num_libuvc_transfer_buffers;                                    // Number of transfer buffers to use in LibUVC backend
        std::string firmware_version;                                       // Firmware version string
        std::string serial;                                                 // Serial number of the camera (from USB or from SPI memory)
        float nominal_depth_scale;                                          // Default scale

        static_device_info();

        subdevice_mode_selection select_mode(const stream_request (&requests)[RS_STREAM_NATIVE_COUNT], int subdevice_index) const;
        std::vector<subdevice_mode_selection> select_modes(const stream_request (&requests)[RS_STREAM_NATIVE_COUNT]) const;
    };
    static_device_info add_standard_unpackers(const static_device_info & device_info);

    // Thread-safe, non-blocking, lock-free triple buffer for marshalling data from a producer thread to a consumer thread
    template<class T> class triple_buffer
    {
        struct { T x; int id; } buffers[3]; // Three distinct values each tagged with a unique identifier
        int front = 0, back = 2;            // Determines which buffer is currently the "front" buffer (accessed only by consumer thread) and "back" buffer (accessed only by producer thread)
        std::atomic<int> middle;            // Determines which buffer is currently the "middle" buffer (available to be atomically swapped with from either thread)
        std::atomic<int> counter;           // Sequentially increasing counter, read from both threads and written by UVC thread
    public:
        triple_buffer(T value) : middle(1), counter(0) { for(auto & b : buffers) { b.x = value; b.id = 0; } }

        int get_count() const { return counter.load(std::memory_order_relaxed); }
        T & get_back() { return buffers[back].x; }
        void swap_back()
        {
            int id = counter.load(std::memory_order_relaxed) + 1;   // Compute new sequentially increasing unique ID
            buffers[back].id = id;                                  // Tag value with this unique ID
            back = middle.exchange(back);                           // Swap new value into middle buffer
            counter.store(id, std::memory_order_release);           // Perform this store last to force writes to become visible to consumer thread
        }

        bool has_front() const { return buffers[front].id > 0; }
        const T & get_front() const { return buffers[front].x; }
        bool swap_front()
        {
            auto id = counter.load(std::memory_order_acquire);              // Perform this load first to force producer thread's writes to become visible
            if(buffers[front].id == id) return false;                       // If the front buffer is up-to-date, return false
            while(buffers[front].id < id) front = middle.exchange(front);   // Swap until we retrieve the new value
            return true;                                                    // Return true to indicate front buffer was updated
        }
    };

    // Buffer for storing images provided by a given stream
    class stream_buffer
    {
        struct frame
        {
            std::vector<byte>               data;
            int                             timestamp;  // DS4 frame number or IVCAM rolling timestamp, used to compute LibRealsense frame timestamp
            int                             delta;      // Difference between the last two timestamp values, used to estimate next frame arrival time
        };

        subdevice_mode_selection            selection;
        triple_buffer<frame>                frames;
        int                                 last_frame_number;
    public:
                                            stream_buffer(subdevice_mode_selection selection, rs_stream stream);

        const subdevice_mode_selection &    get_mode() const { return selection; }

        const byte *                        get_front_data() const { return frames.get_front().data.data(); }
        int                                 get_front_number() const { return frames.get_front().timestamp; }
        int                                 get_front_delta() const { return frames.get_front().delta; }
        bool                                is_front_valid() const { return frames.has_front(); }

        byte *                              get_back_data() { return frames.get_back().data.data(); }
        void                                swap_back(int frame_number);
        bool                                swap_front() { return frames.swap_front(); }
    };

    class intrinsics_buffer
    {
        struct state { std::vector<rs_intrinsics> intrin, rect_intrin; };
        mutable triple_buffer<state> buffer;
    public:
        intrinsics_buffer() : buffer({}) {}

        rs_intrinsics get(int index) const
        {
            buffer.swap_front(); // We are logically const even though we check for updates, visible state will never change unless someone calls set
            return buffer.get_front().intrin[index];
        }

        rs_intrinsics get_rect(int index) const
        {
            buffer.swap_front(); // We are logically const even though we check for updates, visible state will never change unless someone calls set
            return buffer.get_front().rect_intrin[index];
        }

        void set(std::vector<rs_intrinsics> intrinsics)
        {
            buffer.get_back().intrin = buffer.get_back().rect_intrin = move(intrinsics);
            buffer.swap_back();
        }

        void set(std::vector<rs_intrinsics> intrinsics, std::vector<rs_intrinsics> rect_intrinsics)
        {
            buffer.get_back().intrin = move(intrinsics);
            buffer.get_back().rect_intrin = move(rect_intrinsics);
            buffer.swap_back();
        }
    };

    struct device_config
    {
        const static_device_info            info;
        intrinsics_buffer                   intrinsics;
        stream_request                      requests[RS_STREAM_NATIVE_COUNT];  // Modified by enable/disable_stream calls
        float                               depth_scale;                       // Scale of depth values

                                            device_config(const rsimpl::static_device_info & info, std::vector<rs_intrinsics> intrin, std::vector<rs_intrinsics> rect_intrin) : info(info), depth_scale(info.nominal_depth_scale) 
                                            { 
                                                for(auto & req : requests) req = rsimpl::stream_request(); 
                                                intrinsics.set(intrin, rect_intrin);
                                            }

        std::vector<subdevice_mode_selection> select_modes() const { return info.select_modes(requests); }
    };

    // Utilities
    struct to_string
    {
        std::ostringstream ss;
        template<class T> to_string & operator << (const T & val) { ss << val; return *this; }
        operator std::string() const { return ss.str(); }
    };

    #pragma pack(push, 1)
    template<class T> class big_endian
    {
        T be_value;
    public:
        operator T () const
        {
            T le_value = 0;
            for(int i=0; i<sizeof(T); ++i) reinterpret_cast<char *>(&le_value)[i] = reinterpret_cast<const char *>(&be_value)[sizeof(T)-i-1];
            return le_value;
        }
    };
    #pragma pack(pop)
}

#endif
