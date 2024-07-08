# Setup Terminator
sudo apt install terminator -y

# Setup Bash
gedit ~/.bashrc
## Add the following lines
source /opt/ros/humble/setup.bash
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash

## Add the following lines corresponding to the ROS2 workspace
source ~/Documents/Github/learn-ros2/section3/ros2_ws/install/setup.bash


# Build pkg
## All packages
colcon build
## Specific package
colcon build --packages-select my_py_pkg

# Python Node
## Set Executable
chmod +x my_first_node.py

## Run
./my_first_node.py

## Run with ROS2
### Setup bash
source ~/.bashrc

# C++ Node
## Add path to ROS2 Instalaation
"opt/ros/humble/include/**"

## edit CMakeLists.txt