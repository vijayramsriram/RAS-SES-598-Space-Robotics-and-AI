// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/VehicleOdometry.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/vehicle_odometry__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__VehicleOdometry__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x42, 0x95, 0xb9, 0x6a, 0xd3, 0x12, 0x08, 0x4a,
      0xa3, 0x5c, 0x84, 0xbd, 0xce, 0xc6, 0x5b, 0xa2,
      0xf5, 0x7e, 0xb4, 0xf6, 0xa2, 0x93, 0xd5, 0x7d,
      0x52, 0xd9, 0x5a, 0xcb, 0xe9, 0x9f, 0xf8, 0x17,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__VehicleOdometry__TYPE_NAME[] = "px4_msgs/msg/VehicleOdometry";

// Define type names, field names, and default values
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__timestamp_sample[] = "timestamp_sample";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__pose_frame[] = "pose_frame";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__position[] = "position";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__q[] = "q";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__velocity_frame[] = "velocity_frame";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__velocity[] = "velocity";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__angular_velocity[] = "angular_velocity";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__position_variance[] = "position_variance";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__orientation_variance[] = "orientation_variance";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__velocity_variance[] = "velocity_variance";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__reset_counter[] = "reset_counter";
static char px4_msgs__msg__VehicleOdometry__FIELD_NAME__quality[] = "quality";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__VehicleOdometry__FIELDS[] = {
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__timestamp_sample, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__pose_frame, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__position, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__q, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      4,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__velocity_frame, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__velocity, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__angular_velocity, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__position_variance, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__orientation_variance, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__velocity_variance, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__reset_counter, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleOdometry__FIELD_NAME__quality, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
px4_msgs__msg__VehicleOdometry__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__VehicleOdometry__TYPE_NAME, 28, 28},
      {px4_msgs__msg__VehicleOdometry__FIELDS, 13, 13},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Vehicle odometry data. Fits ROS REP 147 for aerial vehicles\n"
  "uint64 timestamp\\t\\t# time since system start (microseconds)\n"
  "uint64 timestamp_sample\n"
  "\n"
  "uint8 POSE_FRAME_UNKNOWN = 0\n"
  "uint8 POSE_FRAME_NED     = 1 # NED earth-fixed frame\n"
  "uint8 POSE_FRAME_FRD     = 2 # FRD world-fixed frame, arbitrary heading reference\n"
  "uint8 pose_frame            # Position and orientation frame of reference\n"
  "\n"
  "float32[3] position         # Position in meters. Frame of reference defined by local_frame. NaN if invalid/unknown\n"
  "float32[4] q                # Quaternion rotation from FRD body frame to reference frame. First value NaN if invalid/unknown\n"
  "\n"
  "uint8 VELOCITY_FRAME_UNKNOWN  = 0\n"
  "uint8 VELOCITY_FRAME_NED      = 1 # NED earth-fixed frame\n"
  "uint8 VELOCITY_FRAME_FRD      = 2 # FRD world-fixed frame, arbitrary heading reference\n"
  "uint8 VELOCITY_FRAME_BODY_FRD = 3 # FRD body-fixed frame\n"
  "uint8 velocity_frame        # Reference frame of the velocity data\n"
  "\n"
  "float32[3] velocity         # Velocity in meters/sec. Frame of reference defined by velocity_frame variable. NaN if invalid/unknown\n"
  "\n"
  "float32[3] angular_velocity # Angular velocity in body-fixed frame (rad/s). NaN if invalid/unknown\n"
  "\n"
  "float32[3] position_variance\n"
  "float32[3] orientation_variance\n"
  "float32[3] velocity_variance\n"
  "\n"
  "uint8 reset_counter\n"
  "int8 quality\n"
  "\n"
  "# TOPICS vehicle_odometry vehicle_mocap_odometry vehicle_visual_odometry\n"
  "# TOPICS estimator_odometry";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__VehicleOdometry__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__VehicleOdometry__TYPE_NAME, 28, 28},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1390, 1390},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__VehicleOdometry__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__VehicleOdometry__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
