#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

# Import Interfaces
from myrobot_interfaces.action import CountUntil

# Import Action
from rclpy.action import ActionClient
from rclpy.action.client import ClientGoalHandle, GoalStatus


class CountUntilClientNode(Node): 
    def __init__(self):
        super().__init__("count_until_client") 
        
        self.count_until_client_ = ActionClient(self, 
                                               CountUntil, 
                                               "count_until")
        
    
    def send_goal(self, target_number: int, period: float):
        # Wait for the server
        self.count_until_client_.wait_for_server()
        
        # Create a Goal
        goal = CountUntil.Goal()
        goal.target_number = target_number
        goal.period = period
        
        # Send the goal
        self.get_logger().info(f"Sending Goal Request: {goal}")
        self.count_until_client_.\
            send_goal_async(goal, feedback_callback=self.feedback_callback).\
                add_done_callback(self.goal_response_callback)
                
        # Send a Cancel Request 2secods later
        self.timer_ = self.create_timer(2.0, self.cancel_goal)
    
    def cancel_goal(self):
        self.get_logger().info("Send a Cancel Request")
        self.goal_handle_.cancel_goal_async()
        
        self.timer_.cancel()

    def goal_response_callback(self, future):
        self.goal_handle_ : ClientGoalHandle = future.result()
        if(self.goal_handle_.accepted):
            self.get_logger().info("Goal Accepted")
            self.goal_handle_.get_result_async().add_done_callback(self.goal_result_callback)
        else:
            self.get_logger().warn("Goal Rejected")
            
    def goal_result_callback(self, future):
        status = future.result().status
        result = future.result().result
        if status == GoalStatus.STATUS_SUCCEEDED:
            self.get_logger().info("Goal Succeeded")
        elif status == GoalStatus.STATUS_ABORTED:
            self.get_logger().error("Goal Aborted")
        elif status == GoalStatus.STATUS_CANCELED:
            self.get_logger().warn("Goal Canceled")
        
        self.get_logger().info(f"Result: {result.reached_number}")
    
    def feedback_callback(self, feedback_msg):
        self.get_logger().info(f"Received Feedback: {feedback_msg.feedback.current_number}")

def main(args=None):
    rclpy.init(args=args)
    node = CountUntilClientNode() 
    node.send_goal(5, 1.0)
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
