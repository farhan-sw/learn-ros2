#include <rclcpp/rclcpp.hpp>

int main(int args, char **argv) {
    // Initialize the ROS 2 system
    rclcpp::init(args, argv);


    // Create a node
    auto node = std::make_shared<rclcpp::Node>("cpp_test");
    RCLCPP_INFO(node->get_logger(), "Hello Cpp Node");

    rclcpp::spin(node);


    // Shutdown the ROS 2 system
    rclcpp::shutdown();

    return 0;
}