from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    
    remap_number_topic =  ("number", "my_number")
    
    number_publisher_node = Node(
        package="my_py_pkg",
        executable="number_publisher",
        parameters=[
            {"number_to_publish": 4},
            {"frequency_hz": 2}
        ],
        
        remappings=[remap_number_topic]
    )
    
    number_counter_mode = Node(
        package="my_cpp_pkg",
        executable="number_counter",
        name="number_counter",
        remappings=[remap_number_topic]
    )
    
    ld.add_action(number_publisher_node)
    ld.add_action(number_counter_mode)
    
    
    return ld