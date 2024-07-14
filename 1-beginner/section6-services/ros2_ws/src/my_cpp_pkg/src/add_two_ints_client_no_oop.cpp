#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"
#include "rclcpp/executors.hpp" // Add this line to include the appropriate header file

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("add_two_ints_client_no_oop"); // MODIFY NAME

    auto client = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

    while (!client->wait_for_service(std::chrono::seconds(1))) {
        if (!rclcpp::ok()) {
            RCLCPP_ERROR(node->get_logger(), "Interrupted while waiting for the service. Exiting.");
            return 1;
        }
        RCLCPP_INFO(node->get_logger(), "service not available, waiting again...");
    }

    auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
    request->a = 3;
    request->b = 4;

    auto future = client->async_send_request(request);
    if(rclcpp::spin_until_future_complete(node, future) == rclcpp::FutureReturnCode::SUCCESS) { // Update the type to rclcpp::FutureReturnCode
        RCLCPP_INFO(node->get_logger(), "%ld + %ld = %ld", request->a, request->b, future.get()->sum);
    } else {
        RCLCPP_ERROR(node->get_logger(), "Failed to call service add_two_ints");
    }
    
    rclcpp::shutdown();
    return 0;
}
