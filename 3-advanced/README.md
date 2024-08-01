## Setup ROS2 Action

1. Create a pkg
```bash
ros2 pkg create {name_of_the_robot}_interfaces
```
2. Prepare Folder
```bash 
rm -r include/ src/
mkdir msg srv action
```
3. Create Action
```bash
touch action/{verb}.action
```

4. Create Test Action
```bash
# Goal
int64 target_number
float64 period
---
#Result
int64 reched_number
---
# Feedback
int64 current_number
```

5. Edit Package.xml
```xml
  <buildtool_depend>rosidl_default_generators</buildtool_depend>
  <exec_depend>rosidl_default_runtime</exec_depend>  
  <member_of_group>rosidl_interface_packages</member_of_group>
  ```

6. Edit CMakeLists.txt
```cmake
# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "action/CountUntil.action"
)

ament_export_dependencies(rosidl_default_runtime)


ament_package()
```

7. Show the Interface
```bash
ros2 interface show {name_of_the_robot}_interfaces/action/CountUntil
```

## Python Action
1. Create a pkg
```bash
ros2 pkg create actions_py --build-type ament_python --dependencies rclpy myrobot_interfaces/
```
2. Create a Python File
```python
touch actions_py/actions_py/count_until_server.py
chmod +x actions_py/actions_py/count_until_server.py
```