# Assignment: Turtlesim Lawnmower Pattern Control

## Objective
Tune a PD controller to make a turtle execute the most precise lawnmower pattern possible in the turtlesim environment. The goal is to minimize the cross-track error while maintaining smooth motion.

## Learning Outcomes
- Understanding PD control parameters and their effects
- Practical experience with controller tuning
- Analysis of trajectory tracking performance
- ROS2 visualization and debugging

## Prerequisites

### System Requirements
Choose one of the following combinations:
- Ubuntu 22.04 + ROS2 Humble
- Ubuntu 23.04 + ROS2 Iron
- Ubuntu 23.10 + ROS2 Iron
- Ubuntu 24.04 + ROS2 Jazzy (when released)

### Required Packages
- Python 3.8+ (for Ubuntu 22.04) or Python 3.10+ (for Ubuntu 23.04+)
- ROS2 base installation
- Additional ROS2 packages:
  ```bash
  sudo apt install ros-$ROS_DISTRO-turtlesim
  sudo apt install ros-$ROS_DISTRO-rqt*
  ```

### Python Dependencies
```bash
pip3 install numpy matplotlib
```

## The Challenge

### 1. Controller Tuning (60 points)
Use rqt_reconfigure to tune the following PD controller parameters in real-time:
```python
# Controller parameters to tune
self.Kp_linear = 1.0   # Proportional gain for linear velocity
self.Kd_linear = 0.1   # Derivative gain for linear velocity
self.Kp_angular = 1.0  # Proportional gain for angular velocity
self.Kd_angular = 0.1  # Derivative gain for angular velocity
```

Performance Metrics:
- Average cross-track error (25 points)
- Maximum cross-track error (15 points)
- Smoothness of motion (10 points)
- Cornering performance (10 points)

### 2. Pattern Parameters (20 points)
Optimize the lawnmower pattern parameters:
```python
# Pattern parameters to tune
self.spacing = 1.0     # Spacing between lines
```
- Coverage efficiency (10 points)
- Pattern completeness (10 points)

### 3. Analysis and Documentation (20 points)
Provide a detailed analysis of your tuning process:
- Methodology used for tuning
- Performance plots and metrics
- Challenges encountered and solutions
- Comparison of different parameter sets

## Getting Started

### Repository Setup
1. Fork the repository:
   - Visit: https://github.com/robomechanics/turtlesim_survey_demo
   - Click "Fork" in the top-right corner
   - Select your GitHub account as the destination

2. Clone your fork:
```bash
cd ~/ros2_ws/src
git clone https://github.com/YOUR_USERNAME/turtlesim_survey_demo.git
```

3. Set up upstream remote (for future updates):
```bash
cd turtlesim_survey_demo
git remote add upstream https://github.com/robomechanics/turtlesim_survey_demo.git
```

### Building and Running
1. Build the package:
```bash
cd ~/ros2_ws
colcon build --packages-select turtlesim_survey_demo
source install/setup.bash
```

2. Launch the demo:
```bash
ros2 launch turtlesim_survey_demo survey_demo.launch.py
```

3. Monitor performance:
```bash
ros2 topic echo /lawnmower_controller/cross_track_error
```

4. Visualize trajectory:
```bash
ros2 run rqt_plot rqt_plot
```
Add these topics:
- /turtle1/pose/x
- /turtle1/pose/y

## Evaluation Criteria

1. Controller Performance (60%)
   - Average cross-track error < 0.1m (25%)
   - Maximum cross-track error < 0.2m (15%)
   - Smooth velocity profiles (10%)
   - Clean cornering behavior (10%)

2. Pattern Quality (20%)
   - Even spacing between lines
   - Complete coverage of target area
   - Efficient use of space

3. Documentation (20%)
   - Clear explanation of tuning process
   - Well-presented performance metrics
   - Thoughtful analysis of results

## Submission Requirements

1. GitHub Repository:
   - Your fork should be public and contain all code changes
   - Commit messages should be descriptive
   - Include a clear version history of your tuning process

2. Documentation in Repository:
   - Update the README.md in your fork with:
     - Final parameter values with justification
     - Performance metrics and analysis
     - Plots showing:
       - Cross-track error over time
       - Trajectory plot
       - Velocity profiles
     - Discussion of tuning methodology
     - Challenges and solutions

3. Submit your work:
   - Submit the URL of your GitHub repository
   - Ensure your repository is public
   - Final commit should be before the deadline

## Tips for Success
- Start with low gains and increase gradually
- Test one parameter at a time
- Pay attention to both straight-line tracking and cornering
- Use rqt_plot to visualize performance in real-time
- Consider the trade-off between speed and accuracy

## Deadline
Submit your tuned implementation by February 1, 2025

## Grading Rubric
- Perfect tracking (cross-track error < 0.05m): 100%
- Good tracking (cross-track error < 0.1m): 90%
- Acceptable tracking (cross-track error < 0.2m): 80%
- Poor tracking (cross-track error > 0.2m): 60% or lower

Note: Final grade will also consider documentation quality and analysis depth. 