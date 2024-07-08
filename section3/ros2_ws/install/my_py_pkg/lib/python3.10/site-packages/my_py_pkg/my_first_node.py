#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
### the name of the file can be different from the name of the node and can be different from the name of the executable

class MyNode(Node):
    def __init__(self):
        super().__init__("py_test")
        self.counter_ = 0
        self.get_logger().info("Hello ROS2")

        # Create timer
        self.create_timer(0.5, self.timer_callback) # set to 2Hz (0.5s period)

    def timer_callback(self):
        self.counter_ += 1
        self.get_logger().info("Hello " + str(self.counter_))

def main(args=None):
    rclpy.init(args=args)

    # create a node
    ## Node Name: py_test
    node = MyNode()

    # pause program allowing node to run
    rclpy.spin(node)


    rclpy.shutdown()


if __name__ == '__main__':
    main()