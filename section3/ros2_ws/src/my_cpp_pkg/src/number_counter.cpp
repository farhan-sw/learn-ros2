#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

class number_counter_node : public rclcpp::Node // MODIFY NAME
{
public:
    number_counter_node() : Node("number_counter") // MODIFY NAME
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
            "number", 10, std::bind(&number_counter_node::callbackNumber, this, std::placeholders::_1));

        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&number_counter_node::publishNumber, this));

        // Logger
        RCLCPP_INFO(this->get_logger(), "Number Counter has been started");

    }

private:
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    // Timer
    rclcpp::TimerBase::SharedPtr timer_;
    int count_ = 0;

    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Number Received: %ld", msg->data);
        count_++;
    }

    void publishNumber()
    {
        auto message = example_interfaces::msg::Int64();
        message.data = count_;
        publisher_->publish(message);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<number_counter_node>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
