// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from my_robot_interfaces:msg/BooleanArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "my_robot_interfaces/msg/detail/boolean_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace my_robot_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void BooleanArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) my_robot_interfaces::msg::BooleanArray(_init);
}

void BooleanArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<my_robot_interfaces::msg::BooleanArray *>(message_memory);
  typed_message->~BooleanArray();
}

size_t size_function__BooleanArray__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<bool> *>(untyped_member);
  return member->size();
}

void fetch_function__BooleanArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & member = *reinterpret_cast<const std::vector<bool> *>(untyped_member);
  auto & value = *reinterpret_cast<bool *>(untyped_value);
  value = member[index];
}

void assign_function__BooleanArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & member = *reinterpret_cast<std::vector<bool> *>(untyped_member);
  const auto & value = *reinterpret_cast<const bool *>(untyped_value);
  member[index] = value;
}

void resize_function__BooleanArray__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<bool> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember BooleanArray_message_member_array[1] = {
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_robot_interfaces::msg::BooleanArray, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__BooleanArray__data,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    fetch_function__BooleanArray__data,  // fetch(index, &value) function pointer
    assign_function__BooleanArray__data,  // assign(index, value) function pointer
    resize_function__BooleanArray__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers BooleanArray_message_members = {
  "my_robot_interfaces::msg",  // message namespace
  "BooleanArray",  // message name
  1,  // number of fields
  sizeof(my_robot_interfaces::msg::BooleanArray),
  BooleanArray_message_member_array,  // message members
  BooleanArray_init_function,  // function to initialize message memory (memory has to be allocated)
  BooleanArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t BooleanArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &BooleanArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace my_robot_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<my_robot_interfaces::msg::BooleanArray>()
{
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::BooleanArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, my_robot_interfaces, msg, BooleanArray)() {
  return &::my_robot_interfaces::msg::rosidl_typesupport_introspection_cpp::BooleanArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
