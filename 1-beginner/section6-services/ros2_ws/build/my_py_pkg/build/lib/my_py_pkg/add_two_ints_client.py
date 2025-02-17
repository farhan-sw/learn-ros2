#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from functools import partial

from example_interfaces.srv import AddTwoInts # MODIFY NAME


class AddTwoIntsClient(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("add_two_ints_client") # MODIFY NAME
        self.call_add_two_ints_server(1, 2)
    
    def call_add_two_ints_server(self, a, b):
        # Explanation of the code below:
        # 1. Create a client object of the AddTwoInts service
        # 2. Wait for the server to be available
        client = self.create_client(AddTwoInts, "add_two_ints")
        while not client.wait_for_service(1.0):
            self.get_logger().warn("Waiting for Server...")
            
        # 3. Create a request object of the AddTwoInts service
        request = AddTwoInts.Request()
         
        request.a = a
        request.b = b
        
        # 5. Send the request to the server and wait for the response
        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_add_two_ints, a=a, b=b))
    
    def callback_call_add_two_ints(self, future, a, b):
        try:
            response = future.result()
            self.get_logger().info(str(a) + " + " + str(b) + " = " + str(response.sum))
        except Exception as e:
            self.get_logger().error("Service call failed %r" % (e,))
        


def main(args=None):
    rclpy.init(args=args)
    node = AddTwoIntsClient() # MODIFY NAME
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
