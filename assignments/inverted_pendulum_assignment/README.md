# Assignment 2: Inverted Pendulum Stabilization

Implement a controller to stabilize an inverted pendulum using ROS2.

## Prerequisites

- ROS2 Humble
- Python 3.8+
- NumPy
- Control systems understanding

## Installation

1. Clone this repository into your ROS2 workspace:
```bash
cd ~/ros2_ws/src
git clone <repository_url>
```

2. Install dependencies:
```bash
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
```

3. Build the package:
```bash
colcon build --packages-select inverted_pendulum_assignment
```

4. Source the workspace:
```bash
source ~/ros2_ws/install/setup.bash
```

## Assignment Tasks

### 1. System Model Implementation (20 points)

Complete the TODOs in `pendulum_model.py`:

```python
def update_state(self, state, control_input, dt):
    """
    TODO: Implement pendulum dynamics
    State: [x, x_dot, theta, theta_dot]
    Input: [force]
    
    Dynamic model:
    x_ddot = (force - m*l*theta_ddot*cos(theta) + m*l*theta_dot^2*sin(theta)) / (M + m)
    theta_ddot = (g*sin(theta) - x_ddot*cos(theta)) / l
    """
```

### 2. Controller Implementation (50 points)

Complete the TODOs in `pendulum_controller.py`:

1. State Feedback Control (30 points)
```python
def compute_control(self, state):
    """
    TODO: Implement LQR controller
    Compute control input u = -K*x
    """
```

2. State Estimation (20 points)
```python
def estimate_state(self, measurements):
    """
    TODO: Implement state observer
    Update state estimate using sensor measurements
    """
```

### 3. Safety Features (30 points)

Implement safety checks in `safety_monitor.py`:

```python
def check_safety_constraints(self, state, control):
    """
    TODO: Implement safety checks
    - Position limits
    - Velocity limits
    - Control input saturation
    - Emergency stop conditions
    """
```

## Testing Your Implementation

1. Launch the simulation:
```bash
ros2 launch inverted_pendulum_assignment pendulum.launch.py
```

2. Visualize results:
```bash
ros2 run rqt_plot rqt_plot
```

Add these topics to plot:
- `/pendulum/state/theta`
- `/pendulum/state/x`
- `/pendulum/control/force`

## Submission

1. Fork this repository
2. Complete the implementations
3. Create a README in your repository documenting:
   - Control design approach
   - Tuning methodology
   - Performance analysis

## Evaluation (100 points)

- Correct implementation (60 points)
  - System model (20 points)
  - Controller (30 points)
  - Safety features (10 points)
- Code quality (20 points)
  - Documentation
  - Style guidelines
  - Readability
- Results and analysis (20 points)
  - Controller performance
  - Safety verification
  - Implementation insights

Deadline: January 28, 2025 
