
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
12. [Make a Custom Msg and Srv](#make-a-custom-msg-and-srv)
      - [Custom Msg](#custom-msg)

---

## Setup ([back to top](#table-of-contents))

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

## Create Workspace ([back to top](#table-of-contents))
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

## Build Package ([back to top](#table-of-contents))

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

## Python Node ([back to top](#table-of-contents))

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
Make sure you are in /src folder:
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

## C++ Node ([back to top](#table-of-contents))

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

#### Template
```cmake
cmake_minimum_required(VERSION 3.8)
project(my_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(example_interfaces REQUIRED)

# Make an executable
add_executable(add_two_ints_server src/add_two_ints_server.cpp)
ament_target_dependencies(add_two_ints_server rclcpp example_interfaces)

# Install the executable
install(TARGETS
  add_two_ints_server
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()

```

### Install the Executable
```cmake
install(TARGETS
  cpp_node
  robot_news_station
  DESTINATION lib/${PROJECT_NAME}
)
```

## ROS 2 Command Line Tools ([back to top](#table-of-contents))

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

## Colcon ([back to top](#table-of-contents))

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

## RQT and rqt_graph ([back to top](#table-of-contents))

### Open rqt
```bash
rqt
```  

### Open rqt_graph
```bash
rqt_graph
```

## TurtleSim ([back to top](#table-of-contents))
Simulation of a turtle that can move in a 2D plane.

### Install TurtleSim
```bash
sudo apt-get install ros-humble-turtlesim
```

## Intro ([back to top](#table-of-contents))
It is now the time to explore ROS communication features. At the end of this section you will be able to make your nodes communicate between each other, using ROS2 Topics.

Here’s what you’ll do in this section:
- Understand what is a ROS2 topic thanks to a real-life analogy
- Write your own Topic (publisher/subscriber) in both Python and Cpp
- Debug topics with ROS2 tools
- Experiment on Turtlesim

And finally, you’ll work on an activity to practice on everything you’ve seen until this point.

## Topics ([back to top](#table-of-contents))

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


# Make a Custom Msg and Srv
[back to top](#table-of-contents)

## Custom Msg
create a new package:
```bash
ros2 pkg create my_robot_interfaces
```

Delete the include and src folders
```bash
rm -r my_robot_interfaces/include
rm -r my_robot_interfaces/src
```
Make a msg/ folder:
```bash
mkdir my_robot_interfaces/msg
```

Configure package.xml, add a new 3 lines:
```xml
  <build_depend>rosidl_default_generators</build_depend>
  <exec_depend>rosidl_default_runtime</exec_depend>
  <member_of_group>rosidl_interface_packages</member_of_group>
```

Configure the CMakeLists.txt:
```cmake
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
```

Go to msg/ folder and create a new file:
```bash
touch my_robot_interfaces/msg/HardwareStatus.msg
```

Edit the HardwareStatus.msg file, example:
```bash
int64 temperature
bool are_motors_ready
string debug_message
```

Generate the source code of the message in CMakelists.txt:
```cmake
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HardwareStatus.msg"
)
```

Build the package
```bash
colcon build --packages-select my_robot_interfaces
```

### Used in a Python Node
Add path to the VSCode settings.json:
File->Preferences->Settings->Extensions->Python->Python Path
```json
"python.autoComplete.extraPaths": [
    "/home/your_user/Documents/Github/learn-ros2/section3/ros2_ws/install/my_robot_interfaces/lib/python3.8/site-packages"
]
```

### Used in a C++ Node
Edit the vscode setting c_cpp_properties.json:
```json
"includePath": [
        "${workspaceFolder}/**",
        "/opt/ros/humble/include/**",
        "/home/farhan-sw/Documents/Github/learn-ros2/section6-services/ros2_ws/install/my_robot_interfaces/include/**",
      ],
```

## Custom Srv
Using a step before, inser srv/ folder in robot_interfaces package:
```bash
mkdir my_robot_interfaces/srv
```

Create a new file in srv/ folder:
```bash
touch my_robot_interfaces/srv/ComputeRectangleArea.srv
```

Edit package.xml and CMAkeLists.txt as before. Add the srv in CMakelists.txt:
```cmake
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/HardwareStatus.msg"
  "srv/ComputeRectangleArea.srv"
)
```


