# Sample Code for Intel® RealSense™ cameras

**Code Examples to start prototyping quickly:** These simple examples demonstrate how to easily use the SDK to include code snippets that access the camera into your applications.

For mode advanced usages please review the list of [Tools](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/tools/README.md) we provide.

For a detailed explanations and API documentation see our [Documentation](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/doc/README.md) section

## List of Samples:

### C++ Examples:

#### Basic

1. [Capture](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/capture/README.md) - Show how to syncronize and render multiple streams: left & right imagers, depth and RGB streams.
2. [Save To Disk](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/save-to-disk/README.md) - Demonstrate how to render and save video streams on headless systems without graphical user interface \(GUI\).
3. [Multicam](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/multicam/README.md) - Present multiple cameras depth streams simultaneously, in separate windows.
4. [Pointcloud](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/pointcloud/README.md) - Showcase Projection API while generating and rendering 3D pointcloud.

   **Intermediate**

5. [Streams Alignment](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/align/README.md) - Show a simple method for dynamic background removal from video.
6. [Depth Post Processing](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/post-processing/README.md) - Demonstrating usage of post processing filters for depth images.
7. [Record and Playback](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/record-playback/README.md) - Demonstrating usage of the recorder and playback devices.

   **Advanced**

8. [Software Device](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/software-device/README.md) - Shows how to create a custom `rs2::device`.
9. [Sensor Control](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/sensor-control/README.md) -- A tutorial for using the `rs2::sensor` API
10. [Measure](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/measure/README.md) - Lets the user measure the dimentions of 3D objects in a stream.

### C Examples:

1. [Depth](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/C/depth/README.md) - Demonstrates how to stream depth data and prints a simple text-based representation of the depth image.
2. [Distance](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/C/distance/README.md) - Print the distance from the camera to the object in the center of the image.
3. [Color](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/examples/C/color/README.md) - Demonstrate how to stream color data and prints some frame information.

### CV Examples:

> See [getting started with OpenCV and RealSense](https://github.com/IntelRealSense/librealsense/tree/master/wrappers/opencv)

1. [ImShow](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/wrappers/opencv/imshow/README.md) - Minimal OpenCV application for visualizing depth data
2. [GrabCuts](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/wrappers/opencv/grabcuts/README.md) - Simple background removal using the GrabCut algorithm
3. [Latency-Tool](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/wrappers/opencv/latency-tool/README.md) - Basic latency estimation using computer vision
4. [DNN](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/wrappers/opencv/dnn/README.md) - Intel RealSense camera used for real-time object-detection

### Community Projects:

1. [OpenCV DNN object detection with RealSense camera](https://github.com/twMr7/rscvdnn)
2. [minimal\_realsense2](https://github.com/SirDifferential/minimal_realsense2) - Streaming and Presets in C
3. [ANDREASJAKL.COM](https://www.andreasjakl.com/capturing-3d-point-cloud-intel-realsense-converting-mesh-meshlab/) - Capturing a 3D Point Cloud with Intel RealSense and Converting to a Mesh with MeshLab
4. [FluentRealSense](https://www.codeproject.com/Articles/1233892/FluentRealSense-The-First-Steps-to-a-Simpler-RealS) - The First Steps to a Simpler RealSense

