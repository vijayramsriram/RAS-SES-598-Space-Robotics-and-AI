# Assignment 3: Rocky Times Challenge - Search, Map, & Analyze report

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
![image](https://github.com/user-attachments/assets/f9866ac7-b4ae-41d3-809d-376478380aa2)

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

🏁 **Final Result**
![image](https://github.com/user-attachments/assets/baf82ba8-ec47-4e64-b993-63ecf235087a)


