# Windows 8.1 & Windows 10 Installation

**Note:** Due to the USB 3.0 translation layer between native hardware and virtual machine, the librealsense team does not recommend or support installation in a VM.

librealsense shall be built on Windows using [CMake v3.8+](https://cmake.org/download/) and Visual Studio 2015 / 2017:  
\(MSVC2013 and older are not fully compatible with the C++11 feature-set\).  [![Windows CMake](../.gitbook/assets/windows_cmake.png)](installation_windows.md) !\[link text\]\[Win\_cmake\_image\]

Don't forget to check `BUILD_EXAMPLES` if you wish to use librealsense samples.

## Windows 8.1:

When working on Windows 8.1, make sure you have [KB3075872](https://support.microsoft.com/en-us/kb/3075872) and [KB2919355](https://support.microsoft.com/en-us/kb/2919355) installed. These patches are addressing issues specific to 8.1 video drivers, that were later resolved in Windows 10.

## Enabling metadata on Windows

Metadata attributes is an advanced capability provided by librealsense. Read more on this feature in [link](frame_metadata.md).  
Follow the instructions to enable metadata generation:

Prerequisites:

* Windows 10 with administrator login.
* WinSDK ver 10 \(10.0.15063\) or later.

### Installation:

* Verify OS version:
  * Run `winver` command from desktop/terminal - "Version 1607" or later is expected.  

    ![winver](../.gitbook/assets/winver_win10.png)
* Install WinSDK ver10:

  * Navigate to "Control Panel" -&gt; "Programs and Features"
  * Double-click on "Microsoft Visual Studio" and select "Modify"
  * Check that SDK version 10.0.10586 or later is present, install if needed:

    ![winsdk](../.gitbook/assets/winsdk_10.0.10586.png)

  **Update Registry:**

  * Windows OS requires a dedicated registry entry to be present for each unique video device in order to provide metadata.  

  **Use automation script:**

  * Launch Windows `Powershell` tool as _Admin_ and navigate to the script directory
  * Run the following: `PS > .\realsense_metadata_win10.ps1 <optional:operation>` The supported parameters are
    * `-op install` adds registry keys for connected Intel Realsense devices
    * `-op install_all` adds keys for all RealSense devices logged in the registry
    * `-op remove` removes registry keys for connected Intel Realsense devices
    * `-op remove_all` removes the keys for all RealSense devices logged in the registry

      Running the script without arguments will is similar to `-op install` operation.  
  * If you receive `... cannot be loaded because running scripts is disabled on this system` message, run:

    `PS > Set-ExecutionPolicy RemoteSigned` , answer `Y` and then rerun the script

    **Important** - The registry keys are device-unique. Therefore, _**the script must be executed each time a new RealSense device is attached**_ to the PC.

**Modifying the registry manually**

In case the script cannot be executed due to permissions, or other Host-related issue please follow the instructions to update the registry manually:

* Connect Intel® RealSense™ device to the host
* Navigate to "Control Panel" -&gt; "Device Manager"
* Browse for Intel® RealSense™ devices
* Select the first device from the list, e.g. `Intel® RealSense™ Camera SR300 Depth` \(Step 1\)
* Find device's path \(Step 2\) and the additional interfaces \(Step 3\)

  ![win\_dev\_master\_interface](../.gitbook/assets/win_device_interface.png) ![win\_dev\_master\_interface](../.gitbook/assets/win_device_sibling_interfaces.png)

* Modifying the Windows Registry:
  * For each interface found \(Steps 2 and 3\) perform
    * Using Registry Editing tool such as "regedit" navigate to    `HKLM\SYSTEM\CurrentControlSet\Control\DeviceClasses\{e5323777-f976-4f5b-9b55-b94699c46e44}` branch.
    * Browse into the subdirectory with the name identical to the `Device instance path` obtained from the previous step
      * Expand the entry into `#GLOBAL` -&gt; `Device Parameters`
      * Add `DWORD 32bit` value named `MetadataBufferSizeInKB0` with value 5.
      * Add an additional `DWORD 32bit` value named `MetadataBufferSizeInKB1` with value 5 for RS400 device zero interface `##?##USB#VID_8086&PID... **MI_00**..`

        ![win\_md\_reg\_key](../.gitbook/assets/win_md_reg_key.png)  
    * Repeat the previous step for `HKLM\SYSTEM\CurrentControlSet\Control\DeviceClasses\{65E8773D-8F56-11D0-A3B9-00A0C9223196}` branch
* Repeat the procedure for all the additional RealSense devices \(e.g. `Intel® RealSense™ Camera SR300 RGB`\)

### Compiling Librealsense with Metadata support:

During compilation the library will automatically detect and enable/disable metadata functionality according to the WinSDK version selected. In case the installed WinSDK doesn't expose metadata the user will be notified that the build does not include metadata generation:  
`Librealsense notification: Featuring UVC Metadata requires WinSDK 10.0.10586.0 toolset.    
The library will be compiled without the metadata support!`

In order to ensure compilation with metadata support check the `ENFORCE_METADATA` in the [Cmake configuration stage](installation_windows.md#cmake_snapshot_win). When set, the compiler will check the target WinSDK version, and abort the build if it is not compatible with metadata requirements.

**Note** In case of multiple WinSDK version installed, CMake automatically selects the latest version of SDK. In some cases, however, the automatic selection may fail. Then you need to manually retarget the solution for the proper WinSDK version:  
![win\_retarget\_platform](../.gitbook/assets/win_retarget_platform.png)

