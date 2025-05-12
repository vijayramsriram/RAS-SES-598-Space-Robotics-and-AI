// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/VehicleGlobalPosition.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/vehicle_global_position__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__VehicleGlobalPosition__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x16, 0x0a, 0x88, 0x73, 0xf3, 0x16, 0x79, 0xf2,
      0xf1, 0xc1, 0x2b, 0x61, 0xbd, 0xa9, 0x52, 0x5d,
      0x85, 0x46, 0xca, 0x96, 0x9f, 0x9c, 0x53, 0x61,
      0x52, 0xb4, 0x7c, 0x35, 0x1c, 0x53, 0x14, 0x49,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__VehicleGlobalPosition__TYPE_NAME[] = "px4_msgs/msg/VehicleGlobalPosition";

// Define type names, field names, and default values
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__timestamp_sample[] = "timestamp_sample";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__lat[] = "lat";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__lon[] = "lon";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__alt[] = "alt";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__alt_ellipsoid[] = "alt_ellipsoid";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__delta_alt[] = "delta_alt";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__lat_lon_reset_counter[] = "lat_lon_reset_counter";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__alt_reset_counter[] = "alt_reset_counter";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__eph[] = "eph";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__epv[] = "epv";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__terrain_alt[] = "terrain_alt";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__terrain_alt_valid[] = "terrain_alt_valid";
static char px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__dead_reckoning[] = "dead_reckoning";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__VehicleGlobalPosition__FIELDS[] = {
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__timestamp_sample, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__lat, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__lon, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__alt, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__alt_ellipsoid, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__delta_alt, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__lat_lon_reset_counter, 21, 21},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__alt_reset_counter, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__eph, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__epv, 3, 3},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__terrain_alt, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__terrain_alt_valid, 17, 17},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__VehicleGlobalPosition__FIELD_NAME__dead_reckoning, 14, 14},
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
px4_msgs__msg__VehicleGlobalPosition__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__VehicleGlobalPosition__TYPE_NAME, 34, 34},
      {px4_msgs__msg__VehicleGlobalPosition__FIELDS, 14, 14},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# Fused global position in WGS84.\n"
  "# This struct contains global position estimation. It is not the raw GPS\n"
  "# measurement (@see vehicle_gps_position). This topic is usually published by the position\n"
  "# estimator, which will take more sources of information into account than just GPS,\n"
  "# e.g. control inputs of the vehicle in a Kalman-filter implementation.\n"
  "#\n"
  "\n"
  "uint64 timestamp\\t\\t# time since system start (microseconds)\n"
  "uint64 timestamp_sample         # the timestamp of the raw data (microseconds)\n"
  "\n"
  "float64 lat\\t\\t\\t# Latitude, (degrees)\n"
  "float64 lon\\t\\t\\t# Longitude, (degrees)\n"
  "float32 alt\\t\\t\\t# Altitude AMSL, (meters)\n"
  "float32 alt_ellipsoid\\t\\t# Altitude above ellipsoid, (meters)\n"
  "\n"
  "float32 delta_alt \\t# Reset delta for altitude\n"
  "uint8 lat_lon_reset_counter\\t# Counter for reset events on horizontal position coordinates\n"
  "uint8 alt_reset_counter \\t# Counter for reset events on altitude\n"
  "\n"
  "float32 eph\\t\\t\\t# Standard deviation of horizontal position error, (metres)\n"
  "float32 epv\\t\\t\\t# Standard deviation of vertical position error, (metres)\n"
  "\n"
  "float32 terrain_alt\\t\\t# Terrain altitude WGS84, (metres)\n"
  "bool terrain_alt_valid\\t\\t# Terrain altitude estimate is valid\n"
  "\n"
  "bool dead_reckoning\\t\\t# True if this position is estimated through dead-reckoning\n"
  "\n"
  "# TOPICS vehicle_global_position vehicle_global_position_groundtruth external_ins_global_position\n"
  "# TOPICS estimator_global_position\n"
  "# TOPICS aux_global_position";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__VehicleGlobalPosition__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__VehicleGlobalPosition__TYPE_NAME, 34, 34},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 1381, 1381},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__VehicleGlobalPosition__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__VehicleGlobalPosition__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
