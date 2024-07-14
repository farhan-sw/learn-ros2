#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class RobotNewsStationNode : public rclcpp::Node // MODIFY NAME
{
public:
    RobotNewsStationNode() : Node("robot_news_station"), robot_name_("R2D2")
    {
        publisher_ = this->create_publisher<example_interfaces::msg::String>("robot_news", 10);

        // Create Timer
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), std::bind(&RobotNewsStationNode::publishNews, this));

        // Print to console that the node is started
        RCLCPP_INFO(this->get_logger(), "Robot News Station has been started");
    }

private:
    void publishNews()
    {
        auto message = example_interfaces::msg::String();
        message.data = std::string("Hello, this is ") + robot_name_ + std::string(" from the robot news station");
        publisher_->publish(message);
    }

    std::string robot_name_;
    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;

    // Create Timer
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNewsStationNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
