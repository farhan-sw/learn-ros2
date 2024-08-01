## Installation

1. Setup Nav2 Stack
```bash
sudo apt update
sudo apt install ros-humble-navigation2 ros-humble-nav2-bringup ros-humble-turtlebot3*
```

## GENERATE A MAP WITH SLAM
1. Open the Gazebo

Add this following line to the .bashrc file
```bash
. /usr/share/gazebo/setup.sh
export TURTLEBOT3_MODEL=waffle
```
Open the terminal
```bash
ros2 launch turtlebot3_gazebo turtlebot3_world.launch.py 
```
Run using teleop
```bash
ros2 run turtlebot3_teleop teleop_keyboard
```