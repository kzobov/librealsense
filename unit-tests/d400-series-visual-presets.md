# D400-Series-Visual-Presets

## Overview

The [Intel® RealSense™ Viewer](https://github.com/IntelRealSense/librealsense/tree/master/tools/realsense-viewer%20) tool supports several predefined depth presets that can be selected according to the user's usage. The predefined presets are listed in the table below. The table explains some of the recommended use cases for each predefined preset. There are also examples of images with each preset and a corresponding JSON file.  
 The user can also modify the settings via the Advanced Mode menu and save a customized user preset. All the settings can be saved and loaded via the tool's menu. We use machine learning algorithms and capture of ground truth datasets to optimize preset for certain conditions, and we may add more presets in the future. The developers can do this too, or just start adjusting the parameters by hand, but we do not provide guidance on this. The key to good depth is to start from our recommended defaults:

* D435: Use 848x480 resolution @30fps, with auto-exposure.  Use post processing with downsample 2.   
* D415: Use 1280x720 resolution @30fps, with auto-exposure. Use post processing with downsample 3.

If you have bad depth, please first try to use manual exposure and adjust exposure. Keep gain as low as possible \(preferably 16\).

For further information, please refer to "_Best Known Methods for Tuning Intel RealSense Depth Cameras D415 and D435_" at [https://realsense.intel.com/intel-realsense-downloads/\#whitepaper](https://realsense.intel.com/intel-realsense-downloads/#whitepaper).

## Supported Devices

Please refer to [latest release](https://github.com/IntelRealSense/librealsense/releases/latest) for the supported devices and platforms.

## Preset Table

Note: Some of the presets are different based on the resolution and some are the same for all resolutions. The resolution range is:

* High Res  - 1280x720 or 848x480
* Med Res - 640x480 or 640x360
* Low Res  - 480x270 or 424x240

| Resolution  Preset | Use Cases recommended for usage | Resolution Based? | JSON files |
| :--- | :--- | :--- | :--- |
| High Density | Higher Fill factor, sees more objects. \(Ex. BGS and 3D Enhanced Photography,  Object recognition\) | Yes | [HighResHighDensityPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/HighResHighDensityPreset.json), [MedResHighDensityPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/MidResHighDensityPreset.json), [LowResHighDensityPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/LowResHighDensityPreset.json) |
| Medium Density | Balance between Fill factor and accuracy. | Yes | [HighResMedDensityPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/HighResMidDensityPreset.json),  [MedResMedDensityPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/MidResMidDensityPreset.json), [LowResMedDensityPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/LowResMidDensityPreset.json) |
| High Accuracy | High confidence threshold value of depth, lower fill factor.  \(Ex. Object Scanning,  Collision Avoidance, Robots\) | Yes | [HighResHighAccuracyPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/HighResHighAccuracyPreset.json), [MedResHighAccuracyPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/MidResHighAccuracyPreset.json), [LowResHighAccuracyPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/LowResHighAccuracyPreset.json) |
| Hand | Good for Hand Tracking,  Gesture recognition, good edges | No | [HandGesturePreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/HandGesturePreset.json) |
| Left Imager Color w/o IR Pattern | Removes the Projector-generated IR pattern from left imager when streaming synthetic RGB.  Applies to D415 and D410 Devices.  Supported since FW ver 5.9.10+ | No | [D415\_RemoveIR.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/D415_RemoveIR.json) |
| Default | Best Visual appeal, Clean edges,  Reduced PointCloud Spraying | No | [DefaultPreset\_D415.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/DefaultPreset_D415.json), [DefaultPreset\_D435.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/DefaultPreset_D435.json) |

  
Additional Presets not in the Viewer:

| Preset Use case | JSON file | Notes |
| :--- | :--- | :--- |
| Vacuum Cleaner | [ShortRangePreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/ShortRangePreset.json) |  |
| Body Scan | [BodyScanPreset.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/BodyScanPreset.json) |  |
| Edge Map | [EdgeMapD435.json](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/d400_presets/EdgeMapD435.json) | **Edges** ![](https://raw.githubusercontent.com/wiki/IntelRealSense/librealsense/res/edgemap.jpg) |

## Example Pictures

Please refer to the example pictures below captured with the various presets. The depth presets are evaluated and compared based on:

* Depth quality based on a 3D scene configured to include a variety of object types, textures, and distances.
* A flat target depth metric test

All pictures were taken with these settings/conditions:

* Resolution: 1280 x 720
* Frame Rate: 30
* Auto Exposure: On
* Ambient fluorescent lighting \(~100 - 200 lx\)

## RGB Images

The following RGB images captured as a test scene with objects ranging from ~0.6m \(foreground cube and hand\) to ~2m \(back wall\) from camera.

**D415 Camera**  
![](https://user-images.githubusercontent.com/17433152/35091542-d20b510c-fc34-11e7-8f7d-9d319d39fa54.png)

  
  
**D435 Camera**  
![](https://user-images.githubusercontent.com/17433152/35097687-12dea03a-fc49-11e7-9b32-7bca0731d81b.png)

## Corresponding Depth images using Visual Presets

* **Default Preset**

  Best visual appeal, clean edges and reduced Point Cloud spraying.  

**D415 Camera**  
![](https://user-images.githubusercontent.com/17433152/35091885-c6d1c6da-fc35-11e7-9484-a3b2b0214032.png)

  
  
**D435 Camera**  
![](https://user-images.githubusercontent.com/17433152/35097826-be6e8898-fc49-11e7-9e2a-41e9b7bc288b.png)

* **High Accuracy Preset**

  High confidence threshold value of depth, lower fill factor.  

**D415 Camera**  
![](https://user-images.githubusercontent.com/17433152/35094329-dc3e70fc-fc3c-11e7-84be-fd220aa9fd27.png)

  
  
**D435 Camera**  
![](https://user-images.githubusercontent.com/17433152/35097726-32fd30ac-fc49-11e7-8840-64b9fabaaf80.png)

* **High Density Preset**

  Higher fill factor which sees more objects.  

**D415 Camera**  
![](https://user-images.githubusercontent.com/17433152/35094430-1eb2217c-fc3d-11e7-8608-9cec38c1ba79.png)

  
  
**D435 Camera**  
![](https://user-images.githubusercontent.com/17433152/35097758-5a9ccd20-fc49-11e7-96a6-7b08deac1ace.png)

* **Medium Density Preset**

  Balance between fill factor and accuracy.  

**D415 Camera**  
![](https://user-images.githubusercontent.com/17433152/35094547-7636f7c4-fc3d-11e7-9558-7a1fa68875bd.png)

  
  
**D435 Camera**  
![](https://user-images.githubusercontent.com/17433152/35097774-6e200f4c-fc49-11e7-8c08-48a6af30d200.png)

* **Hand Gesture Preset**

  Hand tracking and gesture recognition.  

**D415 Camera**  
![](https://user-images.githubusercontent.com/17433152/35094642-c247fdfc-fc3d-11e7-93e5-231e85f73fef.png)

  
  
**D435 Camera**  
![](https://user-images.githubusercontent.com/17433152/35097797-91f03a0a-fc49-11e7-8b30-4701ba9134dc.png)

![](https://user-images.githubusercontent.com/17433152/35097813-ab783496-fc49-11e7-8b73-3ac8ea08d1c1.png)

## Related Discussion

1. Best parameters for **short-range**:
2. [Finding the best acquisition parameters](https://github.com/IntelRealSense/librealsense/issues/1171)
3. [D435 Recommended configuration for near-range \(&lt; 1m\) accuracy](https://github.com/IntelRealSense/librealsense/issues/1021)

