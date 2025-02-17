// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/LedStates.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/led_states__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_LedStates_states
{
public:
  explicit Init_LedStates_states(::my_robot_interfaces::msg::LedStates & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::LedStates states(::my_robot_interfaces::msg::LedStates::_states_type arg)
  {
    msg_.states = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStates msg_;
};

class Init_LedStates_led
{
public:
  Init_LedStates_led()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LedStates_states led(::my_robot_interfaces::msg::LedStates::_led_type arg)
  {
    msg_.led = std::move(arg);
    return Init_LedStates_states(msg_);
  }

private:
  ::my_robot_interfaces::msg::LedStates msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::LedStates>()
{
  return my_robot_interfaces::msg::builder::Init_LedStates_led();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__LED_STATES__BUILDER_HPP_
