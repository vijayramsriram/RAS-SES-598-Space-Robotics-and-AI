# Assignment 3: Rocky Times Challenge - Search, Map, & Analyze report

This ROS 2 package implements a basic autonomous drone mission using PX4 SITL and Gazebo.  
It performs:
- Smooth Takeoff and Hover
- ArUco Marker Detection
- Autonomous Landing based on vision

---

## 🛠️ Developed ROS 2 Nodes

In this project, I developed **four ROS 2 nodes** to achieve a fully autonomous drone operation:

| Node | Description |
|:-----|:------------|
| `takeoff_and_hover.py` | Commands the drone to arm, switch to OFFBOARD mode, takeoff vertically to a desired altitude, and hover |
| `aruco_landing.py` | Detects an ArUco marker using the onboard camera, aligns the drone over the marker, and commands landing when centered |
| `dimension_estimator.py` | Detects the ArUco marker and estimates its distance from the drone using the pinhole camera model and known marker size |
| `energy_logger.py` | Tracks the drone’s position in 3D space, calculates total distance traveled, and estimates energy consumption in real time |

---

## 🛠️ NOTE
 I have changed the px4 x500_depth cameras orientation to face down for my code to work.

![image](https://github.com/user-attachments/assets/5db78375-8d41-4a06-97c1-fc9f4ef10dc0)


# 📏 Dimension Estimator Node (`dimension_estimator.py`)

---
The `dimension_estimator.py` node is designed to estimate the distance between the drone and the ArUco marker in the scene.

It uses:

- Camera image feed (`/rgb_camera`)
- OpenCV ArUco detection
- Pinhole camera model equations

to estimate **marker distance** and **approximate cylinder dimensions**.

✅ Real-time distance calculation from marker pixel size.

---

| Step | Description |
|:-----|:------------|
| 1 | Subscribe to camera images `/rgb_camera` |
| 2 | Detect ArUco markers using OpenCV |
| 3 | Calculate average **pixel width** of detected marker |
| 4 | Use known camera **focal length** and **marker size** to estimate distance |
| 5 | Print/log estimated distance to the marker |

---

## 📐 Important Parameters

| Parameter | Value | Description |
|:----------|:------|:------------|
| `marker_real_size` | `0.2` meters | Real-world size of the ArUco marker |
| `fx` | `554.0` pixels | Camera focal length (assumed) |

---

## 📈 Distance Estimation Formula

The distance is estimated using the **pinhole camera model**:

\[
\text{Distance} = \frac{f_x \times \text{Marker Real Size}}{\text{Marker Pixel Width}}
\]

where:
- \( f_x \) = focal length in pixels
- Marker Real Size = known physical size of the marker
- Marker Pixel Width = width of the detected marker in pixels

## Output
![image](https://github.com/user-attachments/assets/64792be6-cef8-49f2-86e2-868df13e5567)

---

# ⚡ Energy Logger Node (`energy_logger.py`)

---

## 📋 Overview

The `energy_logger.py` node monitors the drone’s motion by subscribing to its odometry data.  
It continuously tracks the total distance traveled and estimates the energy consumed during flight.
  
✅ Real-time  

---
| Step | Description |
|:-----|:------------|
| 1 | Subscribes to PX4 odometry data: `/fmu/out/vehicle_odometry` |
| 2 | Records 3D position `(x, y, z)` at each update |
| 3 | Calculates distance traveled between frames |
| 4 | Integrates total distance |
| 5 | Logs estimated **energy usage**, assuming 1 unit per meter |

---
## 🔧 QoS Configuration

To receive PX4 odometry correctly, this node uses:

- **Best Effort** QoS (matching PX4’s publisher)
- Depth = 10

python
from rclpy.qos import QoSProfile, QoSReliabilityPolicy

qos_profile = QoSProfile(
    reliability=QoSReliabilityPolicy.BEST_EFFORT,
    depth=10
)
Avoids QoS mismatch warnings and ensures message reception.

![image](https://github.com/user-attachments/assets/954350cd-a707-4dbb-852f-e1ab16b4d66f)


## 🛠️ Nodes Developed

### 1. `takeoff_and_hover.py`

- Arms the drone automatically.
- Switches to **OFFBOARD** control mode.
- Smoothly commands the drone to takeoff to **15 meters** altitude.
- Maintains stable **hover** position after reaching the target height.
- Publishes trajectory setpoints to `/fmu/in/trajectory_setpoint`.

---

### 2. `aruco_landing.py`

- Subscribes to camera images via the topic `/rgb_camera`.
- Detects **ArUco markers** in real-time using **OpenCV**.
- Computes **pixel error** between the marker center and image center.
- Publishes velocity corrections to `/cmd_vel` to align drone with marker.
- Commands an autonomous **LAND** when the drone is centered above the marker.

---

### 3. `dimension_estimator.py`

- Subscribes to the same camera topic (`/rgb_camera`) to detect ArUco markers.
- Measures the **pixel width** of the marker in the image.
- Uses a known marker size and **pinhole camera model** to estimate distance.
- Logs estimated distance to the marker in meters.
- Helps in approximating **cylinder height or position accuracy**.

---

### 4. `energy_logger.py`

- Subscribes to `/fmu/out/vehicle_odometry` to access the drone’s live position.
- Tracks the drone’s motion in **3D space**.
- Computes total **distance traveled** using Euclidean distance between waypoints.
- Estimates **energy usage** assuming 1 unit per meter.
- Logs both distance and energy at regular intervals (every 5 seconds).


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


## 🛠️ NOTE
run the aruco_landing node after the drone sees the aruco marker.
4. **Run the aruco_landing Node:**

```bash
ros2 run terrain_mapping_drone_control aruco_landing.py
```
This will:
-Start detecting ArUco markers using onboard camera
-Align the drone over the marker using velocity control
-Command the drone to LAND once centered over the marker

5. **Run the Dimension_estimator Node:**

```bash
ros2 run terrain_mapping_drone_control dimension_estimator.py
```

## 🛠️ NOTE
run the energy logger node after the drone arms and lifts a little.
6. **Run the energy_logger Node:**

```bash
ros2 run terrain_mapping_drone_control energy_logger.py
```

 

🏁 **Final Result**
![image](https://github.com/user-attachments/assets/baf82ba8-ec47-4e64-b993-63ecf235087a)


