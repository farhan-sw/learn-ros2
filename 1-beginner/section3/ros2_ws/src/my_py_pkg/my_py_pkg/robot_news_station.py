#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.msg import String


class RobotNewsStationNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("robot_news_station") # MODIFY NAME 

        # Explanation of the code below
        # self.publishers_ is a list of publishers.
        # Each publisher is responsible for publishing a message of type String to a topic.
        # The topic is called "robot_news".
        # The queue size is 10, which means that if messages are published faster than they are processed, the messages are buffered up to 10.
        self.robot_name_ = "C3PO"
        self.publishers_ = self.create_publisher(String, "robot_news", 10)

        # Set the timer
        # The timer is set to call the publish_news method every 0.5 seconds. (2Hz)
        self.timer_ = self.create_timer(0.5, self.publish_news)

        # Print the message for a best practice
        self.get_logger().info("Robot News Station has been started.")
    
    def publish_news(self):
        msg = String()
        msg.data = "Hi, this is " + self.robot_name_ + " from the Robot News Station."
        self.publishers_.publish(msg)
        


def main(args=None):
    rclpy.init(args=args)
    node = RobotNewsStationNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
