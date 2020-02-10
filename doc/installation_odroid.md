# Odroid 4.14 Installation

NOTE: Intel does not officially support the Odroid line of devices. Furthermore, there are several known known [issues](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/issues?utf8=✓&q=is:issue%20is:open%20odroid/README.md) with running librealsense on Odroid.

To install librealsense on the Odroid, use the 4.14 image and follow the [regular instructions](installation.md) for Ubuntu 16.04 with the following exceptions: 1. Run `patch-realsense-odroid.sh` instead of `patch-realsense-lts.sh` 2. After `sudo udevadm control --reload-rules && udevadm trigger` do `sudo modprobe uvcvideo`

