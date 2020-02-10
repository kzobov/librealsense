# API-Changes

## Version [2.32.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.32.1)

* [rs2\_remove\_static\_node](https://github.com/IntelRealSense/librealsense/blob/v2.32.1/include/librealsense2/h/rs_sensor.h#L547) - T265: Remove a named location tag
* [rs2\_create\_huffman\_depth\_decompress\_block](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L566) - Generates a processing block dedicated for decoding `Z16H` compressed depth format.
* [RS2\_FORMAT\_Z16H](https://github.com/IntelRealSense/librealsense/blob/v2.32.1/include/librealsense2/h/rs_sensor.h#L88) - Provision for `Z16H` format. A variable-length compression dedicated for 16-bit depth values using customized Huffman code implementation.
* [RS2\_FRAME\_METADATA\_RAW\_FRAME\_SIZE](https://github.com/IntelRealSense/librealsense/blob/v2.32.1/include/librealsense2/h/rs_frame.h#L63) - Metadata attribute for the size in bytes of the transmitted frame payload \(w/o metadata header\). For non-compressed video streams is equal to Width_Height_BytesPerPixel.
* \[RS2\_EXTENSION\_COLOR\_SENSOR,  

  RS2\_EXTENSION\_MOTION\_SENSOR,  

  RS2\_EXTENSION\_FISHEYE\_SENSOR,  

  RS2\_EXTENSION\_DEPTH\_HUFFMAN\_DECODER\]\([https://github.com/IntelRealSense/librealsense/blob/v2.32.1/include/librealsense2/h/rs\_types.h\#L177-L180](https://github.com/IntelRealSense/librealsense/blob/v2.32.1/include/librealsense2/h/rs_types.h#L177-L180)\) - Extension types used for class instance identification/affiliation.

## Version [2.30.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.30.0)

* [RS2\_NOTIFICATION\_CATEGORY\_POSE\_RELOCALIZATION](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L566) - category added to `rs2_notification_category`. The notification designates T265 performing relocalization event, i.e. finding a match between the current position and a previously recorded map.

## Version [2.29.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.29.0)

Changed enum RS2\_CAMERA\_INFO\_FIRMWARE\_UPDATE\_SERIAL\_NUMBER to [RS2\_CAMERA\_INFO\_FIRMWARE\_UPDATE\_ID](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L35)

## Version [2.27.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.27.0)

* **T265 Calibration Write APIs**: Allow custom calibration to be provided to the device and committed to device flash memory. There is also a mechanism to roll-back to factory calibration. Currently these APIs are only implemented for the T265, but similar scheme is likely to be used for other families
  * [rs2\_set\_intrinsics](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L555) - set video stream profile intrinsic calibration
  * [rs2\_set\_extrinsics](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L566) - set extrinsic calibration between two stream profiles
  * [rs2\_set\_motion\_device\_intrinsics](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L575) - set motion stream profile intrinsics
  * [rs2\_reset\_to\_factory\_calibration](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_device.h#L155) - Resets the device to factory calibration when available
  * [rs2\_write\_calibration](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_device.h#L162) - Commit calibration changes to device flash memory
* [rs2\_clone\_video\_stream\_profile](https://github.com/dorodnic/librealsense/blob/d98ab745c20ffeab9b23dd9ce30abd782c10fff2/include/librealsense2/h/rs_sensor.h#L372) - Utility function used when developing custom processing blocks that modify video stream resolution

## Version [2.26.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.26.0)

Firmware Update with non Digitally-signed images:

* [rs2\_update\_firmware\_unsigned\_cpp](https://github.com/IntelRealSense/librealsense/blob/v2.26.0/include/librealsense2/h/rs_device.h#L206) - Invoke Firmware Update flow using unsigned DFU image.
* [rs2\_update\_firmware\_unsigned](https://github.com/IntelRealSense/librealsense/blob/v2.26.0/include/librealsense2/h/rs_device.h#L220) - Same as above for C-code users
* [rs2\_get\_frame\_data\_size](https://github.com/IntelRealSense/librealsense/blob/v2.26.0/include/librealsense2/h/rs_frame.h#L124) - The actual frame size may differ from the initially-negotiated max size. Required to properly support the compressed data streams, such as MJPEG.
* [RS2\_FORMAT\_MJPEG](https://github.com/IntelRealSense/librealsense/blob/v2.26.0/include/librealsense2/h/rs_sensor.h#L81) - Adding SDK support for MJPEG compressed stream type
* [RS2\_OPTION\_DEPTH\_OFFSET](https://github.com/IntelRealSense/librealsense/blob/v2.26.0/include/librealsense2/h/rs_option.h#L83)- Provides the offset from the sensor to the depth origin for affected camera types.

## Version [2.25.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.25.0)

Introduce [T265-specific](https://github.com/IntelRealSense/librealsense/blob/d19829788008b8e000870895a068f0c43d58895a/doc/t265.md#are-there-any-t265-specific-options) options

* RS2\_OPTION\_ENABLE\_MAPPING - Enable internal mapping generation required for location correction \(feedback\). Turning this option off will result in device running in an open loop.
* RS2\_OPTION\_ENABLE\_RELOCALIZATION - Allow the device ti utilize the internal/stored map to correct the current location based on previously recorded data.
* RS2\_OPTION\_ENABLE\_POSE\_JUMPING - Allow the device to correct the location by making a discontinuous transformation \(jump\) 
* RS2\_OPTION\_ENABLE\_DYNAMIC\_CALIBRATION 

  Read more in the above link

## Version [2.24.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.24.0)

* Firmware Update functionality
* Switch SR300 and D400 camera into DFU \(Firmware Update\) mode [rs2\_enter\_update\_state](https://github.com/IntelRealSense/librealsense/blob/f112ed78e3917df79047254f864157195d4488b0/include/librealsense2/h/rs_device.h#L196).

  When applied, the D400 camera will disconnect from host and reconnect as boot-loader device with a different VID/PID. 

* Perform Firmware Upgrade for D400/SR300 device [rs2\_update\_firmware](https://github.com/IntelRealSense/librealsense/blob/f112ed78e3917df79047254f864157195d4488b0/include/librealsense2/h/rs_device.h#L161-L170). The functionality requires a digitally-signed image to be provided as an input
* Perform Firmware Upgrade for D400/SR300 device, report progress to user-provided callback [rs2\_update\_firmware\_cpp](https://github.com/IntelRealSense/librealsense/blob/f112ed78e3917df79047254f864157195d4488b0/include/librealsense2/h/rs_device.h#L150-L158)
* Generate a firmware image copy [rs2\_create\_flash\_backup](https://github.com/IntelRealSense/librealsense/blob/f112ed78e3917df79047254f864157195d4488b0/include/librealsense2/h/rs_device.h#L182-L189). Note that the generated backup image format is different from the file required in `rs2_update_firmware/rs2_update_firmware_cpp` and cannot be used with these APIs.
* Generate a firmware image copy, report progress to user-provided callback [rs2\_create\_flash\_backup\_cpp](https://github.com/IntelRealSense/librealsense/blob/f112ed78e3917df79047254f864157195d4488b0/include/librealsense2/h/rs_device.h#L173-L179). The limitations are similar to `rs2_create_flash_backup`

## Version [2.23.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.23.0)

* Depth linearity enhancement - Mitigate the half-pixel disparity issue by adjusting the Amplitude factor in the modulation funciton \(\)
* Adding getter/setter for the Half-disparity modulation function control [rs2\_set\_amp\_factor/rs2\_get\_amp\_factor](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/rs_advanced_mode.h#L91-L94) into the Advanced-mode parameters block.
* Adding a new temperature sensor [`RS2_OPTION_APD_TEMPERATURE`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L78) option.
* Enumerating Global Timer-supported sensors with explicit extension type [`RS2_EXTENSION_GLOBAL_TIMER`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_types.h#L170).

## Version [2.22.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.22.0)

* Global Camera Timestamp:
  * Add `rs2_timestamp_domain::RS2_TIMESTAMP_DOMAIN_GLOBAL_TIME` [enumeration type](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_frame.h#L23) that will be used as default when the HW timestamp is available via the appropriate metadata attribute.
  * Add `rs2_sensor* rs2_get_frame_sensor` [function](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_frame.h#L108)
  * Add `RS2_OPTION_GLOBAL_TIME_ENABLED` [option](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L77)
* Depth units transformation - Processing block
  * `rs2_processing_block* rs2_create_units_transform` [function](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L69)
  * Add `rs2_format::RS2_FORMAT_DISTANCE` synthetic stream [format](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L78)
  * Add `units_transform` [class](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/hpp/rs_processing.hpp#L524)
  * Add `rs2_error * rs2_create_error` [functionality](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_types.h#L240)
  * Add `pose_stream_profile` [class](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/hpp/rs_frame.hpp#L284) to handle T265 pose sensor.
  * Add `frame::get_sensor()` [functionality](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/hpp/rs_frame.hpp#L420)
  * Add `sensor_from_frame(frame f)`  [functionality](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/hpp/rs_sensor.hpp#L332)
* GLSL Processing Blocks Module:
  * New header files with new API for GLSL-supported modules are added to [include/librealsense2-gl](https://github.com/IntelRealSense/librealsense/tree/development/include/librealsense2-gl) directory

## Version [2.20.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.20.0) to [2.21.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.21.0)

New IR format introduced to D415 - `W10`:

* Rectified, 10 bit per-pixels \(packed\) IR stream
* FullHD configuration only 30 fps
* Can be configured for use in conjunction with Depth stream \(which is limited to 720p\)
* Available as:
  * parsed 10 bit per pixel [RS2\_FORMAT\_Y10BPACK](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L77)
  * Raw packed data \(4pixel/5bytes\) according to [V4L2-PIX-FMT-Y10BPACK](https://www.linuxtv.org/downloads/v4l-dvb-apis-old/V4L2-PIX-FMT-Y10BPACK.html) specification

## Version [2.19.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.19.0) to [2.20.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.20.0)

New Lens distortion model support added for T265 optical sensors -  
[RS2\_DISTORTION\_KANNALA\_BRANDT4](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_types.h#L51).  
The model is utilized in [Project/Deproject](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/rsutil.h#L84) routines

[rs2\_send\_wheel\_odometry](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L525) - Wheel odometer API velocity type updated from angular to **linear**.

## From version [2.19.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.19.0) to [2.19.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.19.1)

No API changes

## From version [2.18.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.18.0) to [2.19.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.19.0)

### Added

#### Processing blocks/filters:

1. [`rs2_get_recommended_processing_blocks`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L446) Retrieving an ordered list of processing blocks/filters that are recommended to be used for a specific sensor. For instance, for the Depth sensor the list may include \(Decimation-&gt;Disparity-&gt;Spatial-&gt;Temporal-&gt;HoleFilling-&gt;Disparity\`\`\) sequence.
2. [`rs2_get_recommended_processing_blocks_count`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L463) Retrieving the number of elements on the processing blocks list
3. [`rs2_get_processing_block` ](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L455) Extracting a specific processing block from the list
4. [`rs2_delete_recommended_processing_blocks`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L469) Deleting the processing blocks list. The function shall be used in conjunction with `rs2_get_recommended_processing_blocks` mentioned above to explicitly release the allocated resources.
5. [`rs2_supports_processing_block_info`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L254) Test for attribute availbility without throwing exception
6. [`rs2_get_processing_block_info`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L245) Retrieve processing block attribute
7. [`rs2_is_processing_block_extendable_to`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L263) Check API extension support
8. [`rs2_create_zero_order_invalidation_block`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L236) Adding zero order invalidation processing block

#### Options API:

1. [`rs2_get_options_list`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L146) Dynamic discovery of the options supported by a librealsense entity \(sensor/processing\_block/etc\`\).
2. [`rs2_get_options_list_size`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L153) Retrieve the number of elements in the options list.
3. [`rs2_get_option_name`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L162) Return human-readable option's name attribute.
4. [`rs2_get_option_from_list`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L169) Return an indexed element from the lsit
5. [`rs2_delete_options_list`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L175) Deleting the processing blocks list. The function shall be used in conjunction with `rs2_get_options_list` to explicitly release previously allocated resources.
6. Extending RS2\_OPTIONS enumeration list with:  

   [`RS2_OPTION_ZERO_ORDER_POINT_X`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L71),

   [`RS2_OPTION_ZERO_ORDER_POINT_Y`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L72),

   [`RS2_OPTION_LLD_TEMPERATURE`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L73),

   [`RS2_OPTION_MC_TEMPERATURE`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L74), 

   [`RS2_OPTION_MA_TEMPERATURE`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L75)  

#### Device management

1. [`rs2_get_stereo_baseline`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L169) Retrieve Stereo-based Depth sensor baseline
2. [`rs2_context_add_software_device`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_context.h#L64) Inject a software \(mockup\) device into the SDK's context to be discoverable via `query_devices` API call.

#### T265-specific APIs

1. [`rs2_context_unload_tracking_module`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L169) Unload all perviously acquired tracking device instances. A device query for T265 will automatically take ownership of the connected device.

   This new API allows to explicitly release the devices so that they will be available for use by external processes.

2. [`rs2_export_localization_map`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L489) Advanced feature that allows to export the localization map for later reuse.
3. [`rs2_import_localization_map`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L479) Import previously-obtained localization map into device.
4. [`rs2_set_static_node`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L500) Add a positional bookmark \(name&location\) for positional referencing.
5. [`rs2_get_static_node`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L511) Retrieve previously stored bookmark position.
6. [`rs2_load_wheel_odometry_config`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L517) Load the robot platform configuration and calibration data into device. The data includes the rigid body transformation as well as calibration parameters.
7. [`rs2_send_wheel_odometry`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L525) Feed odometer data generated by a third-party sensor into the tracking device.

### To be deprecated

1. `rs2_option_to_string` - For existing options it will return option name, but for future API additions the user should call rs2\_get\_option\_name instead

## From version [2.17.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.17.0) to [2.18.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.18.0)

### Added

1. [`rs2_create_yuy_decoder`](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L54) Adding YUY2 to RGB processing block [\#3056](https://github.com/IntelRealSense/librealsense/pull/3056) :
2. [`rs2_create_error`](https://github.com/IntelRealSense/librealsense/blame/d39b5139ce62efffddee4cd11a87e8927ecdfa0c/src/api.h#L35) Exposing librealsense error to avoid cross-boundary new/delete operations:
3. [`rs2_create_threshold`](https://github.com/IntelRealSense/librealsense/blob/d39b5139ce62efffddee4cd11a87e8927ecdfa0c/include/librealsense2/h/rs_processing.h#L62) Adding depth min/max clamp filter \(processing block\):
4. [`RS2_OPTION_EMITTER_ON_OFF`](https://github.com/IntelRealSense/librealsense/pull/2829) - adding `RS2_OPTION_EMITTER_ON_OFF` to options enumeration
5. [`rs2_processing_block_register_simple_option`](https://github.com/IntelRealSense/librealsense/pull/2830/files#diff-c47ed929a30eaaa0bfce02ecdcfa2701R64) - adding ability to register custom processing block options
6. Adding [`save_to_ply`](https://github.com/IntelRealSense/librealsense/pull/2830/files#diff-883f598ceaa739d7473cdc28d7995e23R17) and [`save_single_frameset`](https://github.com/IntelRealSense/librealsense/pull/2830/files#diff-883f598ceaa739d7473cdc28d7995e23R161) processing blocks to C++ headers only \(staging to be added to the API\) under [rs\_export.hpp](https://github.com/IntelRealSense/librealsense/blob/master/include/librealsense2/hpp/rs_export.hpp).

### Removed

1. [set\_devices\_changed\_callback](https://github.com/IntelRealSense/librealsense/pull/2823) - was removed from C++ header files

## From version [2.16.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.16.0) to [2.17.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.17.0)

### Added

* [\#2773](https://github.com/IntelRealSense/librealsense/pull/2773) introduced asynchronous pipeline API \(recommended for high frequency data such as IMU\). This change is limited to adding new overloads to `pipeline.start` method:
* [rs2\_pipeline\_start\_with\_callback](https://github.com/matkatz/librealsense/blob/a2406a5c7713bb9de5cd0b28e8558e85a63a19b1/include/librealsense2/h/rs_pipeline.h#L147) - pipeline start with C function pointer and user data, similar to `sensor.start`
* [rs2\_pipeline\_start\_with\_callback\_cpp](https://github.com/matkatz/librealsense/blob/a2406a5c7713bb9de5cd0b28e8558e85a63a19b1/include/librealsense2/h/rs_pipeline.h#L160) - pipeline start with C++ frame callback object, similar to `sensor.start`
* [rs2\_pipeline\_start\_with\_config\_and\_callback](https://github.com/matkatz/librealsense/blob/a2406a5c7713bb9de5cd0b28e8558e85a63a19b1/include/librealsense2/h/rs_pipeline.h#L180) - pipeline start with callback and config
* [rs2\_pipeline\_start\_with\_config\_and\_callback\_cpp](https://github.com/matkatz/librealsense/blob/a2406a5c7713bb9de5cd0b28e8558e85a63a19b1/include/librealsense2/h/rs_pipeline.h#L199) - pipeline start with callback and config \(C++ frame callback object\)
* [\#2687](https://github.com/IntelRealSense/librealsense/pull/2687) introduces new API to control recording compression:
* [rs2\_create\_record\_device\_ex](https://github.com/belkinirena/librealsense/blob/9d8d3a690ebd5fd4b60c3d3c73a6e11e901f14bc/include/librealsense2/h/rs_record_playback.h#L49) - create recorder and explicitly enable or disable compression. By default, compression will be enabled based on device type. D435i and T265 devices that provide high FPS streams disable compression by default to avoid frame drops during recording.
* [\#2673](https://github.com/IntelRealSense/librealsense/pull/2673) adds API to generate IMU and pose data with `software_device`:

Added support for IMU stream and recording IMU frames in software sensor:

* stream\_profile **add\_motion\_stream**\(rs2\_motion\_stream motion\_stream\)
* rs2\_stream\_profile _**rs2\_software\_sensor\_add\_motion\_stream**\(rs2\_sensor_ sensor, rs2\_motion\_stream motion\_stream, rs2\_error\*\* error\);
* void **on\_motion\_frame**\(rs2\_software\_motion\_frame frame\)
* void **rs2\_software\_sensor\_on\_motion\_frame**\(rs2\_sensor _sensor, rs2\_software\_motion\_frame frame, rs2\_error\*_ error\);

Added support for pose stream and recording pose frames in software sensor:

* stream\_profile **add\_pose\_stream**\(rs2\_pose\_stream pose\_stream\)
* rs2\_stream\_profile _**rs2\_software\_sensor\_add\_pose\_stream**\(rs2\_sensor_ sensor, rs2\_pose\_stream pose\_stream, rs2\_error\*\* error\);
* void **on\_pose\_frame**\(rs2\_software\_pose\_frame frame\)
* void **rs2\_software\_sensor\_on\_pose\_frame**\(rs2\_sensor _sensor, rs2\_software\_pose\_frame frame, rs2\_error\*_ error\);

### Renamed

* [\#2757](https://github.com/IntelRealSense/librealsense/pull/2757) is splitting C++ `processing_block` class into `processing_block` and `filter` classes, with `filter` being derived from `processing_block`.

  `processing_block` abstraction offers `start` and `invoke` operations and does not guaranty results will be immediately available \(`processing_block` can chose to **delay** frames\). `filter` is special type of processing block that performs its operation immediately. This lets users compose filters using `apply_filter` operation. 

## From version [2.15.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.15.0) to [2.16.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.16.0)

### Added

* [rs2\_project\_color\_pixel\_to\_depth\_pixel](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/rsutil.h#L117) - map pixel in the color image to pixel in depth image
* [rs2\_allocate\_points](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_frame.h#L288) - allows the user to write custom processing block that outputs frame of type points
* [frame::apply\_filter](https://github.com/IntelRealSense/librealsense/blob/v2.16.0/include/librealsense2/hpp/rs_frame.hpp#L509) - this method allows unified application of processing blocks, regardless of processing or frame type. This allows easy composition of processing blocks.

### Removed

* [`processing_block::operator()(frame f) const`](https://github.com/IntelRealSense/librealsense/blob/v2.15.0/include/librealsense2/hpp/rs_processing.hpp#L151) was removed to reduce the overall ways processing block can be invoked. All processing blocks still contain `invoke` method for async processing \(that sends the results to callback\), and can be applied using added `apply_filter` method, in addition to helper methods like `colorize` and `calculate` specific to each block.

## From version [2.14.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.14.0) to [2.15.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.15.0)

### Added

* [rs2\_query\_devices\_ex](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_context.h#L87) - provide a list of connected devices with user-specified mask. This allows to cherry-pick specific types \(e.g D400/SR300\) during device acquisition stage. 

## Version [2.14.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.14.0) vs [2.13.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.13.1)

### Added

* [rs2\_try\_wait\_for\_frame](https://github.com/IntelRealSense/librealsense/blob/master/include/librealsense2/h/rs_processing.h#L143), [rs2\_pipeline\_try\_wait\_for\_frames](https://github.com/IntelRealSense/librealsense/blob/master/include/librealsense2/h/rs_pipeline.h#L91) - wait\_for\_frames overload that does not throw an exception on timeout
* [was\_added](https://github.com/BrendanDrew/librealsense/blob/12b42d3eb8d6cd44167134737d96d1b06ea0e8eb/include/librealsense2/hpp/rs_context.hpp#L40) and [get\_new\_devices](https://github.com/BrendanDrew/librealsense/blob/12b42d3eb8d6cd44167134737d96d1b06ea0e8eb/include/librealsense2/hpp/rs_context.hpp#L57) methods added to [event\_information](https://github.com/BrendanDrew/librealsense/blob/12b42d3eb8d6cd44167134737d96d1b06ea0e8eb/include/librealsense2/hpp/rs_context.hpp#L13) C++ class

## Version [2.13.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.13.0) \(vs [2.11.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.11.1)\)

### Added

* [rs2\_option::RS2\_OPTION\_INTER\_CAM\_SYNC\_MODE](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_option.h#L66) - Master/Slave control for multi-cam setup synchronization.
* [rs2\_frame\_metadata\_value](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_frame.h#L42-L59) - Extending available attributes:
  * Depth Sensor:
    * Laser Power, Laser Power Mode, Exposure Priority, Exposure ROI.
  * RGB Sensor:
    * Brightness, Contrast, Saturation, Sharpness, Backlight\_Compensation, Hue, Gamma, White\_Balance\_Mode & Temperature, Powerline Frequency and Low Light Compensation.

## From [2.11.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.11.0) to [2.11.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.11.1)

### Modified

* [rs2\_camera\_info::RS2\_CAMERA\_INFO\_RECOMMENDED\_FIRMWARE\_VERSION](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_sensor.h#L26) - Field was moved next to RS2\_CAMERA\_INFO\_FIRMWARE\_VERSION.

## From [2.10.4](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.4) to [2.11.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.11.0)

### Added

* [rs2\_create\_processing\_block\_fptr](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L61) - Allows to create custom processing blocks using C-bindings \(C, LabView, .NET\)
* [rs2\_start\_processing\_fptr](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L78) - Allows to start a processing block with a callback
* [rs2\_config\_enable\_device\_from\_file\_repeat\_option](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_pipeline.h#L259) - Allows to configure pipeline to play from recording while controlling playback-repeat behavior 
* [rs2\_create\_hole\_filling\_filter\_block](https://github.com/IntelRealSense/librealsense/blob/development/include/librealsense2/h/rs_processing.h#L177) - Hole-Filling filter supports three modes of operation:
  * Fill from left - fill the hole by the value from an immediate left neighbor
  * Fill from Far - select one of the up/down/left/right pixel neighbors farthest away from the camera
  * Fill from Near - select one of the up/down/left/right neighbors closest to the camera.  

    It is recommended to use this post-processing block last in the filters chain.

    The functionality is integrated and can be reviewed in realsense-viewer/post-processing section

## From [2.10.3](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.3) to [2.10.4](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.4)

No API changes

## From [2.10.2](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.2) to [2.10.3](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.3)

### Modified

Adding `RS2_CAMERA_INFO_USB_TYPE_DESCRIPTOR` enumeration to detect USB2 vs USB3 mode \(when supported by the firmware\).

## From [2.10.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.1) to [2.10.2](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.2)

### Modified

Adding `RS2_OPTION_AUTO_EXPOSURE_CONVERGE_STEP` enumeration to control the FishEye Auto-Exposure algorithm The option is available for TM1-enabled devices only.

## From [2.10.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.0) to [2.10.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.1)

No API changes

## From [2.9.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.9.1) to [2.10.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.10.0)

### Added

* [rs2::frameset::get\_infrared\_frame\(\)](https://github.com/IntelRealSense/librealsense/blob/master/include/librealsense2/hpp/rs_frame.hpp#L691) - Simpler way for users to get infrared frames from a `rs2::frameset`

### Changed

* Fixed [`rs2_set_devices_changed_callback`](https://github.com/IntelRealSense/librealsense/blob/master/include/librealsense2/h/rs_context.h#L42) - missing `const` specifier and `void** user` parameter were added.
* Change the 'Holes Filling' control for Temporal Post-Processing filter to be activated with `RS2_OPTION_HOLES_FILL` instead of `RS2_OPTION_FILTER_MAGNITUDE`

## From [2.9.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.9.0) to [2.9.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.9.1)

### Added

* [rs2\_keep\_frame](https://github.com/IntelRealSense/librealsense/blob/master/include/librealsense2/hpp/rs_frame.hpp#L269) - this function can be used to preserve specific frame for longer processing. Calling it signals the intention to not return this frame to the pool within next 100ms. 

## From [2.8.3](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.3) to [2.9.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.9.0)

### Added

* [rs2\_create\_disparity\_transform\_block](https://github.com/IntelRealSense/librealsense/blob/v2.9.0/include/librealsense2/h/rs_processing.h#L152) A depth data conversion class that transforms depth data info/from disparity domain for stereo-based depth sensors \(D400 series\). This functionality allows to run post-processing filters in disparity domain to enhance the filtered outcome.
* [rs2\_depth\_stereo\_frame\_get\_baseline](https://github.com/IntelRealSense/librealsense/blob/v2.9.0/include/librealsense2/h/rs_sensor.h#L158) Retrieve the stereoscopic baseline in mm for stereo-based depth camera.
* [rs2\_export\_to\_ply](https://github.com/IntelRealSense/librealsense/blob/v2.9.0/include/librealsense2/h/rs_frame.h#L171) Making the export functionality publicly available, also addressing [\#862](https://github.com/IntelRealSense/librealsense/issues/862)

## From [2.8.2](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.2) to [2.8.3](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.3)

### Added

* [rs2\_log](https://github.com/IntelRealSense/librealsense/blob/v2.8.3/include/librealsense2/rs.h#L80) - Usability function that allows the user to add logs to librealsense internal logger. The feature is useful in debugging and profiling scenarios.

Post-processing depth filters:

* [rs2\_create\_decimation\_filter\_block](https://github.com/IntelRealSense/librealsense/blob/v2.8.3/include/librealsense2/h/rs_processing.h#L133) - Down-sampling filter that effectively reduces the depth map resolution.
* [rs2\_create\_spatial\_filter\_block](https://github.com/IntelRealSense/librealsense/blob/v2.8.3/include/librealsense2/h/rs_processing.h#L145) - Spatial edge-preserving depth filter.
* [rs2\_create\_temporal\_filter\_block](https://github.com/IntelRealSense/librealsense/blob/v2.8.3/include/librealsense2/h/rs_processing.h#L139) - Temporal filter that rectifies depth values based on previously-available frames.

The filters have been integrated into the **realsense-viewer** and **depth-quality** tools.

## From [2.8.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.1) to [2.8.2](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.2)

No API changes introduced

## From [2.8.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.0) to [2.8.1](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.1)

### Added

* [rs2\_start\_processing\_queue](https://github.com/IntelRealSense/librealsense/tree/v2.8.1/include/librealsense2/h/rs_processing.h#L67) - convenience function that lets the user target the output of a processing block \(for example **align**\) directly into a **frame\_queue**. This helps in languages where function pointers are not available, such as LabView 

> Signature of **rs2\_is\_option\_read\_only**, **rs2\_get\_option**, **rs2\_set\_option**, **rs2\_supports\_option**, **rs2\_get\_option\_description** and **rs2\_get\_option\_value\_description** was changed. First parameter used to be pointer to **rs2\_sensor** and now is pointer to **rs2\_options**. However, it is 100% safe to cast pointer to **rs2\_sensor** to pointer to **rs2\_options**.

## From [2.7.9](https://github.com/IntelRealSense/librealsense/releases/tag/v2.7.9) to [2.8.0](https://github.com/IntelRealSense/librealsense/releases/tag/v2.8.0)

### Moved

> See [Pipeline Changes](https://github.com/IntelRealSense/librealsense/pull/672) pull-request for explanation
>
> * [rs2\_stop\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L64)
>
>   is now available as [rs2\_pipeline\_stop](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L40)
>
> * [rs2\_start\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L40)
>
>   is now available as [rs2\_pipeline\_start](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L94)
>
> * [rs2\_pipeline\_get\_device](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L33)
>
>   is now available as [rs2\_pipeline\_profile\_get\_device](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L142)
>
> * [rs2\_pipeline\_get\_active\_streams](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L112)
>
>   is now available as [rs2\_pipeline\_profile\_get\_streams](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L151)
>
> * [rs2\_enable\_pipeline\_stream](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L75)
>
>   is now available as [rs2\_config\_enable\_stream](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L201)
>
> * [rs2\_enable\_pipeline\_device](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L77)
>
>   is now available as [rs2\_config\_enable\_device](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L231)
>
> * [rs2\_disable\_stream\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L82)
>
>   is now available as [rs2\_config\_disable\_stream](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L265)
>
> * [rs2\_disable\_all\_streams\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L87)
>
>   is now available as [rs2\_config\_disable\_all\_streams](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L287)

### Added

* [rs2\_pipeline\_start\_with\_config](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L115)
* [rs2\_pipeline\_get\_active\_profile](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L127)
* [rs2\_delete\_pipeline\_profile](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L158)
* [rs2\_create\_config](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L171)
* [rs2\_delete\_config](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L178)
* [rs2\_config\_enable\_all\_stream](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L219)
* [rs2\_config\_enable\_device\_from\_file](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L243)
* [rs2\_config\_enable\_record\_to\_file](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L253)
* [rs2\_config\_resolve](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L307)
* [rs2\_config\_can\_resolve](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L318)
* [rs2\_config\_disable\_indexed\_stream](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L277)

### Removed

* [rs2\_get\_stream\_profile\_size](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_sensor.h#L357) - This function was intended to offer an estimate of USB bandwidth, however USB3 performance is affect by factors other then bytes/second, rendering this method useless
* [rs2\_open\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L42) - This function was offered to force pipeline configuration prior to streaming. This can be more effectively achieved by [rs2\_config\_resolve](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L307) and [rs2\_config\_can\_resolve](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L318) 
* [rs2\_start\_pipeline\_with\_callback](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L49) -

  and [rs2\_start\_pipeline\_with\_callback\_cpp](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L57) - Pipeline is always performing synchronization at the moment. If you wish to get minimum latency you can use callback API of the individual sensors

* [rs2\_pipeline\_get\_selection\_count](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L120), [rs2\_pipeline\_get\_stream\_selection](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L129),  [rs2\_pipeline\_get\_stream\_type\_selection](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L139),  [rs2\_pipeline\_delete\_selection](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L145) - These methods were redundant

## From [2.7.7](https://github.com/IntelRealSense/librealsense/releases/tag/v2.7.7) to [2.7.9](https://github.com/IntelRealSense/librealsense/releases/tag/v2.7.9)

### Moved

* [rs2\_get\_context\_time](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_context.h#L38)

  is now available as [rs2\_get\_time](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/rs.h#L82)

* [rs2\_create\_pipeline\_with\_device](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_pipeline.h#L32)

  is now available as [rs2\_enable\_pipeline\_device](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L77)

* [rs2\_enable\_stream\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_pipeline.h#L82)

  is now available as [rs2\_enable\_pipeline\_stream](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L75)

* [rs2\_pipeline\_get\_selection](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_pipeline.h#L141)

  is now available as [rs2\_pipeline\_get\_active\_streams](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L112)

### Added

* [rs2\_playback\_device\_stop](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_record_playback.h#L168)
* [rs2\_start\_queue](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_sensor.h#L223)
* [rs2\_open\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_pipeline.h#L42)

### Removed

* [rs2\_can\_enable\_stream\_pipeline](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_pipeline.h#L95) - This method, while useful, was not 100% clearly defined. The same goal was more cleanly achieved in a later release - [rs2\_config\_can\_resolve](https://github.com/IntelRealSense/librealsense/tree/v2.8.0/include/librealsense2/h/rs_pipeline.h#L318)
* [rs2\_pipeline\_get\_extrinsics](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_pipeline.h#L133) - Extrinsics can be queried between stream profiles, and don't require the pipeline or context.
* [rs2\_pipeline\_get\_context](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_pipeline.h#L176) - Context can be passed to pipeline constructor for dependency injection, but should not be required for anything useful later on.

### Signature Changed

* [rs2\_create\_pointcloud](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_processing.h#L41) used to accept 2 parameters but

  [rs2\_create\_pointcloud](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_processing.h#L41) accepts 1 parameters!

* [rs2\_create\_processing\_block](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_processing.h#L51) used to accept 3 parameters but

  [rs2\_create\_processing\_block](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_processing.h#L51) accepts 2 parameters!

* [rs2\_create\_align](https://github.com/IntelRealSense/librealsense/tree/v2.7.7/include/librealsense2/h/rs_processing.h#L118) used to accept 3 parameters but

  [rs2\_create\_align](https://github.com/IntelRealSense/librealsense/tree/v2.7.9/include/librealsense2/h/rs_processing.h#L118) accepts 2 parameters!

