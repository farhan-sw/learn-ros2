

# ROS2 Setup and Development Guide

## Table of Contents
1. [Setup](#setup)
   - [Setup Terminator](#setup-terminator)
   - [Setup Python](#setup-python)
   - [Setup Bash](#setup-bash)
2. [Create Workspace](#create-workspace)
3. [Build Package](#build-package)
   - [All Packages](#all-packages)
   - [Specific Package](#specific-package)
   - [Symlink (Only for Python)](#symlink-only-for-python)
4. [Python Node](#python-node)
   - [Set Executable](#set-executable)
   - [Run](#run)
   - [Run with ROS2](#run-with-ros2)
   - [Create Node in Python](#create-node-in-python)
5. [C++ Node](#c-node)
   - [Add Path to ROS2 Installation](#add-path-to-ros2-installation)
   - [Edit CMakeLists.txt](#edit-cmakelists-txt)
   - [Create Node in C++](#create-node-in-c)
6. [ROS 2 Command Line Tools](#ros-2-command-line-tools)
7. [Colcon](#colcon)
   - [Add Bash Auto Completion](#add-bash-auto-completion)
   - [Setup Symlink](#setup-symlink)
   - [Make Executable File](#make-executable-file)
8. [RQT and rqt_graph](#rqt-and-rqt_graph)
9. [TurtleSim](#turtlesim)
10. [Intro](#intro)
11. [Topics](#topics)



## Setup ([back](#table-of-contents))

### Setup Terminator
```bash
sudo apt install terminator -y
```

### Setup Python
```bash
pip install setuptools==58.2.0
```

### Setup Bash
```bash
gedit ~/.bashrc
```

Add the following lines:
```bash
source /opt/ros/humble/setup.bash
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
source ~/Documents/Github/learn-ros2/section3/ros2_ws/install/setup.bash
```

## Create Workspace ([back](#table-of-contents))
Make a folder:
```bash
mkdir -p ~/Documents/Github/learn-ros2/section3/ros2_ws/src
```

Build with colcon (run in the workspace folder, e.g. `~/Documents/Github/learn-ros2/section3/ros2_ws`):
```bash
colcon build
```

Add the setup.bash to the bashrc in `ros2_ws/install/setup.bash`:
```bash
gedit ~/.bashrc
```

Add the following line:
```bash
source ~/Documents/Github/learn-ros2/section3/ros2_ws/install/setup.bash
```

## Build Package ([back](#table-of-contents))

### All Packages
```bash
colcon build
```

### Specific Package
```bash
colcon build --packages-select my_py_pkg
```

### Symlink (Only for Python)
Allowing to run the node without rebuilding the package:
```bash
colcon build --packages-select my_py_pkg --symlink-install
```

## Python Node ([back](#table-of-contents))

### Set Executable
```bash
chmod +x my_first_node.py
```

### Run
```bash
./my_first_node.py
```

### Run with ROS2

#### Setup bash
```bash
source ~/.bashrc
```

## Create Node in Python

### Create a New Package
```bash
ros2 pkg create --build-type ament_python my_py_pkg
```

### Create a New Node
```bash
touch my_py_pkg/my_py_pkg/my_first_node.py
```

### Make the Node Executable
```bash
chmod +x my_py_pkg/my_py_pkg/my_first_node.py
```

### Setup the Node in setup.py
```python
'console_scripts': [
    "py_node = my_py_pkg.my_first_node:main",
    "robot_news_station = my_py_pkg.robot_news_station:main"
],
```

### Have a Dependency?
Go to package.xml and add the dependency:
```xml
<depend>rclpy</depend>
<depend>example_interfaces</depend>
```

### Build the Package with Symlink
```bash
colcon build --packages-select my_py_pkg --symlink-install
```

## C++ Node ([back](#table-of-contents))

### Add Path to ROS2 Installation
```bash
"opt/ros/humble/include/**"
```

### Edit CMakeLists.txt

## Create Node in C++

### Create a New Package
```bash
ros2 pkg create --build-type ament_cmake my_cpp_pkg
```

### Create a New Node
```bash
touch my_cpp_pkg/src/my_first_node.cpp
```

### Have a Dependency?
Go to package.xml and add the dependency:
```xml
<depend>rclcpp</depend>
<depend>example_interfaces</depend>
```

Go to CMakeLists.txt and add the dependency:
```cmake
find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)
```

### Create a New Executable
```cmake
add_executable(robot_news_station src/robot_news_station.cpp)
ament_target_dependencies(robot_news_station rclcpp example_interfaces)
```

### Install the Executable
```cmake
install(TARGETS
  cpp_node
  robot_news_station
  DESTINATION lib/${PROJECT_NAME}
)
```

## ROS 2 Command Line Tools ([back](#table-of-contents))

### Run Package
```bash
ros2 run <package_name> <executable_name>
```

### See Running Nodes
```bash
ros2 node list
```

### See Node Info
```bash
ros2 node info /<node_name>
```

### Rename Node in Runtime with CLI
```bash
ros2 run <package_name> <executable_name> --ros-args -r __node:=<new_node_name>
```

## Colcon ([back](#table-of-contents))

### Add Bash Auto Completion
To add bash auto completion for colcon, add the following line to your .bashrc file:
```bash
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
```

### Setup Symlink
Used to avoid rebuilding the package every time we make a change. Only works for python packages.
```bash
colcon build --packages-select <package_name> --symlink-install
```

### Make Executable File
```bash
chmod +x <file_name>
```

Example:
```bash
chmod +x src/<package_name>/scripts/<file_name>.py
```

## RQT and rqt_graph

### Open rqt
```bash
rqt
```  

### Open rqt_graph
```bash
rqt_graph
```

## TurtleSim
Simulation of a turtle that can move in a 2D plane.

### Install TurtleSim
```bash
sudo apt-get install ros-humble-turtlesim
```

## Topics

### View Example MSG Type
```bash
ros2 interface show example_interfaces/msg/String
```

### View Topic List
```bash
ros2 topic list
```

### View Topic Info
```bash
ros2 topic info /<topic_name>
```

### Echo Topic
To see the messages being published to a topic, you can use the following command:
```bash
ros2 topic echo /<topic_name>
``` 