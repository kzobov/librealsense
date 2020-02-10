# Build an Android Application for RealSense SDK

This document describes how to build an Android application to stream Depth data with RealSense cameras.

> Read about Android support [here](android.md).

## Instructions

1. [Root](https://www.wikihow.tech/Root-Android-Phones) your Android device.
2. Install [Android Studio](https://developer.android.com/studio/install.html) IDE for Linux.
3. Open Android Studio.

   ```text
   ./android-studio/bin/studio.sh
   ```

Click on `configure` and choose `SDK Manager`. [Install LLDB, CMake and NDK](https://developer.android.com/ndk/guides/index.html#download-ndk) for Android Studio. Go to section "Download the NDK and Tools" and start with the second step \(2. Click the SDK Tools tab\).

1. Click on `Start a new Android Studio project`.
2. Change the Application Name and the Company Domain to `realsense_app` and `example.com` respectively, tick the checkbox `Include C++ support` and click on the `Next` button.
3. Choose `API 19: Android 4.4 (KitKat)` in the first listbox and click on the `Next` button.
4. Choose `Empty Activity` and click on the `Next` button.
5. Ensure that the `Activity Name` and the `Layout Name` are containing `MainActivity` and `activity_main` respectively and click on the `Next` button.
6. Choose `C++11` at the `C++ Standard` list box, tick the checkbox `Exception Support` and click on the `Next` button.
7. Clone the latest [RealSense™ SDK 2.0](https://github.com/IntelRealSense/librealsense/releases) to your host machine and place the librealsense folder in the Android application folder under `./realsense_app/app/src/main/cpp/`.
8. Replace the content of `MainActivity`, `native-lib.cpp`, `activity_main.xml` and `CMakeLists.txt` with [MainActivity](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/doc/android/MainActivity.java_), [native-lib.cpp](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/doc/android/native-lib.cpp_), [activity\_main.xml](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/doc/android/activity_main.xml_) and [CMakeLists.txt](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/doc/android/CMakeLists.txt_) respectively.
9. Connect the Android device to the host machine. Click on `Run` and choose `Run 'app'`. Choose your Android device and click on the `OK` button. At the end of this process a new application supposed to appear at the Android device.
10. Install [Terminal Emulator](https://en.wikipedia.org/wiki/Terminal_emulator) on your Android device from Google Play Store.
11. Use the USB OTG cable to connect the RealSense camera to your Android device.
12. Open the Terminal Emulator application and type below lines in order to move to Super User mode and change the USB permissions.

    ```text
    su
    lsusb
    chmod 0777 /dev/bus/usb/<Bus number>/<Dev Number>
    ```

13. Open the `realsense_app` application.

## Expected Output

* Streaming Depth data using rooted Samsung Galaxy S4 device.

