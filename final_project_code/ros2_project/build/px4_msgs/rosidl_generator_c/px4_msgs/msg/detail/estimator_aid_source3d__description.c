// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from px4_msgs:msg/EstimatorAidSource3d.idl
// generated code does not contain a copyright notice

#include "px4_msgs/msg/detail/estimator_aid_source3d__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_px4_msgs
const rosidl_type_hash_t *
px4_msgs__msg__EstimatorAidSource3d__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x71, 0x56, 0xb6, 0xf6, 0x6f, 0xd3, 0xb5, 0xa7,
      0xd5, 0xea, 0x4e, 0x0d, 0x02, 0xc0, 0x02, 0xf0,
      0xc9, 0x8a, 0xed, 0x57, 0xb4, 0x3d, 0xae, 0x52,
      0x1a, 0x0e, 0x15, 0x33, 0xa7, 0x34, 0xef, 0xfd,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char px4_msgs__msg__EstimatorAidSource3d__TYPE_NAME[] = "px4_msgs/msg/EstimatorAidSource3d";

// Define type names, field names, and default values
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__timestamp[] = "timestamp";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__timestamp_sample[] = "timestamp_sample";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__estimator_instance[] = "estimator_instance";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__device_id[] = "device_id";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__time_last_fuse[] = "time_last_fuse";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__observation[] = "observation";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__observation_variance[] = "observation_variance";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__innovation[] = "innovation";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__innovation_variance[] = "innovation_variance";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__test_ratio[] = "test_ratio";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__innovation_rejected[] = "innovation_rejected";
static char px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__fused[] = "fused";

static rosidl_runtime_c__type_description__Field px4_msgs__msg__EstimatorAidSource3d__FIELDS[] = {
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__timestamp, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__timestamp_sample, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__estimator_instance, 18, 18},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT8,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__device_id, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT32,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__time_last_fuse, 14, 14},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_UINT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__observation, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__observation_variance, 20, 20},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__innovation, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__innovation_variance, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__test_ratio, 10, 10},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__innovation_rejected, 19, 19},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {px4_msgs__msg__EstimatorAidSource3d__FIELD_NAME__fused, 5, 5},
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
px4_msgs__msg__EstimatorAidSource3d__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {px4_msgs__msg__EstimatorAidSource3d__TYPE_NAME, 33, 33},
      {px4_msgs__msg__EstimatorAidSource3d__FIELDS, 12, 12},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "uint64 timestamp             # time since system start (microseconds)\n"
  "uint64 timestamp_sample      # the timestamp of the raw data (microseconds)\n"
  "\n"
  "uint8 estimator_instance\n"
  "\n"
  "uint32 device_id\n"
  "\n"
  "uint64 time_last_fuse\n"
  "\n"
  "float32[3] observation\n"
  "float32[3] observation_variance\n"
  "\n"
  "float32[3] innovation\n"
  "float32[3] innovation_variance\n"
  "float32[3] test_ratio\n"
  "\n"
  "bool innovation_rejected     # true if the observation has been rejected\n"
  "bool fused                   # true if the sample was successfully fused\n"
  "\n"
  "# TOPICS estimator_aid_src_ev_vel estimator_aid_src_gnss_vel estimator_aid_src_gravity estimator_aid_src_mag";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
px4_msgs__msg__EstimatorAidSource3d__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {px4_msgs__msg__EstimatorAidSource3d__TYPE_NAME, 33, 33},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 602, 602},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
px4_msgs__msg__EstimatorAidSource3d__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *px4_msgs__msg__EstimatorAidSource3d__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
