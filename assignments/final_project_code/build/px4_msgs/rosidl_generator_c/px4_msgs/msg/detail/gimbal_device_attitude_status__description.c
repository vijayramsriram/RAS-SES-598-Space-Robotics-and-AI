// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/GimbalDeviceAttitudeStatus.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/gimbal_device_attitude_status__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__GimbalDeviceAttitudeStatus__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x9c, 0xf5, 0x40, 0x4f, 0x4f, 0x56, 0x0e, 0x34,
      0x8c, 0x03, 0x8c, 0xd3, 0x32, 0x18, 0x5b, 0xea,
      0xd0, 0xdf, 0x3b, 0xee, 0x31, 0x1b, 0x5c, 0x8f,
      0x9b, 0x14, 0x08, 0x10, 0xef, 0xf9, 0x28, 0x61,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__GimbalDeviceAttitudeStatus__TYPE_NAME[] = "px4_msgs/msg/GimbalDeviceAttitudeStatus";

// Define type names, field names, and default values
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__target_system[] = "target_system";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__target_component[] = "target_component";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__device_flags[] = "device_flags";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__q[] = "q";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__angular_velocity_x[] = "angular_velocity_x";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__angular_velocity_y[] = "angular_velocity_y";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__angular_velocity_z[] = "angular_velocity_z";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__failure_flags[] = "failure_flags";
static char px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__received_from_mavlink[] = "received_from_mavlink";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELDS[] = {
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__target_system, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__target_component, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__device_flags, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT16,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      4,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__angular_velocity_x, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__angular_velocity_y, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__angular_velocity_z, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__failure_flags, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELD_NAME__received_from_mavlink, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
px4_msgs__msg__GimbalDeviceAttitudeStatus__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__GimbalDeviceAttitudeStatus__TYPE_NAME, 39, 39},
      {px4_msgs__msg__GimbalDeviceAttitudeStatus__FIELDS, 10, 10},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 timestamp\\t\\t\\t\\t\\t\\t# time since system start (microseconds)\n"
  "\n"
  "uint8 target_system\n"
  "uint8 target_component\n"
  "uint16 device_flags\n"
  "\n"
  "uint16 DEVICE_FLAGS_RETRACT = 1\n"
  "uint16 DEVICE_FLAGS_NEUTRAL = 2\n"
  "uint16 DEVICE_FLAGS_ROLL_LOCK = 4\n"
  "uint16 DEVICE_FLAGS_PITCH_LOCK = 8\n"
  "uint16 DEVICE_FLAGS_YAW_LOCK = 16\n"
  "\n"
  "float32[4] q\n"
  "float32 angular_velocity_x\n"
  "float32 angular_velocity_y\n"
  "float32 angular_velocity_z\n"
  "\n"
  "uint32 failure_flags\n"
  "\n"
  "bool received_from_mavlink";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__GimbalDeviceAttitudeStatus__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__GimbalDeviceAttitudeStatus__TYPE_NAME, 39, 39},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 440, 440},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__GimbalDeviceAttitudeStatus__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__GimbalDeviceAttitudeStatus__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
