# First-Order Boustrophedon Navigator
![image](https://github.com/user-attachments/assets/940fc6bc-fcee-4d11-8bc8-d53a650aaf80)

## Abstract
In this assignment, I have tuned the provided code in ROS2 with Turtlesim, and refactor for the navigator to implement a precise lawnmower survey (a boustrophedon pattern) for the given critera.The goal was to minimize the cross-track error while maintaining smooth motion.

## Learning Outcomes
- Understanding PD control parameters and their effects on first-order systems
- Practical experience with controller tuning
- Analysis of trajectory tracking performance
- ROS2 visualization and debugging

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
Optimize the boustrophedon pattern parameters:
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

### Building and Running
1. Build the package:
```bash
cd ~/ros2_ws
colcon build --packages-select first_order_boustrophedon_navigator
source install/setup.bash
```

2. Launch the demo:
```bash
ros2 launch first_order_boustrophedon_navigator boustrophedon.launch.py
```

3. Monitor performance:
```bash
# View cross-track error as a number
ros2 topic echo /cross_track_error

# Or view detailed statistics in the launch terminal
```

4. Visualize trajectory and performance:
```bash
ros2 run rqt_plot rqt_plot
```
Add these topics:
- /turtle1/pose/x
- /turtle1/pose/y
- /turtle1/cmd_vel/linear/x
- /turtle1/cmd_vel/angular/z
- /cross_track_error

## Analysis
### Control Parameters
- **Linear Velocity Control**:<br>
kp_linear (Linear Proportional Gain): Determines how aggressively the robot moves toward the waypoint based on the distance error.<br>
kd_linear (Linear Derivative Gain): Adds damping to prevent overshoot in linear motion.<br>
*Adjustments:*
  * kp_linear:
    - **Increase** if the robot is too sluggish.
    - **Decrease** if the robot overshoots or oscillates.
  * kd_linear:
    - **Increase** if the robot oscillates too much.
    - **Decrease** if the robot reacts too slowly.
- **Angular Velocity Control**:<br>
kp_angular (Angular Proportional Gain): Determines how quickly the robot corrects its heading toward the waypoint.<br>
kd_angular (Angular Derivative Gain): Adds damping to angular adjustments, preventing over-correction in turns.<br>
*Adjustments:*
  * kp_angular:
    - **Increase** if the robot is too slow to align with the path.
    - **Decrease** if the robot turns too sharply or oscillates.
  * kd_angular:
    - **Increase** if the robot overshoots while turning.
    - **Decrease** if it’s too sluggish in aligning.
- **Waypoint Spacing**:<br>
Determines the distance between consecutive rows in the lawnmower pattern.<br>
*Adjustments:*
    - **Increase** if the robot struggles to make sharp turns between rows.
    - **Decrease** to cover the area more thoroughly with minimal overlap.
- **Velocity Limits**:<br>
Linear Velocity (linear.x): The maximum speed of forward motion.<br>
Angular Velocity (angular.z): The maximum rate of turning.<br>

## Final Parameter Values

### 1. Controller Performance
   - Average cross-track error =
   - Maximum cross-track error =

### 2. Pattern Quality
   - Even spacing between lines
   - Complete coverage of target area
   - Efficient use of space

3. Documentation (20%)
   - Clear explanation of tuning process
   - Well-presented performance metrics
   - Thoughtful analysis of results

## Submission Requirements

1. GitHub Repository:
   - Commit messages should be descriptive

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

## Grading Rubric
- Perfect tracking (cross-track error < 0.2 units): 100%
- Good tracking (cross-track error < 0.5 units): 90%
- Acceptable tracking (cross-track error < 0.8 units): 80%
- Poor tracking (cross-track error > 0.8 units): 60% or lower

Note: Final grade will also consider documentation quality and analysis depth.

## Extra Credit (10 points)
Create and implement a custom ROS2 message type to publish detailed performance metrics:
- Define a custom message type with fields for:
  - Cross-track error
  - Current velocity
  - Distance to next waypoint
  - Completion percentage
  - Other relevant metrics
- Implement the message publisher in your node
- Document the message structure and usage

This will demonstrate understanding of:
- ROS2 message definitions
- Custom interface creation
- Message publishing patterns 
