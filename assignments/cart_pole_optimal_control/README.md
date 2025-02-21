# Cart-Pole Optimal Control Assignment

![image](https://github.com/user-attachments/assets/c8591475-3676-4cdf-8b4a-6539e5a2325f)

## Overview
This assignment challenges students to tune and analyze an LQR controller for a cart-pole system subject to earthquake disturbances. The goal is to maintain the pole's stability while keeping the cart within its physical constraints under external perturbations. The earthquake force generator in this assignment introduces students to simulating and controlling systems under seismic disturbances, which connects to the Virtual Shake Robot covered later in the course. The skills developed here in handling dynamic disturbances and maintaining system stability will be useful for optimal control of space robots, such as Lunar landers or orbital debris removal robots.

## System Description
The assignment is based on the problem formalism here: https://underactuated.mit.edu/acrobot.html#cart_pole
### Physical Setup
- Inverted pendulum mounted on a cart
- Cart traversal range: ±2.5m (total range: 5m)
- Pole length: 1m
- Cart mass: 1.0 kg
- Pole mass: 1.0 kg

### Disturbance Generator
The system includes an earthquake force generator that introduces external disturbances:
- Generates continuous, earthquake-like forces using superposition of sine waves
- Base amplitude: 15.0N (default setting)
- Frequency range: 0.5-4.0 Hz (default setting)
- Random variations in amplitude and phase
- Additional Gaussian noise

---
### Controller Description
The package includes a complete LQR controller implementation (`lqr_controller.py`) with the following features:
- State feedback control
- Configurable Q and R matrices
- Real-time force command generation
- State estimation and processing

Current default parameters:
```python
# State cost matrix Q (default values)
Q = np.diag([1.0, 1.0, 10.0, 10.0])  # [x, x_dot, theta, theta_dot]

# Control cost R (default value)
R = np.array([[0.1]])  # Control effort cost
```

### Earthquake Disturbance
The earthquake generator (`earthquake_force_generator.py`) provides realistic disturbances:
- Configurable through ROS2 parameters
- Default settings:
  ```python
  parameters=[{
      'base_amplitude': 15.0,    # Strong force amplitude (N)
      'frequency_range': [0.5, 4.0],  # Wide frequency range (Hz)
      'update_rate': 50.0  # Update rate (Hz)
  }]
  ```

# **Effects of Parameter Changes in the Cart-Pole LQR Controller**
---
## **Changing LQR Cost Matrices (`Q` and `R`)**

### **a) Changing `Q` (State Cost Matrix)**  
- **Increasing `Q[0,0]` (penalizing cart position more)**  
  - The system keeps the cart near the center.
  - May lead to stronger corrections and oscillations.

- **Increasing `Q[2,2]` (penalizing pole angle more)**  
  - Prioritizes keeping the pole upright.
  - May cause larger cart movements.

- **Increasing all diagonal values**  
  - The controller becomes **aggressive**, reducing errors.
  - High values may lead to **instability**.

- **Decreasing `Q` values**  
  - The controller becomes **more relaxed**, leading to **smoother but slower** stabilization.

---

### **b) Changing `R` (Control Cost Matrix)**  
- **Increasing `R` (penalizing control force more)**  
  - The controller applies **smaller forces**.
  - The system is **more stable but slower**.
  - If too high, the controller may **fail to balance** the pole.

- **Decreasing `R` (allowing larger control forces)**  
  - The controller applies **stronger forces**.
  - The system stabilizes **faster** but may **oscillate more**.
  - **Increases energy consumption**.

---
### Performance Metrics
---
## Final Parameter Values (Analysis)
|  Iteration no.  | Q values | R value |
|-------------|-------------|-------------|
|      1      | [1.0, 1.0, 10.0, 10.0]      | [0.1] |

https://github.com/user-attachments/assets/4313e80e-10ae-46d3-93ca-fceafa46113c

<br>

|  Iteration no. | Q values | R value |
|-------------|-------------|-------------|
|      2      | [2.0, 5.0, 20.0, 30.0]      | [0.4] |

https://github.com/user-attachments/assets/16a96183-7fb1-44dc-aea7-76a49998984c

<br>

|  Iteration no. | Q values | R value |
|-------------|-------------|-------------|
|      3      | [6.0, 7.0, 10.0, 10.0]      | [0.15]|


https://github.com/user-attachments/assets/d98e3995-0b2c-4484-aa24-d449905045b6

<br>

|  Iteration no. | Q values | R value |
|-------------|-------------|-------------|
|      4      | [6.0, 7.0, 5.0, 10.0]      | [0.2] |

https://github.com/user-attachments/assets/1f233238-dd33-4e8c-96b1-f93ba1dc7b5b

<br>

|  Iteration no. | Q values | R value |
|-------------|-------------|-------------|
|      5      | [6.0, 7.0, 5.0, 4.0]       | [0.05]|


https://github.com/user-attachments/assets/7d00e0c4-e647-4265-aca8-4fce5c885ec8

<br>

---
### Building and Running
```bash
# Build the package
cd ~/ros2_ws
colcon build --packages-select cart_pole_optimal_control --symlink-install

# Source the workspace
source install/setup.bash

# Launch the simulation with visualization
ros2 launch cart_pole_optimal_control cart_pole_rviz.launch.py
```
#### Force Arrows
Two types of forces are visualized:
1. Control Forces (at cart level):
   - Red arrows: Positive control force (right)
   - Blue arrows: Negative control force (left)

2. Earthquake Disturbances (above cart):
   - Orange arrows: Positive disturbance (right)
   - Purple arrows: Negative disturbance (left)

Arrow lengths are proportional to force magnitudes.

### **Conclusion**

The **Cart-Pole LQR Controller** effectively demonstrates how Linear Quadratic Regulator (LQR) control can stabilize an inherently unstable system. By continuously estimating the system state and applying optimal control forces, the controller ensures the pole remains upright while minimizing unnecessary cart movement.

This implementation highlights key aspects of control engineering, such as:

- The impact of **system parameters** (mass, length, gravity) on dynamics.
- The role of **LQR cost matrices** in balancing precision and control effort.
- The importance of **timing and frequency** in real-time control.
- The ability to **track disturbances and recovery** for robust performance.

By tuning these parameters appropriately, this controller can be adapted to different cart-pole setups or extended to more complex robotic systems. Future improvements could include adaptive control, reinforcement learning-based policies, or model predictive control (MPC) for enhanced robustness. 🚀


## License
This work is licensed under a [Creative Commons Attribution 4.0 International License](http://creativecommons.org/licenses/by/4.0/).
[![Creative Commons License](https://i.creativecommons.org/l/by/4.0/88x31.png)](http://creativecommons.org/licenses/by/4.0/) 
