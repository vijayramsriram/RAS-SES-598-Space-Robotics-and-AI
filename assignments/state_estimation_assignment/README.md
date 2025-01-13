# State Estimation Assignment

This assignment focuses on implementing and comparing two fundamental state estimation techniques in robotics using ROS2. You will develop both a Kalman Filter and a Particle Filter to estimate a robot's state using simulated GPS and IMU measurements.

## Learning Objectives

By completing this assignment, you will:
- Implement and understand core state estimation algorithms
- Gain practical experience with ROS2 and sensor fusion
- Learn to analyze and tune filter parameters
- Develop skills in comparing different estimation approaches

## Prerequisites

- ROS2 Humble
- Python 3.8+
- NumPy
- Basic understanding of:
  - State estimation concepts
  - Probability theory
  - Linear algebra
  - ROS2 topics and nodes

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
colcon build --packages-select state_estimation_assignment
```

4. Source the workspace:
```bash
source ~/ros2_ws/install/setup.bash
```

## Assignment Structure

The assignment is divided into two parts:

### Assignment 1a: Kalman Filter Implementation (50 points)

Implement a Kalman filter to estimate the 2D pose (x, y, θ) of a differential drive robot.

#### Tasks

1. State Prediction (15 points)
   - Implement the motion model in `kalman_filter.py`
   - Update state mean using velocity and angular velocity
   - Propagate state covariance with process noise

2. Measurement Updates (20 points)
   - Implement GPS measurement update (position measurements)
   - Implement IMU measurement update (orientation measurements)
   - Calculate appropriate Kalman gains

3. Parameter Tuning (15 points)
   - Tune process noise covariance Q
   - Tune measurement noise covariance R
   - Document your tuning process and reasoning

#### Implementation Details

The `kalman_filter.py` file contains the following structure:
```python
def predict(self, dt, velocity, angular_velocity):
    """
    TODO: Implement the prediction step
    State: [x, y, theta]
    Input: [v, w]
    """
    pass

def update_gps(self, gps_measurement):
    """
    TODO: Implement GPS measurement update
    Measurement: [x, y]
    """
    pass

def update_imu(self, imu_measurement):
    """
    TODO: Implement IMU measurement update
    Measurement: [theta]
    """
    pass
```

### Assignment 1b: Particle Filter Implementation (50 points)

Implement a particle filter for the same robot state estimation problem.

#### Tasks

1. Particle Prediction (15 points)
   - Implement particle motion model
   - Add appropriate process noise
   - Handle particle state representation

2. Measurement Updates (20 points)
   - Implement measurement likelihood functions
   - Update particle weights
   - Normalize weights properly

3. Resampling (15 points)
   - Implement systematic resampling
   - Calculate effective sample size
   - Implement resampling threshold logic

#### Implementation Details

The `particle_filter.py` file contains:
```python
def predict(self, dt, velocity, angular_velocity):
    """
    TODO: Implement particle prediction
    Each particle: [x, y, theta, weight]
    """
    pass

def update(self, gps_measurement, imu_measurement):
    """
    TODO: Implement measurement update and weight calculation
    """
    pass

def resample(self):
    """
    TODO: Implement systematic resampling when needed
    """
    pass
```

### Running and Testing

1. Launch the simulation:
```bash
ros2 launch state_estimation_assignment state_estimation.launch.py
```

2. Visualize results:
```bash
ros2 run rqt_plot rqt_plot
```

Add these topics to plot:
- `/ground_truth/pose/pose/position/x`
- `/estimated_state/pose/pose/position/x`
- `/gps/pose/position/x`

For particle filter visualization:
```bash
ros2 run rviz2 rviz2
```

## Deliverables and Grading

Submit the following:

1. Code Implementation (60%)
   - Completed `kalman_filter.py` (30%)
   - Completed `particle_filter.py` (30%)
   - Code must be well-documented and follow Python style guidelines

2. Technical Report (40%)
   - Implementation description (10%)
   - Parameter tuning methodology (10%)
   - Performance analysis (10%)
   - Comparison of both filters (10%)

### Report Requirements

Your report should include:

1. Algorithm Implementation
   - Detailed description of your implementation
   - Key design decisions and assumptions
   - Mathematical formulation

2. Parameter Tuning
   - Description of tuning process
   - Final parameter values with justification
   - Analysis of parameter sensitivity

3. Results Analysis
   - Quantitative comparison of estimation accuracy
   - Plots showing:
     - True vs. estimated trajectories
     - Error analysis over time
     - Filter convergence behavior
   - Performance comparison between KF and PF

4. Discussion
   - Strengths and weaknesses of each approach
   - Challenges encountered and solutions
   - Potential improvements

## Evaluation Criteria

Your submission will be evaluated out of 100 points based on:

1. Correctness of implementation (30%)
2. Code quality and documentation (20%)
3. Parameter tuning and justification (20%)
4. Analysis depth and insights (30%)

## Resources

- ROS2 Documentation: https://docs.ros.org/en/humble/
- Probabilistic Robotics (Thrun, Burgard, Fox)
- Course lecture notes
- Example datasets for testing

## Submission Instructions

1. Push your code to your own repository
2. Submit your report as a PDF via the course Canvas platform, include link to your repository
3. Include any additional scripts or data used in your analysis in your repository. 

Deadline: January 21, 2025
