#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/int64.hpp"

// Include for Section 6, Services (server)
#include "example_interfaces/srv/set_bool.hpp"
using std::placeholders::_1;
using std::placeholders::_2;

class number_counter_node : public rclcpp::Node // MODIFY NAME
{
public:
    number_counter_node() : Node("number_counter") // MODIFY NAME
    {
        subscriber_ = this->create_subscription<example_interfaces::msg::Int64>(
            "number", 10, std::bind(&number_counter_node::callbackNumber, this, std::placeholders::_1));

        publisher_ = this->create_publisher<example_interfaces::msg::Int64>("number_count", 10);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), std::bind(&number_counter_node::publishNumber, this));

        service_ = this->create_service<example_interfaces::srv::SetBool>(
            "reset_number_count", std::bind(&number_counter_node::callbackResetNumberCount, this, _1, _2));

        // Logger
        RCLCPP_INFO(this->get_logger(), "Number Counter has been started");

    }

private:
    rclcpp::Publisher<example_interfaces::msg::Int64>::SharedPtr publisher_;
    rclcpp::Subscription<example_interfaces::msg::Int64>::SharedPtr subscriber_;
    rclcpp::Service<example_interfaces::srv::SetBool>::SharedPtr service_;

    // Timer
    rclcpp::TimerBase::SharedPtr timer_;
    int count_ = 0;

    void callbackNumber(const example_interfaces::msg::Int64::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Number Received: %ld", msg->data);
        count_ += msg->data;
    }

    void publishNumber()
    {
        auto message = example_interfaces::msg::Int64();
        message.data = count_;
        publisher_->publish(message);
    }

    void callbackResetNumberCount(const example_interfaces::srv::SetBool::Request::SharedPtr request,
                                  const example_interfaces::srv::SetBool::Response::SharedPtr response)
    {
        if (request->data)
        {
            count_ = 0;
            response->success = true;
            response->message = "Number Count has been reset";

            RCLCPP_INFO(this->get_logger(), "Number Count has been reset");
        } else {
            response->success = false;
            response->message = "Number Count has not been reset";

            RCLCPP_INFO(this->get_logger(), "Number Count has not been reset");}
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
