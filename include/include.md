# readme

## librealsense2 API

## File-System Structure

Under `librealsense2` folder you will find two subfolers:

* [h](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/h/README.md) - Contains headers for the C language
* [hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/README.md) - Contains headers for the C++ language, depends on C headers

In addition, you can include [&lt;librealsense2/rs.h&gt;](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/rs.h) and [&lt;librealsense2/rs.hpp&gt;](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/rs.hpp) to get most of SDK functionality in C and C++ respectively.

[&lt;librealsense2/rs\_advanced\_mode.h&gt;](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/rs_advanced_mode.h) and [&lt;librealsense2/rs\_advanced\_mode.hpp&gt;](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/rs_advanced_mode.hpp) can be included to get the extra [Advanced Mode](../doc/rs400_advanced_mode.md) functionality \(in C and C++ respectively\).

[&lt;librealsense2/rsutil.h&gt;](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/rsutil.h) contains mathematical helper functions for projection of 2D points into 3D space and back.

## Files and Classes

> For full up-to-date class documentation see [Doxygen class-list](http://intelrealsense.github.io/librealsense/doxygen/annotated.html)

### [rs\_types.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp):

This file contains common functionality like the exception types. See [Error Handling](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/..doc/error_handling.md)

| Class | Description |
| :--- | :--- |
| [error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L76) | Common base-class for all exceptions thrown from the SDK |
| [recoverable\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L113) | Base class for all recorverable \(in software\) errors |
| [unrecoverable\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L114) | Base class for non-recoverable errors |
| [camera\_disconnected\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L115) | Camera Disconnected error |
| [backend\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L116) | Error from the underlying OS-specific driver |
| [device\_in\_recovery\_mode\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L117) | Device requires firmware update |
| [invalid\_value\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L118) | Invalid input was passed to a function |
| [wrong\_api\_call\_sequence\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L119) | Methods were called in wrong order |
| [not\_implemented\_error](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_types.hpp#L120) | Functionality is not available error |

### [rs\_context.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_context.hpp):

Context can be used to enumerate and iterate over connected device, and also get notifications of device events.

| Class | Description |
| :--- | :--- |
| [context](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_context.hpp#L81) | Context serve as a factory for all SDK devices |
| [device\_hub](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_context.hpp#L185) | Helper class that simplifies handling device change events |
| [event\_information](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_context.hpp#L16) | Information about device change |

### [rs\_device.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_device.hpp):

This file defines the concept of RealSense device.

| Class | Description |
| :--- | :--- |
| [device](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_device.hpp#L109) | Encapsulates Intel RealSense device |
| [device\_list](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_device.hpp#L186) | Wrapper around list of devices |
| [debug\_protocol](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_device.hpp#L151) | Debug-extension that allows to send data directly to the firmware |

### [rs\_processing.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp):

The SDK offers many types of post-processing in form of the Processing Blocks. These primitives can be pipelined using queues and configured using options.

| Class | Description |
| :--- | :--- |
| [syncer](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L260) | Processing block that accepts frames one-by-one and outputs coherent framesets |
| [frame\_queue](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L136) | Basic primitive abstracting a concurrent queue of frames |
| [processing\_block](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L105) | Base class for frame processing functions |
| [pointcloud](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L196) | Processing block that accepts depth and texture frames and outputs 3D points with texture coordinates |
| [asynchronous\_syncer](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L232) | Non-blocking version of the syncher processing block |
| [align](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L316) | Processing block that accepts frames from different viewports and generates new synthetic frames from a single given viewport |
| [colorizer](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L356) | Processing block that accepts depth frames in Z16 format and outputs depth frames in RGB format, applying some depth coloring |
| [decimation\_filter](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L391) | Processing block that intelligently reduces the resolution of a depth frame |
| [temporal\_filter](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L428) | Processing block that filters depth data by looking into previous frames |
| [spatial\_filter](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_processing.hpp#L465) | Processing block that applies edge-preserving smoothing of depth data |

### [rs\_sensor.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_sensor.hpp):

RealSense devices contain sensors. Sensors are units of streaming, each sensor can be controlled individually.

| Class | Description |
| :--- | :--- |
| [sensor](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_sensor.hpp#L392) | Base class for all supported sensors |
| [roi\_sensor](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_sensor.hpp#L446) | Sensor that has the ability to focus on a given ROI |
| [notification](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_sensor.hpp#L15) | Asynchronious message that can be passed to the application |
| [depth\_sensor](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_sensor.hpp#L479) | Sensor that can provide depth frames |

### [rs\_frame.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp):

The output of sensors are frames. There are different kinds of frames, not all video frames.

| Class | Description |
| :--- | :--- |
| [frame](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L157) | Base class for all frames |
| [points](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L423) | Set of 3D points with texture coordinates |
| [video\_frame](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L348) | 2D image \(with width, height and bpp\) |
| [depth\_frame](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L480) | Depth frame |
| [frameset](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L502) | A set of frames |
| [stream\_profile](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L24) | Base class for sensor configuration |
| [video\_stream\_profile](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_frame.hpp#L113) | Video stream configuration |

### [rs\_pipeline.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_pipeline.hpp):

Pipeline is a high-level primitive combining several sensors and processing steps into one simple API.

| Class | Description |
| :--- | :--- |
| [pipeline](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_pipeline.hpp#L345) | High level data-processor combining several sensors, queues and processing blocks |
| [pipeline\_profile](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_pipeline.hpp#L22) | Selected pipeline configuration |
| [config](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_pipeline.hpp#L128) | Desired pipeline configuration |

### [rs\_record\_playback.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_record_playback.hpp):

This file adds playback and record capability using ROS-bag files. See [src/media](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/src/media/README.md)

| Class | Description |
| :--- | :--- |
| [playback](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_record_playback.hpp#L30) | Device that mimiks live device from given input file |
| [recorder](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_record_playback.hpp#L206) | Device that records live device into an output file |

### [rs\_internal.hpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_internal.hpp):

This file is not intented to be included by SDK users, but rather is used in SDK unit-tests. It allows to record everything that will happen in a specific test into a file and later use that file for dependency injection.

| Class | Description |
| :--- | :--- |
| [recording\_context](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_internal.hpp#L19) | Context that records all backend activity to file |
| [mock\_context](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/include/librealsense2/hpp/rs_internal.hpp#L41) | Context that replays all activity from file |

