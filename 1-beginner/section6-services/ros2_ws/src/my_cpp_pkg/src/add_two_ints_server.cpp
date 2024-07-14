#include "rclcpp/rclcpp.hpp"

// INclude the service type
#include "example_interfaces/srv/add_two_ints.hpp"

using std::placeholders::_1;
using std::placeholders::_2;

class AddTwoIntsServerNode : public rclcpp::Node // MODIFY NAME
{
public:
    AddTwoIntsServerNode() : Node("add_two_ints_server") // MODIFY NAME
    {
        service_ = this->create_service<example_interfaces::srv::AddTwoInts>(
            "add_two_ints", std::bind(&AddTwoIntsServerNode::callbackAddTwoInts, this, _1, _2));

        
        // Log Info Servo Init
        RCLCPP_INFO(this->get_logger(), "Add Two Ints Server has been started.");
    }

private:
    rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service_;

    void callbackAddTwoInts(const example_interfaces::srv::AddTwoInts::Request::SharedPtr request,
                            const example_interfaces::srv::AddTwoInts::Response::SharedPtr response)
    {
        response->sum = request->a + request->b;

        // Add Log
        RCLCPP_INFO(this->get_logger(), "Incoming request\na: %ld" " b: %ld = %ld", request->a, request->b, response->sum);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoIntsServerNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
