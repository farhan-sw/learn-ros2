// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:srv/SetLed.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__SRV__DETAIL__SET_LED__STRUCT_H_
#define MY_ROBOT_INTERFACES__SRV__DETAIL__SET_LED__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'ledstates'
#include "my_robot_interfaces/msg/detail/led_states__struct.h"

/// Struct defined in srv/SetLed in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__SetLed_Request
{
  my_robot_interfaces__msg__LedStates ledstates;
} my_robot_interfaces__srv__SetLed_Request;

// Struct for a sequence of my_robot_interfaces__srv__SetLed_Request.
typedef struct my_robot_interfaces__srv__SetLed_Request__Sequence
{
  my_robot_interfaces__srv__SetLed_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__SetLed_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/SetLed in the package my_robot_interfaces.
typedef struct my_robot_interfaces__srv__SetLed_Response
{
  bool success;
} my_robot_interfaces__srv__SetLed_Response;

// Struct for a sequence of my_robot_interfaces__srv__SetLed_Response.
typedef struct my_robot_interfaces__srv__SetLed_Response__Sequence
{
  my_robot_interfaces__srv__SetLed_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__srv__SetLed_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__SRV__DETAIL__SET_LED__STRUCT_H_
