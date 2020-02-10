# rs-convert Tool

## Goal

Console app for converting ROS-bag files to various formats \(currently supported: PNG, RAW, CSV, PLY, BIN\)

## Command Line Parameters

| Flag | Description | Default |
| :--- | :--- | :--- |
| `-i <ros-bag-file>` | ROS-bag filename |  |
| `-p <png-path>` | convert to PNG, set output path to  |  |
| `-v <csv-path>` | convert to CSV \(depth matrix\), set output path to  |  |
| `-r <raw-path>` | convert to RAW, set output path to  |  |
| `-l <ply-path>` | convert to PLY, set output path to  |  |
| `-b <bin-path>` | convert to BIN \(depth matrix\), set output path to  |  |
| `-d` | convert depth frames only |  |
| `-c` | convert color frames only |  |

## Usage

Several converters can be used simultaneously, e.g.: `rs-convert -i some.bag -p some_dir/some_file_prefix -r some_another_dir/some_another_file_prefix`

