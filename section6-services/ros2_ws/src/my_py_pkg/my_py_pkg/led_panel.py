#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from functools import partial

from my_robot_interfaces.msg import LedStates
from my_robot_interfaces.msg import BooleanArray
from my_robot_interfaces.srv import SetLed

class LedPanelNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("led_panel_server") # MODIFY NAME
        
        self.led_states = [False, False, False]
        self.server_ = self.create_service(SetLed, "set_led", self.callback_set_led)
        
        # Set for a publishing rate of 2 Hz
        self.publishers_ = self.create_publisher(BooleanArray, "led_panel_states", 10)
        self.timer_ = self.create_timer(0.5, self.publish_led_states)
        
        
        # Logger
        self.get_logger().info("LED Panel has been started.")
    
    def callback_set_led(self, request, response):
        
        try:
            self.change_led_state(request.ledstates.led, request.ledstates.states)
            response.success = True
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
            response.success = False
        
        # Logger
        self.get_logger().info(f"LED: {request.ledstates.led} State: {request.ledstates.states} Status: {response.success}")
        
        return response

    def change_led_state(self, led, state):
        if (led == 1):
            self.led_states[0] = state
        elif (led == 2):
            self.led_states[1] = state
        elif (led == 3):
            self.led_states[2] = state
        else:
            raise ValueError("Invalid LED Number")
        
    def publish_led_states(self):
        msg = BooleanArray()
        msg.data = self.led_states.copy()
        self.publishers_.publish(msg)
        
        # Logger
        self.get_logger().info(f"Published LED States: {msg.data[0]}, {msg.data[1]}, {msg.data[2]}")

def main(args=None):
    rclpy.init(args=args)
    node = LedPanelNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
