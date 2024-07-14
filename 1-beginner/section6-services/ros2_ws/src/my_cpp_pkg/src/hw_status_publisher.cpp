#include "rclcpp/rclcpp.hpp"
#include "my_robot_interfaces/msg/hardware_status.hpp"

class HardwareStatusPublisher : public rclcpp::Node // MODIFY NAME
{
public:
    HardwareStatusPublisher() : Node("node_name") // MODIFY NAME
    {
        publisher_ = this->create_publisher<my_robot_interfaces::msg::HardwareStatus>("hardware_status", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&HardwareStatusPublisher::publishHardwareStatus, this));

        RCLCPP_INFO(this->get_logger(), "Hardware Status Publisher has been started.");
    }

private:
    rclcpp::Publisher<my_robot_interfaces::msg::HardwareStatus>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    void publishHardwareStatus()
    {
        auto msg = my_robot_interfaces::msg::HardwareStatus();
        msg.temperature = 45;
        msg.are_motors_ready = true;
        msg.debug_message = "Motors are ready to use.";
        RCLCPP_INFO(this->get_logger(), "Publishing: Temperature: %ld, Motors Ready: %d", msg.temperature, msg.are_motors_ready);
        publisher_->publish(msg);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<HardwareStatusPublisher>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
