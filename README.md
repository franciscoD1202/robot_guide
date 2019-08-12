# robot_guide

This ROS repository allows the creation of a map via teleoperation and autonomous driving for a Pioneer P3DX robot, it was tested in the S1 level of Mario Laserna Building in the University of Los Andes.

# Setup

You must have ROS Kinetic installed and the RosAria package, available on Ubuntu 16.04. 

In case of not finding the [**libraria**](libaria_2.9.4+ubuntu16_amd64.deb) installer, it is available in this repository.

## Installing

If you haven't done so, create and build a catkin workspace:

```shell
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```


# Build

Clone this project into the `~/catkin_ws/src` folder. Then, build the package by running

```shell
cd ~/catkin_ws
catkin_make
```

Make sure you run the commands `source /opt/ros/kinetic/setup.bash` and `source ~/catkin_ws/devel/setup.bash` on every new shell to have access to the ROS environment and to this package (you can add this commands to the `.bashrc` file for convinience).


# Execution

Launch the whole program by locating and running the file robot_control_sim.sh:

```shell
. \robot_control_sim.sh
```
This file starts the ros enviroment and starts a ROS core service. Make sure that the line _source /home/XXX//catkin_ws/devel/setup.bash_ the XXX matches the name of your device. By default is set as:

```cpp
source /home/francisco/catkin_ws/devel/setup.bash
```
