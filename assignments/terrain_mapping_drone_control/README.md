# Autonomous Drone Takeoff and ArUco Landing

This ROS 2 package implements a basic autonomous drone mission using PX4 SITL and Gazebo.  
It performs:
- Smooth Takeoff and Hover
- ArUco Marker Detection
- Autonomous Landing based on vision

---

## 📋 Overview

In this project, I developed **two ROS 2 nodes** to achieve an autonomous drone operation:

| Node | Description |
|:-----|:------------|
| `takeoff_and_hover.py` | Commands the drone to arm, switch to OFFBOARD mode, takeoff vertically to a desired altitude, and hover |
| `aruco_landing.py` | Detects an ArUco marker using the onboard camera, aligns the drone over the marker, and commands landing when centered |

---

## 🛠️ Nodes Developed

### 1. `takeoff_and_hover.py`

- Arms the drone automatically.
- Switches to OFFBOARD control mode.
- Smoothly commands the drone to takeoff to **15 meters** altitude.
- Maintains stable hover position after reaching the target height.
- Publishes setpoints to `/fmu/in/trajectory_setpoint`.

### 2. `aruco_landing.py`

- Subscribes to camera images (`/rgb_camera`).
- Detects **ArUco markers** using OpenCV.
- Computes pixel errors between marker center and image center.
- Publishes velocity corrections (`/cmd_vel`) to align the drone over the marker.
- Initiates autonomous **LAND** command once centered above the ArUco within a threshold.

---

## 🧠 Workflow to Launch the System

1. **Start Gazebo simulation:**
```bash
ros2 launch terrain_mapping_drone_control cylinder_landing.launch.py
```
This will:

-Start Gazebo simulation
-Load arena environment
-Spawn cylinder object with attached ArUco marker

2. **Start the Micro XRCE Agent for PX4:**

```bash
MicroXRCEAgent udp4 -p 8888
```
3. **Run the Takeoff Node:**

```bash
ros2 run terrain_mapping_drone_control takeoff_and_hover.py
```
This will:
-Arm the drone
-Engage OFFBOARD mode
-Smoothly takeoff to 15 meters
-Hover stably at the target altitude

4. **Run the ArUco Landing Node:**

```bash
ros2 run terrain_mapping_drone_control aruco_landing.py
```
This will:
-Start detecting ArUco markers using onboard camera
-Align the drone over the marker using velocity control
-Command the drone to LAND once centered over the marker

🏁 Final Result


