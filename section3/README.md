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
gedit ~/.bashrc
### Add the following lines
source /opt/ros/humble/setup.bash
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash

### Add the following lines corresponding to the ROS2 workspace
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