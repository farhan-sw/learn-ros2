#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String


class SmartphoneNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("smartphone") # MODIFY NAME

        # Set Subscriber
        self.subscriber = self.create_subscription(String, "robot_news", self.callback_robot_news, 10)

        # Print the message for a best practice
        self.get_logger().info("Smartphone has been started.")
    
    def callback_robot_news(self, msg):
        self.get_logger().info("Message Received: " + msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = SmartphoneNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
