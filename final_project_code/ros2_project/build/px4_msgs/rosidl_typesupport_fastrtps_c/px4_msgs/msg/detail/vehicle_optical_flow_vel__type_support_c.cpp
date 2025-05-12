// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from px4_msgs:msg/VehicleOpticalFlowVel.idl
// generated code does not contain a copyright notice
#include "px4_msgs/msg/detail/vehicle_optical_flow_vel__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "px4_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "px4_msgs/msg/detail/vehicle_optical_flow_vel__struct.h"
#include "px4_msgs/msg/detail/vehicle_optical_flow_vel__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _VehicleOpticalFlowVel__ros_msg_type = px4_msgs__msg__VehicleOpticalFlowVel;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
bool cdr_serialize_px4_msgs__msg__VehicleOpticalFlowVel(
  const px4_msgs__msg__VehicleOpticalFlowVel * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: timestamp_sample
  {
    cdr << ros_message->timestamp_sample;
  }

  // Field name: vel_body
  {
    size_t size = 2;
    auto array_ptr = ros_message->vel_body;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: vel_ne
  {
    size_t size = 2;
    auto array_ptr = ros_message->vel_ne;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: flow_rate_uncompensated
  {
    size_t size = 2;
    auto array_ptr = ros_message->flow_rate_uncompensated;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: flow_rate_compensated
  {
    size_t size = 2;
    auto array_ptr = ros_message->flow_rate_compensated;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: gyro_rate
  {
    size_t size = 3;
    auto array_ptr = ros_message->gyro_rate;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: gyro_bias
  {
    size_t size = 3;
    auto array_ptr = ros_message->gyro_bias;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ref_gyro
  {
    size_t size = 3;
    auto array_ptr = ros_message->ref_gyro;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
bool cdr_deserialize_px4_msgs__msg__VehicleOpticalFlowVel(
  eprosima::fastcdr::Cdr & cdr,
  px4_msgs__msg__VehicleOpticalFlowVel * ros_message)
{
  // Field name: timestamp
  {
    cdr >> ros_message->timestamp;
  }

  // Field name: timestamp_sample
  {
    cdr >> ros_message->timestamp_sample;
  }

  // Field name: vel_body
  {
    size_t size = 2;
    auto array_ptr = ros_message->vel_body;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: vel_ne
  {
    size_t size = 2;
    auto array_ptr = ros_message->vel_ne;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: flow_rate_uncompensated
  {
    size_t size = 2;
    auto array_ptr = ros_message->flow_rate_uncompensated;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: flow_rate_compensated
  {
    size_t size = 2;
    auto array_ptr = ros_message->flow_rate_compensated;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: gyro_rate
  {
    size_t size = 3;
    auto array_ptr = ros_message->gyro_rate;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: gyro_bias
  {
    size_t size = 3;
    auto array_ptr = ros_message->gyro_bias;
    cdr.deserialize_array(array_ptr, size);
  }

  // Field name: ref_gyro
  {
    size_t size = 3;
    auto array_ptr = ros_message->ref_gyro;
    cdr.deserialize_array(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
size_t get_serialized_size_px4_msgs__msg__VehicleOpticalFlowVel(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleOpticalFlowVel__ros_msg_type * ros_message = static_cast<const _VehicleOpticalFlowVel__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: timestamp_sample
  {
    size_t item_size = sizeof(ros_message->timestamp_sample);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_body
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->vel_body;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_ne
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->vel_ne;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: flow_rate_uncompensated
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->flow_rate_uncompensated;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: flow_rate_compensated
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->flow_rate_compensated;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gyro_rate
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->gyro_rate;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gyro_bias
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->gyro_bias;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ref_gyro
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->ref_gyro;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
size_t max_serialized_size_px4_msgs__msg__VehicleOpticalFlowVel(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: timestamp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: timestamp_sample
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: vel_body
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: vel_ne
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: flow_rate_uncompensated
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: flow_rate_compensated
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gyro_rate
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gyro_bias
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: ref_gyro
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = px4_msgs__msg__VehicleOpticalFlowVel;
    is_plain =
      (
      offsetof(DataType, ref_gyro) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
bool cdr_serialize_key_px4_msgs__msg__VehicleOpticalFlowVel(
  const px4_msgs__msg__VehicleOpticalFlowVel * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: timestamp
  {
    cdr << ros_message->timestamp;
  }

  // Field name: timestamp_sample
  {
    cdr << ros_message->timestamp_sample;
  }

  // Field name: vel_body
  {
    size_t size = 2;
    auto array_ptr = ros_message->vel_body;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: vel_ne
  {
    size_t size = 2;
    auto array_ptr = ros_message->vel_ne;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: flow_rate_uncompensated
  {
    size_t size = 2;
    auto array_ptr = ros_message->flow_rate_uncompensated;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: flow_rate_compensated
  {
    size_t size = 2;
    auto array_ptr = ros_message->flow_rate_compensated;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: gyro_rate
  {
    size_t size = 3;
    auto array_ptr = ros_message->gyro_rate;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: gyro_bias
  {
    size_t size = 3;
    auto array_ptr = ros_message->gyro_bias;
    cdr.serialize_array(array_ptr, size);
  }

  // Field name: ref_gyro
  {
    size_t size = 3;
    auto array_ptr = ros_message->ref_gyro;
    cdr.serialize_array(array_ptr, size);
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
size_t get_serialized_size_key_px4_msgs__msg__VehicleOpticalFlowVel(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _VehicleOpticalFlowVel__ros_msg_type * ros_message = static_cast<const _VehicleOpticalFlowVel__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: timestamp
  {
    size_t item_size = sizeof(ros_message->timestamp);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: timestamp_sample
  {
    size_t item_size = sizeof(ros_message->timestamp_sample);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_body
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->vel_body;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: vel_ne
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->vel_ne;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: flow_rate_uncompensated
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->flow_rate_uncompensated;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: flow_rate_compensated
  {
    size_t array_size = 2;
    auto array_ptr = ros_message->flow_rate_compensated;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gyro_rate
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->gyro_rate;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: gyro_bias
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->gyro_bias;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: ref_gyro
  {
    size_t array_size = 3;
    auto array_ptr = ros_message->ref_gyro;
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_px4_msgs
size_t max_serialized_size_key_px4_msgs__msg__VehicleOpticalFlowVel(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: timestamp
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: timestamp_sample
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Field name: vel_body
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: vel_ne
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: flow_rate_uncompensated
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: flow_rate_compensated
  {
    size_t array_size = 2;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gyro_rate
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: gyro_bias
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Field name: ref_gyro
  {
    size_t array_size = 3;
    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = px4_msgs__msg__VehicleOpticalFlowVel;
    is_plain =
      (
      offsetof(DataType, ref_gyro) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _VehicleOpticalFlowVel__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const px4_msgs__msg__VehicleOpticalFlowVel * ros_message = static_cast<const px4_msgs__msg__VehicleOpticalFlowVel *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_px4_msgs__msg__VehicleOpticalFlowVel(ros_message, cdr);
}

static bool _VehicleOpticalFlowVel__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  px4_msgs__msg__VehicleOpticalFlowVel * ros_message = static_cast<px4_msgs__msg__VehicleOpticalFlowVel *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_px4_msgs__msg__VehicleOpticalFlowVel(cdr, ros_message);
}

static uint32_t _VehicleOpticalFlowVel__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_px4_msgs__msg__VehicleOpticalFlowVel(
      untyped_ros_message, 0));
}

static size_t _VehicleOpticalFlowVel__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_px4_msgs__msg__VehicleOpticalFlowVel(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_VehicleOpticalFlowVel = {
  "px4_msgs::msg",
  "VehicleOpticalFlowVel",
  _VehicleOpticalFlowVel__cdr_serialize,
  _VehicleOpticalFlowVel__cdr_deserialize,
  _VehicleOpticalFlowVel__get_serialized_size,
  _VehicleOpticalFlowVel__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _VehicleOpticalFlowVel__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_VehicleOpticalFlowVel,
  get_message_typesupport_handle_function,
  &px4_msgs__msg__VehicleOpticalFlowVel__get_type_hash,
  &px4_msgs__msg__VehicleOpticalFlowVel__get_type_description,
  &px4_msgs__msg__VehicleOpticalFlowVel__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, px4_msgs, msg, VehicleOpticalFlowVel)() {
  return &_VehicleOpticalFlowVel__type_support;
}

#if defined(__cplusplus)
}
#endif
