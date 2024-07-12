#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from functools import partial

from my_robot_interfaces.msg import LedStates
from my_robot_interfaces.srv import SetLed

# For threading and sleep
import threading
import time

class BatteryNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("battery_node") # MODIFY NAME
        
        self.start_repeating_task()
        
        # Logger
        self.get_logger().info("Battery Node has been started.")
        
        
    def call_service_ledPanel(self, led, state):
        client = self.create_client(SetLed, "set_led")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server...")
            
        request = SetLed.Request()
        
        # set values of request object
        ledstate = LedStates()
        ledstate.led = led
        ledstate.states = state
        
        request.ledstates = ledstate
             
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_service_ledPanel, state=state))
    
    def callback_call_service_ledPanel(self, future, state):
        try:
            response = future.result()
            self.get_logger().info("LED Panel Status: " + str(response.success))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
            
    def start_repeating_task(self):
        self.get_logger().info("Starting repeating task")
        threading.Thread(target=self.task, daemon=True).start()
        
    def task(self):
        while True:
            self.call_service_ledPanel(3, True)
            time.sleep(4)
            self.call_service_ledPanel(3, False)
            time.sleep(6)

def main(args=None):
    rclpy.init(args=args)
    node = BatteryNode() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
