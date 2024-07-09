# Setup
## Setup Terminator
```bash
sudo apt install terminator -y
```

## Setup Python
```bash
pip install setuptools==58.2.0
```

## Setup Bash
```bash
gedit ~/.bashrc
```
an add the following lines

```bash
source /opt/ros/humble/setup.bash
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
```

for new ros2 workspace
```bash
source ~/Documents/Github/learn-ros2/section3/ros2_ws/install/setup.bash
```

# Create Workspace
Make a folder
```bash
mkdir ~/Documents/Github/learn-ros2/section3/ros2_ws/src
```
after that, build with colcon
```bash
colcon build
```
Note: run in the workspace folder, e.g. ~/Documents/Github/learn-ros2/section3/ros2_ws

Add the setup.bash to the bashrc in ros2_ws/install/setup.bash
```bash
gedit ~/.bashrc
```
an add the following lines

```bash
source ~/Documents/Github/learn-ros2/section3/ros2_ws/install/setup.bash
```



# Build pkg
## All packages
```bash
colcon build
```

## Specific package
```bash
colcon build --packages-select my_py_pkg
```

## Symlink (Only for Python)
Allowing to run the node without rebuilding the package
```bash
colcon build --packages-select my_py_pkg --symlink-install
```

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
```bash
"opt/ros/humble/include/**"
```

## edit CMakeLists.txt

# Create Node in Python
## Create a new package
```bash
ros2 pkg create --build-type ament_python my_py_pkg
```

## Create a new node
```bash
touch my_py_pkg/my_py_pkg/my_first_node.py
```

## Make the node executable
```bash
chmod +x my_py_pkg/my_py_pkg/my_first_node.py
```

## Setup the node in setup.py
```python
    'console_scripts': [
            ## Executable Name: py_node
            "py_node = my_py_pkg.my_first_node:main",
            "robot_news_station = my_py_pkg.robot_news_station:main"
        ],
```

## Have a Dependency?
go to package.xml and add the dependency
```xml
  <depend>rclpy</depend>
  <depend>example_interfaces</depend>
```

## Build the package with Symlink
```bash
colcon build --packages-select my_py_pkg --symlink-install
```

# Create Node in C++
## Create a new package
```bash
ros2 pkg create --build-type ament_cmake my_cpp_pkg
```

## Create a new node
```bash
touch my_cpp_pkg/src/my_first_node.cpp
```

## Have a Dependency?
go to package.xml and add the dependency
```xml
  <depend>rclcpp</depend>
  <depend>example_interfaces</depend>
```

go to cmake_lists.txt and add the dependency
```cmake
  find dependencies
  find_package(ament_cmake REQUIRED)
  find_package(rclcpp REQUIRED)
  find_package(example_interfaces REQUIRED)
```

## Create a new executable
```cmake
add_executable(robot_news_station src/robot_news_station.cpp)
ament_target_dependencies(robot_news_station rclcpp example_interfaces)
```

## Install the executable
```cmake
install(TARGETS
  cpp_node
  robot_news_station
  DESTINATION lib/${PROJECT_NAME}
)
```
