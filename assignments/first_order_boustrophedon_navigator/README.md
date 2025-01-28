# First-Order Boustrophedon Navigator
![image](https://github.com/user-attachments/assets/940fc6bc-fcee-4d11-8bc8-d53a650aaf80)

## Abstract
In this assignment, I have tuned the provided code in ROS2 with Turtlesim, and refactor for the navigator to implement a precise lawnmower survey (a boustrophedon pattern) for the given critera.The goal was to minimize the cross-track error while maintaining smooth motion.

## Learning Outcomes
- Understanding PD control parameters and their effects on first-order systems
- Practical experience with controller tuning
- Analysis of trajectory tracking performance
- ROS2 visualization and debugging

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
|  Iterations  | `kp_linear` | `kd_linear` | `kp_angular` | `kd_angular` | Spacing | Avg Cross-Track Error |
|-------------|-------------|-------------|--------------|--------------|---------|-----------------------|
|      1      | 9.0         | 0.06        | 7.8          | 0.018        | 0.6     | 0.094                 |
|      2      | 9.0         | 0.06        | 7.7          | 0.018        | 0.5     | 0.098                 |
|      3      | 9.0         | 0.06        | 7.6          | 0.019        | 0.4     | 0.104                 |
|      4      | 9.0         | 0.065       | 8.7          | 0.018        | 0.3     | 0.078                 |
|      5      | 8.4         | 0.065       | 8.2          | 0.022        | 0.3     | 0.101                 |
|      6      | 8.4         | 0.07        | 8.0          | 0.025        | 0.3     | 0.095                 |
|      7      | 8.2         | 0.07        | 7.9          | 0.028        | 0.3     | 0.089                 |
|      8      | 8.0         | 0.07        | 8.0          | 0.034        | 0.3     | 0.098                 |

## Outputs

### Iterations 1 to 8 
<div style="max-width: 100%; overflow-x: auto; white-space: nowrap; padding: 10px;">

  <div style="display: inline-block; text-align: center; margin-right: 20px;">   
    <img src="https://github.com/user-attachments/assets/f649fc59-758b-4aad-8d92-1fb81592fc7e" alt="Topic 1" width="225" /> <img src="https://github.com/user-attachments/assets/146c4dc0-8493-4d44-86f0-d845fc02cfbb" alt="Topic 2" width="225" />  <img src="https://github.com/user-attachments/assets/18638419-1628-4346-9f8b-e977dcb2905c" alt="Topic 3" width="225" />  <img src="https://github.com/user-attachments/assets/af56ffc8-a98c-472a-9d60-7a0a9ce0527c" alt="Topic 4" width="225" />  
  </div>

  <div style="display: inline-block; text-align: center; margin-right: 20px;">
    <img src="https://github.com/user-attachments/assets/886e9c2e-33df-41d9-a98d-e8e1dd4d32ac" alt="Topic 5" width="225" />  <img src="https://github.com/user-attachments/assets/3c75a9c0-26b4-44b1-b5f1-545b3a880fa0" alt="Topic 6" width="225" />  <img src="https://github.com/user-attachments/assets/3fc9a753-656c-4f5d-9197-3d1ec63de82b" alt="Topic 7" width="225" />  <img src="https://github.com/user-attachments/assets/39de7f57-6d58-4ecb-8b2f-83f6cc4b58f2" alt="Topic 8" width="225" />
  </div>

### Best Result (Iteration -8)
<div style="max-width: 100%; overflow-x: auto; white-space: nowrap; padding: 10px;">

  <div style="display: inline-block; text-align: center; margin-right: 20px;">   
    <img src="https://github.com/user-attachments/assets/39de7f57-6d58-4ecb-8b2f-83f6cc4b58f2" alt="Topic 8" width="500" />
  </div>
<div style="display: inline-block; text-align: center; margin-right: 20px;">   
    <img src="https://github.com/user-attachments/assets/573d3163-76a2-4717-9054-4f8b82b9d9e7" alt="Topic 8" width="500" />
  </div>
  <div style="display: inline-block; text-align: center; margin-right: 20px;">   
    <img src="https://github.com/user-attachments/assets/ff75e5f2-4c64-4ff5-b2e9-17b62d78a0c7" alt="Topic 8" width="1000" /> 
  </div>
  
   - **Final average cross-track error = 0.098** 
   - **Maximum cross-track error = 0.242**


This will demonstrate understanding of:
- ROS2 message definitions
- Custom interface creation
- Message publishing patterns 
