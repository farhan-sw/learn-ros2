
# ROS 2 Command Line Tools
## For ROS 2 command line tools, we will use the following tools:
```bash
cat ~/.bashrc
```

## Run Package
```bash
ros2 run <package_name> <executable_name>
```

## See Running Nodes
```bash
ros2 node list
```

## See Node Info
```bash
ros2 node info /<node_name>
```

## Rename Node in Runtime with CLI
```bash
ros2 run <package_name> <executable_name> --ros-args -r __node:=<new_node_name>
```

# Colcon
## Add Bash Auto Completion
To add bash auto completion for colcon, add the following line to your .bashrc file.
```bash
source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
```

## Setup Symlink
Used to avoid rebuilding the package every time we make a change. Only works for python packages.
```bash
colcon build --packages-select <package_name> --symlink-install
```

### Make Executable File
```bash
chmod +x <file_name>
```

example:
```bash
chmod +x src/<package_name>/scripts/<file_name>.py
```

# RQT and rqt_graph
## Open rqt
```bash
rqt
```  

## Open rqt_graph
```bash
rqt_graph
```

# TurtleSim
Simulation of a turtle that can move in a 2D plane.
  
## Install TurtleSim
```bash
sudo apt-get install ros-humble-turtlesim
``` 