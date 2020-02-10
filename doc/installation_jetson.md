# Jetson TX2 Installation

> Check out [www.jetsonhacks.com](http://www.jetsonhacks.com/) for more great content regarding RealSense on the Jetson

**NOTE: Intel does not officially support the Jetson line of devices. Furthermore, there are several** [**known issues**](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/issues?utf8=✓&q=is:issue%20is:open%20jetson/README.md) **with running librealsense on jetson.**  
  
 To install librealsense on the Jetson TX2 Developer Kit, Follow the [regular instructions](installation.md) for Ubuntu 16.04.

A couple things of note: 1. Make sure you are running the [latest L4T release](https://developer.nvidia.com/embedded/linux-tegra) as published by NVIDIA. 2. The `./scripts/patch-realsense-ubuntu-xenial.sh` script will _NOT_ work as is. The following are the minimal changes necessary to make the script run.

* Change [line \#26](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/scripts/patch-realsense-ubuntu-xenial.sh#L26) to `kernel_name="kernel-4.4"`
* Replace [line \#29](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/scripts/patch-realsense-ubuntu-xenial.sh#L29) with: `[ ! -d ${kernel_name} ] && git clone https://github.com/jetsonhacks/buildJetsonTX2Kernel.git && cd buildJetsonTX2Kernel && ./getKernelSources.sh && ./scripts/fixMakeFiles.sh && cd .. && cp /usr/src/kernel/${kernel_name} ./${kernel_name}`
* Comment out [lines \#33-53](https://github.com/kzobov/librealsense/tree/7148f9ae1d78b5d44bee4fc578bf0b8fb9a220c5/scripts/patch-realsense-ubuntu-xenial.sh#L33-L53). This is necessary because the original script grabs the kernel sources from a git repository, which NVIDIA does not provide for L4T, and this segment was written with that assumption in mind.
  1. QtCreator won't work out of the box on the Jetson. JetsonHacks has posted a [helpful tutorial](http://www.jetsonhacks.com/2017/01/31/install-qt-creator-nvidia-jetson-tx1/) explaining how to properly configure it.

