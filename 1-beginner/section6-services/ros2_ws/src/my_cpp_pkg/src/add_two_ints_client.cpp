#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/srv/add_two_ints.hpp"

class AddTwoClientNode : public rclcpp::Node // MODIFY NAME
{
public:
    AddTwoClientNode() : Node("add_two_ints_client") // MODIFY NAME
    {
        thread_.push_back(std::thread(std::bind(&AddTwoClientNode::callAddTwoIntsService, this, 1, 2)));
        thread_.push_back(std::thread(std::bind(&AddTwoClientNode::callAddTwoIntsService, this, 4, 2)));
    }

    void callAddTwoIntsService(int a, int b)
    {
        // Explanation
        // The create_client function is a member function of the Node class that creates a client for a service.
        // The template parameter is the service type, which is example_interfaces::srv::AddTwoInts in this case.
        auto client = this->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

        // Explanation
        // The wait_for_service function is a member function of the Client class that waits for the service to be available.
        // The argument is the timeout duration, which is std::chrono::seconds(1) in this case.
        while(!client->wait_for_service(std::chrono::seconds(1))) {
            if(!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }

        // Explanation
        // The async_send_request function is a member function of the Client class that sends a request to the service asynchronously.
        // The argument is the request message, which is a shared pointer to example_interfaces::srv::AddTwoInts::Request in this case.
        auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();
        request->a = a;
        request->b = b;

        auto future = client->async_send_request(request);

        try{
            auto response = future.get();
            RCLCPP_INFO(this->get_logger(), "%ld + %ld = %ld", request->a, request->b, response->sum);
        }
        catch(const std::exception& e){
            RCLCPP_ERROR(this->get_logger(), "Service call failed");
        }
        
        
    }

private:
    std::vector<std::thread> thread_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<AddTwoClientNode>(); // MODIFY NAME
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
