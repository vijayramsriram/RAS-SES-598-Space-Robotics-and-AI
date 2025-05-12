// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/ActuatorArmed.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/actuator_armed__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__ActuatorArmed__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x6a, 0xf5, 0x77, 0x0c, 0xcd, 0xd1, 0x1d, 0x21,
      0x91, 0x4c, 0xc1, 0x22, 0xf5, 0x98, 0x95, 0xd1,
      0xcb, 0x06, 0xe4, 0x49, 0x78, 0x5e, 0x78, 0xd6,
      0xe1, 0x5d, 0xf9, 0x4a, 0x89, 0x1c, 0xe4, 0x6e,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__ActuatorArmed__TYPE_NAME[] = "px4_msgs/msg/ActuatorArmed";

// Define type names, field names, and default values
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__armed[] = "armed";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__prearmed[] = "prearmed";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__ready_to_arm[] = "ready_to_arm";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__lockdown[] = "lockdown";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__manual_lockdown[] = "manual_lockdown";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__force_failsafe[] = "force_failsafe";
static char px4_msgs__msg__ActuatorArmed__FIELD_NAME__in_esc_calibration_mode[] = "in_esc_calibration_mode";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__ActuatorArmed__FIELDS[] = {
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__armed, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__prearmed, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__ready_to_arm, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__lockdown, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__manual_lockdown, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__force_failsafe, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__ActuatorArmed__FIELD_NAME__in_esc_calibration_mode, 23, 23},
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
px4_msgs__msg__ActuatorArmed__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__ActuatorArmed__TYPE_NAME, 26, 26},
      {px4_msgs__msg__ActuatorArmed__FIELDS, 8, 8},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 timestamp\\t# time since system start (microseconds)\n"
  "\n"
  "bool armed\\t\\t# Set to true if system is armed\n"
  "bool prearmed\\t\\t# Set to true if the actuator safety is disabled but motors are not armed\n"
  "bool ready_to_arm\\t# Set to true if system is ready to be armed\n"
  "bool lockdown\\t\\t# Set to true if actuators are forced to being disabled (due to emergency or HIL)\n"
  "bool manual_lockdown    # Set to true if manual throttle kill switch is engaged\n"
  "bool force_failsafe\\t# Set to true if the actuators are forced to the failsafe position\n"
  "bool in_esc_calibration_mode # IO/FMU should ignore messages from the actuator controls topics";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__ActuatorArmed__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__ActuatorArmed__TYPE_NAME, 26, 26},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 615, 615},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__ActuatorArmed__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__ActuatorArmed__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
