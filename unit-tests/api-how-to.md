# API-How-To

## Table of Content

* [Get first RealSense device](api-how-to.md#get-first-realsense-device)
* [Start Streaming with Default Configuration](api-how-to.md#start-streaming-with-default-configuration)
* [Start Streaming Left and Right Infrared Imagers](api-how-to.md#start-streaming-left-and-right-infrared-imagers)
* [Wait for Coherent Set of Frames](api-how-to.md#wait-for-coherent-set-of-frames)
* [Poll for Frames](api-how-to.md#poll-for-frames)
* [Do Processing on a Background-Thread](api-how-to.md#do-processing-on-a-background-thread)
* [Get and Apply Depth-to-Color Extrinsics](api-how-to.md#get-and-apply-depth-to-color-extrinsics)
* [Get Disparity Baseline](api-how-to.md#get-disparity-baseline)
* [Get Video Stream Intrinsics](api-how-to.md#get-video-stream-intrinsics)
* [Get Field of View](api-how-to.md#get-field-of-view)
* [Get Depth Units](api-how-to.md#get-depth-units)
* [Controlling the Laser](api-how-to.md#controlling-the-laser)

## TODO:

* Fetch frame width, height, bytes-per-pixel and stride in bytes
* Fetch frame time-stamp and per-frame metadata
* Get color aligned to depth and vice-versa

## Get first RealSense device

* **librealsense1**:

  ```cpp
  rs::context ctx;
  if (ctx.get_device_count() == 0) 
    throw std::runtime_error("No device detected. Is it plugged in?");
  rs::device & dev = *ctx.get_device(0);
  ```

* **librealsense2**:

  ```cpp
  rs2::context ctx;
  auto list = ctx.query_devices(); // Get a snapshot of currently connected devices
  if (list.size() == 0) 
    throw std::runtime_error("No device detected. Is it plugged in?");
  rs2::device dev = list.front();
  ```

## Start Streaming with Default Configuration

* **librealsense1**:

  ```cpp
  rs::context ctx;
  rs::device & dev = *ctx.get_device(0);
  dev.enable_stream(rs::stream::color, rs::preset::best_quality);
  dev.enable_stream(rs::stream::depth, rs::preset::best_quality);
  dev.start();
  ```

* **librealsense2**:

  ```cpp
  rs2::pipeline pipe;
  pipe.start();
  ```

## Start Streaming Left and Right Infrared Imagers

* **librealsense1**:

  ```cpp
  rs::context ctx;
  rs::device & dev = *ctx.get_device(0);
  dev.enable_stream(rs::stream::infrared, rs::preset::best_quality);
  dev.enable_stream(rs::stream::infrared2, rs::preset::best_quality);
  dev.start();
  ```

* **librealsense2**:

  ```cpp
  rs2::config cfg;
  cfg.enable_stream(RS2_STREAM_INFRARED, 0);
  cfg.enable_stream(RS2_STREAM_INFRARED, 1);
  rs2::pipeline pipe;
  pipe.start(cfg);
  ```

## Wait for Coherent Set of Frames

* **librealsense1**:

  ```cpp
  rs::context ctx;
  rs::device & dev = *ctx.get_device(0);
  dev.enable_stream(rs::stream::color, rs::preset::best_quality);
  dev.enable_stream(rs::stream::depth, rs::preset::best_quality);
  dev.start();
  dev.wait_for_frames();
  dev.get_frame_data(rs::stream::depth); // Pointer to depth pixels, 
  // invalidated by next call to wait/poll for frames
  ```

* **librealsense2**:

  ```cpp
  rs2::pipeline pipe;
  pipe.start();
  rs2::frameset frames = pipe.wait_for_frames();
  rs2::frame frame = frames.first(RS2_STREAM_DEPTH);
  if (frame)
    frame.get_data(); // Pointer to depth pixels, 
                      // invalidated when last copy of frame goes out of scope
  ```

## Poll for Frames

* **librealsense1**:

  ```cpp
  rs::context ctx;
  rs::device & dev = *ctx.get_device(0);
  dev.enable_stream(rs::stream::color, rs::preset::best_quality);
  dev.enable_stream(rs::stream::depth, rs::preset::best_quality);
  dev.start();
  if (dev.poll_for_frames())
    dev.get_frame_data(rs::stream::depth);
  ```

* **librealsense2**:

  ```cpp
  rs2::pipeline pipe;
  pipe.start();
  rs2::frameset frames;
  if (pipe.poll_for_frames(&frames))
  {
    rs2::frame depth_frame = frames.first(RS2_STREAM_DEPTH);
    depth_frame.get_data();
  }
  ```

## Do Processing on a Background-Thread

* **librealsense1**:

  \`\`\`cpp

  rs::context ctx;

  rs::device & dev = \*ctx.get\_device\(0\);

  dev.enable\_stream\(rs::stream::depth, rs::preset::best\_quality\);

  dev.start\(\);

std::mutex m; std::deque&gt; queue; std::thread t\([&](api-how-to.md) { while \(true\) { std::vector frame\_copy; { std::lock\_guard lock\(m\); frame\_copy = queue.front\(\); queue.front\(\); } frame\_copy.data\(\); // Do processing on the frame } }\); t.detach\(\);

while \(true\) { dev.wait\_for\_frames\(\); const auto stream = rs::stream::depth; const auto CAPACITY = 5; // allow max latency of 5 frames uint8\_t bytes\_per\_pixel = 1; switch \(dev.get\_stream\_format\(stream\)\) { case rs::format::raw8: case rs::format::y8: bytes\_per\_pixel = 1; break; case rs::format::z16: case rs::format::disparity16: case rs::format::yuyv: case rs::format::y16: case rs::format::raw10: case rs::format::raw16: bytes\_per\_pixel = 2; break; case rs::format::rgb8: case rs::format::bgr8: bytes\_per\_pixel = 3; break; case rs::format::rgba8: case rs::format::bgra8: case rs::format::xyz32f: bytes\_per\_pixel = 4; break; } auto ptr = \(uint8\_t_\)dev.get\_frame\_data\(rs::stream::depth\); std::vector frame\_copy\( // Deep-copy the frame data ptr, ptr + dev.get\_stream\_width\(stream\)_  dev.get\_stream\_height\(stream\) \* bytes\_per\_pixel\); { std::lock\_guard lock\(m\); if \(queue.size\(\) &lt; CAPACITY\) queue.push\_back\(frame\_copy\); } }

```text
* **librealsense2**:
```cpp
rs2::pipeline pipe;
pipe.start();

const auto CAPACITY = 5; // allow max latency of 5 frames
rs2::frame_queue queue(CAPACITY);
std::thread t([&]() {
    while (true)
    {
        rs2::depth_frame frame;
        if (queue.poll_for_frame(&frame))
        {
            frame.get_data();
            // Do processing on the frame
        }
    }
});
t.detach();

while (true)
{
    auto frames = pipe.wait_for_frames();
    queue.enqueue(frames.get_depth_frame());
}
```

## Get and Apply Depth-to-Color Extrinsics

* **librealsense1**:

  ```cpp
  rs::context ctx;
  rs::device & dev = *ctx.get_device(0);
  dev.enable_stream(rs::stream::color, rs::preset::best_quality);
  dev.enable_stream(rs::stream::depth, rs::preset::best_quality);
  dev.start();
  rs::extrinsics e = dev.get_extrinsics(rs::stream::depth, rs::stream::color);
  // Apply extrinsics to the origin
  auto color_point = e.transform({ 0.f, 0.f, 0.f });
  ```

* **librealsense2**:

  ```cpp
  rs2::pipeline pipe;
  rs2::pipeline_profile selection = pipe.start();
  auto depth_stream = selection.get_stream(RS2_STREAM_DEPTH);
  auto color_stream = selection.get_stream(RS2_STREAM_COLOR);
  rs2_extrinsics e = depth_stream.get_extrinsics_to(color_stream);
  // Apply extrinsics to the origin
  float origin[3] { 0.f, 0.f, 0.f };
  float target[3];
  rs2_transform_point_to_point(target, &e, origin);
  ```

## Get Disparity Baseline

* **librealsense1**:

  ```cpp
  rs::context ctx;
  rs::device & dev = *ctx.get_device(0);
  dev.enable_stream(rs::stream::infrared, rs::preset::best_quality);
  dev.enable_stream(rs::stream::infrared2, rs::preset::best_quality);
  dev.start();
  rs_extrinsics e = dev.get_extrinsics(rs::stream::infrared, rs::stream::infrared2);
  auto baseline = e.translation[0];
  ```

* **librealsense2**:

  ```cpp
  rs2::config cfg;
  cfg.enable_stream(RS2_STREAM_INFRARED, 1);
  cfg.enable_stream(RS2_STREAM_INFRARED, 2);
  rs2::pipeline pipe;
  rs2::pipeline_profile selection = pipe.start(cfg);
  auto ir1_stream = selection.get_stream(RS2_STREAM_INFRARED, 1);
  auto ir2_stream = selection.get_stream(RS2_STREAM_INFRARED, 2);
  rs2_extrinsics e = ir1_stream.get_extrinsics_to(ir2_stream);
  auto baseline = e.translation[0];
  ```

## Get Video Stream Intrinsics

* **librealsense1**:

  \`\`\`cpp

  rs::context ctx;

  rs::device & dev = \*ctx.get\_device\(0\);

  dev.enable\_stream\(rs::stream::infrared, rs::preset::best\_quality\);

  dev.enable\_stream\(rs::stream::infrared2, rs::preset::best\_quality\);

  dev.start\(\);

rs::intrinsics i = dev.get\_stream\_intrinsics\(rs::stream::depth\); auto principal\_point = std::make\_pair\(i.ppx, i.ppy\); auto focal\_length = std::make\_pair\(i.fx, i.fy\); auto resolution = std::make\_pair\(i.width, i.height\); rs\_distortion model = i.model;

```text
* **librealsense2**:
```cpp
rs2::pipeline pipe;
rs2::pipeline_profile selection = pipe.start();
auto depth_stream = selection.get_stream(RS2_STREAM_DEPTH)
                             .as<rs2::video_stream_profile>();
auto resolution = std::make_pair(depth_stream.width(), depth_stream.height());
auto i = depth_stream.get_intrinsics();
auto principal_point = std::make_pair(i.ppx, i.ppy);
auto focal_length = std::make_pair(i.fx, i.fy);
rs2_distortion model = i.model;
```

## Get Field of View

* **librealsense1**:

  \`\`\`cpp

  rs::context ctx;

  rs::device & dev = \*ctx.get\_device\(0\);

  dev.enable\_stream\(rs::stream::infrared, rs::preset::best\_quality\);

  dev.enable\_stream\(rs::stream::infrared2, rs::preset::best\_quality\);

  dev.start\(\);

rs::intrinsics i = dev.get\_stream\_intrinsics\(rs::stream::depth\); float fov\[2\] = { i.hfov, i.vfov };

```text
* **librealsense2**:
```cpp
rs2::pipeline pipe;
rs2::pipeline_profile selection = pipe.start();
auto depth_stream = selection.get_stream(RS2_STREAM_DEPTH)
                             .as<rs2::video_stream_profile>();
auto i = depth_stream.get_intrinsics();
float fov[2]; // X, Y fov
rs2_fov(&i, fov);
```

## Get Depth Units

* **librealsense1**:

  \`\`\`cpp

  rs::context ctx;

  rs::device & dev = \*ctx.get\_device\(0\);

  dev.enable\_stream\(rs::stream::infrared, rs::preset::best\_quality\);

  dev.enable\_stream\(rs::stream::infrared2, rs::preset::best\_quality\);

  dev.start\(\);

auto scale = dev.get\_depth\_scale\(\);

```text
* **librealsense2**:
```cpp
rs2::pipeline pipe;
rs2::pipeline_profile selection = pipe.start();

// Find first depth sensor (devices can have zero or more then one)
auto sensor = selection.get_device().first<rs2::depth_sensor>();
auto scale =  sensor.get_depth_scale();
```

## Controlling the Laser

* **librealsense1**:

  \`\`\`cpp

  rs::context ctx;

  rs::device & dev = \*ctx.get\_device\(0\);

if \(dev.supports\_option\(rs::option::r200\_emitter\_enabled\)\) // For R200 family { dev.set\_option\(rs::option::r200\_emitter\_enabled, 1.f\); // Enable laser emitter dev.set\_option\(rs::option::r200\_emitter\_enabled, 0.f\); // Disable laser } if \(dev.supports\_option\(rs::option::f200\_laser\_power\)\) // For F200 and SR300 { double min, max, step; // Query min and max values: dev.get\_option\_range\(rs::option::f200\_laser\_power, min, max, step\); dev.set\_option\(rs::option::f200\_laser\_power, max\); // Enable laser \(max power\) dev.set\_option\(rs::option::f200\_laser\_power, 0.f\); // Disable laser emitter }

```text
* **librealsense2**:
```cpp
rs2::pipeline pipe; 
rs2::pipeline_profile selection = pipe.start();
rs2::device selected_device = selection.get_device();
auto depth_sensor = selected_device.first<rs2::depth_sensor>();

if (depth_sensor.supports(RS2_OPTION_EMITTER_ENABLED))
{
    depth_sensor.set_option(RS2_OPTION_EMITTER_ENABLED, 1.f); // Enable emitter
    depth_sensor.set_option(RS2_OPTION_EMITTER_ENABLED, 0.f); // Disable emitter
}
if (depth_sensor.supports(RS2_OPTION_LASER_POWER))
{
    // Query min and max values:
    auto range = depth_sensor.get_option_range(RS2_OPTION_LASER_POWER);
    depth_sensor.set_option(RS2_OPTION_LASER_POWER, range.max); // Set max power
    depth_sensor.set_option(RS2_OPTION_LASER_POWER, 0.f); // Disable laser
}
```

