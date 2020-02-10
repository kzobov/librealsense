# Recorded Camera Data

**Intel® RealSense™ SDK 2.0** supports working with pre-recorded data \([learn more](https://github.com/IntelRealSense/librealsense/blob/master/src/media/readme.md)\).

All files below can be opened using the [RealSense Viewer](https://github.com/IntelRealSense/librealsense/releases/download/v2.8.0/Intel.RealSense.Viewer.exe) \(`Add Source` &gt; `Load Recorded Sequence` or just drag & drop into the Viewer\) In addition, you can make any of the provided [examples](https://github.com/IntelRealSense/librealsense/tree/master/examples) run from file, by replacing `pipe.start()` with:

```cpp
rs2::config cfg;
cfg.enable_device_from_file(<filename>);
pipe.start(cfg); // Load from file
```

`*.bag` files contain uncompressed and unfiltered data and hence tend to be rather large \(in the order of 100 MB per one second of recording\). Our file-format is an extension of open [ROS-bag](http://wiki.ros.org/rosbag) format, meaning they can also be opened using existing robotics tools like [rqt-bag](http://wiki.ros.org/rqt_bag)

> **Disclaimer**: The files below are not official marketing material. These are captured using pre-production hardware with the sole purpose of helping developers, makers and students get started with RealSense technology

## Files

|  |  |
| :--- | :--- |
|  | Outdoors scene captured with D415 pre-production sample \(Depth from Stereo\) |
|  | Flight of stairs captured D435 pre-production sample \(Depth from Stereo\) |
|  | Short-range scene captured with the SR300 Depth Camera \(Structured Light technology\) |
|  | Scene captured with pre-production D415 device \(Depth from Stereo\) with objects submerged under water [![Binder](https://mybinder.org/badge.svg)](https://mybinder.org/v2/gh/IntelRealSense/librealsense/jupyter?filepath=notebooks/depth_under_water.ipynb) |

