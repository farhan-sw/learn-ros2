#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer
from rclpy.action.server import ServerGoalHandle

import time
from myrobot_interfaces.action import CountUntil


class CountUntilServerNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("count_until_server") # MODIFY NAME
        
        self.count_until_action_server = ActionServer(self, 
                                                      CountUntil, 
                                                      "count_until", 
                                                      execute_callback=self.execute_callback)
        
        # LOGGER
        self.get_logger().info("Count Until Server has been started.")
        
    def execute_callback(self, goal_handle: ServerGoalHandle):
        # Get the request
        target_number = goal_handle.request.target_number
        period = goal_handle.request.period
        
        # Execute the action
        self.get_logger().info(f"Executing, target: {target_number}, period: {period}")
        
        # Start executing the action
        counter = 0
        for i in range(target_number):
            counter += 1
            self.get_logger().info(f"Count: {counter}")
            time.sleep(period)
            
        # Once Done, set goal final state
        goal_handle.succeed()
        
        # And send the result
        result = CountUntil.Result()
        result.reached_number = counter
        return result

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilServerNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()
