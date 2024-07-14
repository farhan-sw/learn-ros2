#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts


def main(args=None):
    rclpy.init(args=args)
    node = Node("add_two_ints_no_oop")
    
    # Explanation parameter: 1. Service type, 2. Service name
    client = node.create_client(AddTwoInts, "add_two_ints")
    
    # Explanation: Wait for the service to be available
    while(not client.wait_for_service(1.0)):
        node.get_logger().warn("Service not available, waiting again...")
    # Log message
    node.get_logger().info("Service is available")
    
    request = AddTwoInts.Request()
    request.a = 3
    request.b = 8
    
    # Call the service
    # Ecplanation async: Asynchronous call will not block the main thread and will return immediately
    # Explanation without async: Synchronous call will block the main thread until the service is completed
    future = client.call_async(request)
    # Explanation: Spin until the future is complete, i.e. the service is completed
    rclpy.spin_until_future_complete(node, future)
    
    try:
        response = future.result()
    except Exception as e:
        node.get_logger().error(f"Service call failed {e}")
        
    
    node.get_logger().info(f"Response: {response.sum}")
    
    rclpy.shutdown()


if __name__ == "__main__":
    main()
