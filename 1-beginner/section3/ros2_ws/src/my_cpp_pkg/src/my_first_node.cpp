#include <rclcpp/rclcpp.hpp>

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("cpp_test"), counter_(0)
    {
        RCLCPP_INFO(this->get_logger(), "Hello Cpp Node");
        timer_ = this->create_wall_timer(std::chrono::seconds(1),
                                         std::bind(&MyNode::timerCallback, this));
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_ = 0;

    void timerCallback()
    {
        counter_++;
        RCLCPP_INFO(this->get_logger(), "Hello %d", counter_);
    }
};

int main(int args, char **argv)
{
    // Initialize the ROS 2 system
    rclcpp::init(args, argv);

    // Create a node
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);

    // Shutdown the ROS 2 system
    rclcpp::shutdown();

    return 0;
}