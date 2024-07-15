# TF and URDF with Gazebo

## Table of Contents
- [TF (Transform) Overview](#tf-transform-overview)
- [Create URDF(URDF Robot Description Format)](#create-urdfurdf-robot-description-format)
  - [Add a Joint](#add-a-joint)
  - [Different Types of Joints](#different-types-of-joints)
- [Run the Robot State Publisher with URDF](#run-the-robot-state-publisher-with-urdf)


## TF (Transform) Overview
[Back to top](#tf-and-urdf-with-gazebo)
TF is a package that lets the user keep track of multiple coordinate frames over time. It maintains the relationship between different coordinate frames and allows us to perform transformations between them. It is a fundamental concept in ROS and is used in many packages. For example, the navigation stack uses TF to keep track of the robot's position in the world.

### How to see realationships between TF
[Back to top](#tf-and-urdf-with-gazebo)
```bash
sudo apt install ros-humble-tf2-tools
```
run TF in the terminal and then run the following command in another terminal
```bash
ros2 run tf2_tools view_frames
```
The file will be saved in the running directory as `frames.pdf`. Open the file to see the relationships between the frames.

## Create URDF(URDF Robot Description Format)
[Back to top](#tf-and-urdf-with-gazebo)

URDF is an XML format used in ROS to describe all elements of a robot. It is used to define the robot's kinematics, dynamics, visual representation, and sensors. It is used in many ROS packages, such as the navigation stack, to describe the robot's physical properties.

create a new urdf file
```bash
touch my_robot.urdf
```
make a template of URDF file
```xml
<?xml version="1.0"?>
<robot name="my_robot">

</robot>
```
example
```xml
<?xml version="1.0"?>
<robot name="my_robot">

    <material name="green">
        <color rgba="0 0.5 0 1"/>
    </material>

    <link name="base_link">
        <visual>
            <geometry>
                <box size="0.6 0.4 0.2"/>
            </geometry>
            <origin xyz="0 0 0" rpy="0 0 0"/>
            <material name="green"/>
        </visual>
    </link>
</robot>
```

View example in RViz
```bash
ros2 launch urdf_tutorial display.launch.py model:=my_robot.urdf
```
Notes : if error, give a full path of my_robot.urdf example
```bash
ros2 launch urdf_tutorial display.launch.py model:=/home/farhan-sw/Documents/Github/learn-ros2/2-intermediate/section3-urdf/my_robot.urdf
```

### Add a Joint
[Back to top](#tf-and-urdf-with-gazebo)
```xml
<joint name="base_second_joint" type="fixed">
        <parent link="base_link"/>
        <child link="second_link"/>
        <origin xyz="0 0 0.2" rpy="0 0 0"/>
    </joint>
```

Tips naming the join is important. {parent_link}_{child_link}_joint. another tips is initialize the origin with all 0 value.

1. Fix Origin point of the joint
2. Fix the visual

### Different Types of Joints
[Back to top](#tf-and-urdf-with-gazebo)

Using reference from [ROS URDF](https://wiki.ros.org/urdf/XML)

## Run the Robot State Publisher with URDF
[Back to top](#tf-and-urdf-with-gazebo)

Install the Xacro package
```bash
sudo apt install ros-humble-xacro
```
Start the state publisher without any arguments
```bash
ros2 run robot_state_publisher robot_state_publisher
```
to pass an argument to the robot_state_publisher for the URDF file
```bash
ros2 run robot_state_publisher robot_state_publisher --ros-args -p robot_description:="$(xacro my_robot.urdf)"
```
for a complete example
```bash
ros2 run robot_state_publisher robot_state_publisher --ros-args -p robot_description:="$(xacro /home/farhan-sw/Documents/Github/learn-ros2/2-intermediate/section3-urdf/my_robot.urdf)"
```

viewing joint state wth gui
```bash
ros2 run joint_state_publisher_gui joint_state_publisher_gui
```

View the robot in RViz
```bash
ros2 run rviz2 rviz2
```

Add the robot model and TF in RViz

## Create Robot Description Package
[Back to top](#tf-and-urdf-with-gazebo)

The name of the package is usually the name of the robot with the suffix `_description`. For example, if the robot is called `my_robot`, the package name would be `my_robot_description`.

Create a new package
```bash
ros2 pkg create my_robot_description
```
Remove the include and source
```bash
rm -r my_robot_description/include my_robot_description/src
```
Make a URDF folder
```bash
mkdir my_robot_description/urdf
```
Move the URDF file to the URDF folder
```bash
mv my_robot.urdf my_robot_description/urdf
```

if u want to run vscode in existing workspace
```bash
code .
```

Edit the CmakeLists.txt
```cmake
install(DIRECTORY urdf
  DESTINATION share/${PROJECT_NAME}
)
```

## Write a Launch File using XML

1. Create a folder launch in the src/my_robot_description
2. For the best practice, launch file should be in the launch package. But for this example, we will put it in the src/my_robot_description folder as debugging purposes.

Edit the cmake file
```cmake
install(DIRECTORY urdf launch
  DESTINATION share/${PROJECT_NAME}
)
```

Create display.launch.xml
```bash
touch launch/display.launch.xml
```

To run the XML
```bash
colcon build
ros2 launch my_robot_description display.launch.xml
```

## Write a Launch File using Python
```bash
touch launch/display.launch.py
```
Normal Template
```python
from launch import LaunchDescription

def generate_launch_description():
    
    return LaunchDescription([
        
    ])
```
