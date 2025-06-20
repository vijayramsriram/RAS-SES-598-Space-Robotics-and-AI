// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from px4_msgs:msg/VehicleLocalPosition.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "px4_msgs/msg/vehicle_local_position.h"


#ifndef PX4_MSGS__MSG__DETAIL__VEHICLE_LOCAL_POSITION__STRUCT_H_
#define PX4_MSGS__MSG__DETAIL__VEHICLE_LOCAL_POSITION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Constant 'DIST_BOTTOM_SENSOR_NONE'.
enum
{
  px4_msgs__msg__VehicleLocalPosition__DIST_BOTTOM_SENSOR_NONE = 0
};

/// Constant 'DIST_BOTTOM_SENSOR_RANGE'.
/**
  * (1 << 0) a range sensor is used to estimate dist_bottom field
 */
enum
{
  px4_msgs__msg__VehicleLocalPosition__DIST_BOTTOM_SENSOR_RANGE = 1
};

/// Constant 'DIST_BOTTOM_SENSOR_FLOW'.
/**
  * (1 << 1) a flow sensor is used to estimate dist_bottom field (mostly fixed-wing use case)
 */
enum
{
  px4_msgs__msg__VehicleLocalPosition__DIST_BOTTOM_SENSOR_FLOW = 2
};

/// Struct defined in msg/VehicleLocalPosition in the package px4_msgs.
/**
  * Fused local position in NED.
  * The coordinate system origin is the vehicle position at the time when the EKF2-module was started.
 */
typedef struct px4_msgs__msg__VehicleLocalPosition
{
  /// time since system start (microseconds)
  uint64_t timestamp;
  /// the timestamp of the raw data (microseconds)
  uint64_t timestamp_sample;
  /// true if x and y are valid
  bool xy_valid;
  /// true if z is valid
  bool z_valid;
  /// true if vx and vy are valid
  bool v_xy_valid;
  /// true if vz is valid
  bool v_z_valid;
  /// Position in local NED frame
  /// North position in NED earth-fixed frame, (metres)
  float x;
  /// East position in NED earth-fixed frame, (metres)
  float y;
  /// Down position (negative altitude) in NED earth-fixed frame, (metres)
  float z;
  /// Position reset delta
  /// Amount of lateral shift of position estimate in latest reset (in x and y)
  float delta_xy[2];
  /// Index of latest lateral position estimate reset
  uint8_t xy_reset_counter;
  /// Amount of vertical shift of position estimate in latest reset
  float delta_z;
  /// Index of latest vertical position estimate reset
  uint8_t z_reset_counter;
  /// Velocity in NED frame
  /// North velocity in NED earth-fixed frame, (metres/sec)
  float vx;
  /// East velocity in NED earth-fixed frame, (metres/sec)
  float vy;
  /// Down velocity in NED earth-fixed frame, (metres/sec)
  float vz;
  /// Down position time derivative in NED earth-fixed frame, (metres/sec)
  float z_deriv;
  /// Velocity reset delta
  /// Amount of lateral shift of velocity estimate in latest reset (in x and y)
  float delta_vxy[2];
  /// Index of latest vertical velocity estimate reset
  uint8_t vxy_reset_counter;
  /// Amount of vertical shift of velocity estimate in latest reset
  float delta_vz;
  /// Index of latest vertical velocity estimate reset
  uint8_t vz_reset_counter;
  /// Acceleration in NED frame
  /// North velocity derivative in NED earth-fixed frame, (metres/sec^2)
  float ax;
  /// East velocity derivative in NED earth-fixed frame, (metres/sec^2)
  float ay;
  /// Down velocity derivative in NED earth-fixed frame, (metres/sec^2)
  float az;
  /// Euler yaw angle transforming the tangent plane relative to NED earth-fixed frame, -PI..+PI,  (radians)
  float heading;
  float heading_var;
  /// Same as heading but generated by integrating corrected gyro data only
  float unaided_heading;
  /// Heading delta caused by latest heading reset
  float delta_heading;
  /// Index of latest heading reset
  uint8_t heading_reset_counter;
  bool heading_good_for_control;
  float tilt_var;
  /// Position of reference point (local NED frame origin) in global (GPS / WGS84) frame
  /// true if position (x, y) has a valid global reference (ref_lat, ref_lon)
  bool xy_global;
  /// true if z has a valid global reference (ref_alt)
  bool z_global;
  /// Time when reference position was set since system start, (microseconds)
  uint64_t ref_timestamp;
  /// Reference point latitude, (degrees)
  double ref_lat;
  /// Reference point longitude, (degrees)
  double ref_lon;
  /// Reference altitude AMSL, (metres)
  float ref_alt;
  /// Distance to surface
  /// Distance from from bottom surface to ground, (metres)
  float dist_bottom;
  /// true if distance to bottom surface is valid
  bool dist_bottom_valid;
  /// bitfield indicating what type of sensor is used to estimate dist_bottom
  uint8_t dist_bottom_sensor_bitfield;
  /// Standard deviation of horizontal position error, (metres)
  float eph;
  /// Standard deviation of vertical position error, (metres)
  float epv;
  /// Standard deviation of horizontal velocity error, (metres/sec)
  float evh;
  /// Standard deviation of vertical velocity error, (metres/sec)
  float evv;
  /// True if this position is estimated through dead-reckoning
  bool dead_reckoning;
  /// estimator specified vehicle limits
  /// maximum horizontal speed - set to 0 when limiting not required (meters/sec)
  float vxy_max;
  /// maximum vertical speed - set to 0 when limiting not required (meters/sec)
  float vz_max;
  /// minimum height above ground level - set to 0 when limiting not required (meters)
  float hagl_min;
  /// maximum height above ground level - set to 0 when limiting not required (meters)
  float hagl_max;
} px4_msgs__msg__VehicleLocalPosition;

// Struct for a sequence of px4_msgs__msg__VehicleLocalPosition.
typedef struct px4_msgs__msg__VehicleLocalPosition__Sequence
{
  px4_msgs__msg__VehicleLocalPosition * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} px4_msgs__msg__VehicleLocalPosition__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PX4_MSGS__MSG__DETAIL__VEHICLE_LOCAL_POSITION__STRUCT_H_
