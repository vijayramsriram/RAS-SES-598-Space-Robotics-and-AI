# State Estimation Assignment

Implement and compare two fundamental state estimation techniques: Kalman Filter and Particle Filter.

## Prerequisites

- ROS2 Humble
- Python 3.8+
- NumPy

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

## Assignment Tasks

### 1a. Kalman Filter Implementation (50 points)

Complete the TODOs in `kalman_filter.py`:

1. State Prediction (15 points)
   ```python
   def predict(self, dt, velocity, angular_velocity):
       """
       TODO: Implement the prediction step
       State: [x, y, theta]
       Input: [v, w]
       
       Motion model:
       x' = x + v*cos(theta)*dt
       y' = y + v*sin(theta)*dt
       theta' = theta + w*dt
       """
   ```

2. Measurement Updates (35 points)
   ```python
   def update_gps(self, gps_measurement):
       """
       TODO: Implement GPS measurement update
       Measurement: [x, y]
       """

   def update_imu(self, imu_measurement):
       """
       TODO: Implement IMU measurement update
       Measurement: [theta]
       """
   ```

### 1b. Particle Filter Implementation (50 points)

Complete the TODOs in `particle_filter.py`:

1. Particle Prediction (15 points)
   ```python
   def predict(self, dt, velocity, angular_velocity):
       """
       TODO: Implement particle prediction
       Each particle: [x, y, theta, weight]
       """
   ```

2. Measurement Update (20 points)
   ```python
   def update(self, gps_measurement, imu_measurement):
       """
       TODO: Implement measurement update and weight calculation
       """
   ```

3. Resampling (15 points)
   ```python
   def resample(self):
       """
       TODO: Implement systematic resampling
       """
   ```

## Testing Your Implementation

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

## Submission

1. Fork this repository
2. Complete the implementations
3. Create a README in your repository documenting:
   - Your approach
   - Parameter choices
   - Results analysis
   - Comparison between KF and PF

## Evaluation (100 points)

- Correct implementation (60 points)
  - Kalman Filter (30 points)
  - Particle Filter (30 points)
- Code quality (20 points)
  - Documentation
  - Style guidelines
  - Readability
- Results and analysis (20 points)
  - Parameter tuning
  - Performance comparison
  - Implementation insights

Deadline: January 21, 2025
