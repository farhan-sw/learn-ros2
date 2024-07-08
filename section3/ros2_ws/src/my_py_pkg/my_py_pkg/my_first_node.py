#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

### the name of the file can be different from the name of the node and can be different from the name of the executable

def main(args=None):
    rclpy.init(args=args)

    # create a node
    ## Node Name: py_test
    node = Node("py_test")
    node.get_logger().info("Hello ROS2")

    # pause program allowing node to run
    rclpy.spin(node)


    rclpy.shutdown()


if __name__ == '__main__':
    main()