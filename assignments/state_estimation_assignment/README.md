# State Estimation Assignments

This package contains two parts of Assignment 1 focused on state estimation techniques using ROS2:

1a. Kalman Filter Implementation
1b. Particle Filter Implementation

## Prerequisites

- ROS2 Humble
- Python 3.8+
- NumPy
- Basic understanding of state estimation concepts

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

## Assignment 1a: Kalman Filter

In this assignment, you will implement a Kalman filter to estimate the state of a robot using GPS and IMU measurements.

### Tasks

1. Complete the prediction step in `kalman_filter.py`:
   - Implement state prediction using the motion model
   - Implement covariance prediction

2. Complete the update steps:
   - Implement GPS measurement update
   - Implement IMU measurement update
   - Tune the noise parameters Q and R

### Running the Code

```bash
ros2 launch state_estimation_assignment state_estimation.launch.py
```

To visualize the results:
```bash
ros2 run rqt_plot rqt_plot
```

Add these topics to plot:
- `/ground_truth/pose/pose/position/x`
- `/estimated_state/pose/pose/position/x`
- `/gps/pose/position/x`

## Assignment 1b: Particle Filter

In this assignment, you will implement a particle filter for state estimation.

### Tasks

1. Complete the prediction step in `particle_filter.py`:
   - Implement particle motion model
   - Add appropriate process noise

2. Complete the measurement update steps:
   - Implement GPS measurement likelihood
   - Implement IMU measurement likelihood
   - Update particle weights

3. Implement the resampling step:
   - Calculate effective sample size
   - Implement resampling when needed

### Running the Code

```bash
ros2 launch state_estimation_assignment state_estimation.launch.py
```

To visualize the particles:
```bash
ros2 run rviz2 rviz2
```

Add these displays:
- MarkerArray (topic: `/particles`)
- Odometry (topics: `/ground_truth`, `/estimated_state`)

## Evaluation

Your implementation will be evaluated based on:

1. Accuracy of state estimation
2. Code quality and documentation
3. Parameter tuning and justification
4. Analysis of results

## Submission

Submit your completed implementation along with a report that includes:

1. Description of your implementation
2. Explanation of parameter tuning
3. Analysis of results (plots comparing true vs. estimated states)
4. Discussion of challenges and solutions

## Resources

- ROS2 Documentation: https://docs.ros.org/en/humble/