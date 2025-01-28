**Final Parameter Values and Justification**
The following parameter values were tuned for the best performance:

**• Kp_linear = 2.2**

**Behavior Observed at Higher Values:**

When this gain was increased beyond 2.2, the robot displayed unstable behavior. It moved uncontrollably, often overshooting the target and overlapping into previously covered lines. Additionally, at the endpoint of each line, the robot failed to stop in the designated area and moved beyond the restricted zone before halting.

**Optimal Value (2.2):** 

At this value, the robot maintained smooth linear tracking, avoiding significant overshooting or overlap. It effectively stopped within the restricted area at the endpoints, ensuring precise coverage of the workspace.

**• Kd_linear = 0.2**

**Behavior at 0.0:** 

Without any damping (Kd = 0.0), the robot exhibited overlap at certain turning points, likely due to residual momentum from its linear motion.

**Behavior at Higher Values:** 

Increasing this value to 2.0 caused the robot to slow excessively before turns, leading to jerky motion. At very high values, the robot appeared to "stick" and failed to complete the desired trajectory smoothly.

**Optimal Value (0.2):**

This value acted as a sufficient "braking factor," allowing the robot to reduce overlap without excessive deceleration. It ensured smooth transitions at turning points and balanced the motion between rows effectively.

**• Kp_angular = 11.2**

**Behavior at Lower Values:** 

Reducing this value to 5.0 caused the robot to take wider curves at row transitions. This led to inefficient coverage and deviations from the desired trajectory.

**Behavior at Higher Values:** 

Increasing this gain beyond 11.2 caused the robot to overcorrect its angular errors, leading to oscillatory motion or wobbling, especially during sharp turns.

**Optimal Value (11.2):** 

At this value, the robot took tight, precise corners without introducing oscillations. This ensured efficient and smooth row-to-row transitions, minimizing deviations from the desired path.

**• Kd_angular = 0.0**

**Behavior at Non-Zero Values:**

Even small values like 0.1 caused the robot to wobble excessively when transitioning between rows. This was due to the damping factor introducing oscillations that destabilized the angular control. Increasing this value further only amplified the wobbling effect, with the robot oscillating multiple times (5-6 times) before stabilizing on a straight track.

**Optimal Value (0.0):** 

Completely eliminating the derivative term for angular control resulted in smooth and stable turning behavior, with no wobbling or oscillations observed.

**• Spacing = 1.0**

**Optimal Spacing Justification:**

This parameter was tuned to ensure even coverage of the workspace. At smaller values, rows were too close together, leading to redundant coverage and inefficient use of space. Larger spacing caused gaps between rows, resulting in incomplete coverage of the workspace.

**Optimal Value (1.0):** 

This spacing provided efficient use of space, with each row adequately covering its assigned area. It prevented overlap between adjacent rows while ensuring no areas were left uncovered.

**Performance Metrics and Analysis**

**1. Cross-Track Error**
    • Current: -0.001 
    • Average: 0.034 
    • Minimum: 0.001 
    • Maximum: 0.099

  ![image](https://github.com/user-attachments/assets/6bdb2c87-ee5c-47aa-8633-279c0b2643c2)
 
These metrics demonstrate that the robot consistently maintained low deviations from the desired path, achieving near-perfect tracking with minimal cross-track error.

**2. Trajectory Plot**

The trajectory plot visualizes the robot's path across the boustrophedon pattern. Each line segment corresponds to a row, with smooth transitions at the turning points.

**• Key Observations:** 
        ◦ Minimal overshooting at row endpoints. 
        ◦ Tight turns with consistent spacing.
   
**3. Velocity Profiles**

The velocity profiles for both linear and angular velocities show the robot's responsiveness to the control inputs:

**• Linear Velocity:** Smooth acceleration and deceleration near turning points, maintaining a constant speed during straight-line motion. 

**• Angular Velocity:** Sharp spikes at turning points, indicating tight cornering.

![image](https://github.com/user-attachments/assets/0d0af055-63d7-4b4a-af5b-70632913b4a6)


**Discussion of Tuning Methodology**

**1. Initial Tuning**

**Objective:** Establish a baseline for the controller by starting with reasonable default values and understanding the robot's behavior.  

**Approach:**  
Began with default values. These values provided a starting point to observe how the robot responded to control inputs.  
bserved critical issues like overshooting, large turning curves, and wobbling. This helped identify which parameters had the most significant influence on performance.  
Adjustments were then made incrementally to refine performance in each phase of motion, focusing on one issue at a time.

**2. Single Parameter Tuning**

**Objective:** Isolate the impact of each parameter to methodically fine-tune the robot's behavior.

**Approach:**  

**Tuning `Kp_linear`:**  

Adjusted the proportional gain for linear velocity to stabilize straight-line motion.  
Lower values caused sluggish behavior, while higher values introduced overshooting at endpoints. Through iterative adjustments, `Kp_linear = 2.2` was determined to balance responsiveness and endpoint precision.

**Tuning `Kd_linear`:**  

Increased the derivative gain to minimize overshooting at row endpoints.  
Initially set to `0.0`, which led to endpoint overlap. Incremental increases revealed that `Kd_linear = 0.2` provided smooth braking without excessive deceleration.  

**Tuning `Kp_angular`:**  
Adjusted the proportional gain for angular velocity to optimize cornering performance.  
Lower values like `5.0` caused wide turning curves, while higher values caused overcorrection and oscillations. A value of `Kp_angular = 11.2` was found to produce tight, controlled turns without wobbling. 

**Setting `Kd_angular = 0.0`:**  
Any non-zero value introduced oscillatory damping effects, leading to wobbling during turns. By setting `Kd_angular` to `0.0`, the wobbling was entirely eliminated, resulting in smooth, stable transitions between rows.

**3. Real-Time Visualization**
   
**Objective:** Use visualization tools to monitor critical performance metrics and provide immediate feedback for parameter adjustments.  

**Approach:**

**Using `rqt_plot`:**  

Monitored key topics such as `/turtle1/cmd_vel/linear/x` (linear velocity), `/turtle1/cmd_vel/angular/z` (angular velocity), and `/cross_track_error` (deviation from the desired path).  
Observed real-time plots to identify trends like velocity overshoots, turning instability, and cross-track error reduction over time. 

**Using `rqt_reconfigure`:**  

Dynamically adjusted parameters during runtime, allowing immediate observation of how each change affected performance. This real-time feedback loop significantly accelerated the tuning process. 

**Performance Insights:**  

Detected overshooting by spikes in `/cmd_vel/linear/x`.  
Identified wobbling during turns by oscillations in `/cmd_vel/angular/z`.  
Monitored cross-track error to ensure it consistently decreased as tuning progressed.

**4. Final Iterations**
   
**Approach:**

**Testing Over Multiple Cycles:**

Ran the robot through the boustrophedon pattern multiple times to confirm that the adjustments worked across different rows and transitions.  
Observed consistent endpoint precision, smooth turning, and uniform row coverage.

**Adjusting Spacing:**  

Fine-tuned the spacing parameter to achieve even row coverage without overlaps or gaps. A value of `1.0` ensured optimal coverage while maintaining efficiency.  
Trajectory plots were analyzed to verify that row-to-row spacing was uniform throughout the workspace.

**Challenges and Solutions**

**Challenge: Overshooting at Row Endpoints**

Problem Observed: The robot moved beyond the restricted area at the ends of rows before stopping. This led to overlapping into previously covered areas, reducing trajectory accuracy and creating inefficiencies in coverage.
Solution:Reduction of Kp_linear: The proportional gain for linear velocity was reduced to prevent excessive acceleration that caused the overshooting. Lowering this value allowed the robot to maintain a controlled and steady approach toward the endpoints.
Increase in Kd_linear: The derivative gain for linear velocity was increased to act as a braking factor, helping the robot decelerate smoothly as it approached the endpoints. This adjustment eliminated the overshooting behavior while maintaining precise stopping within the designated area.

**Challenge: Wobbling During Turns**

Problem Observed: The robot exhibited oscillatory motion or wobbling when transitioning between rows, especially during tight turns. This caused instability and delayed the completion of the turn.
Solution:Setting Kd_angular to 0.0: The derivative term for angular velocity was causing over-damping and introduced oscillatory effects. By setting it to 0.0, the wobbling was completely eliminated, resulting in smooth and stable turns.
Fine-Tuning of Kp_angular: The proportional gain for angular velocity was adjusted to achieve the optimal balance between curve tightness and stability. This ensured that the robot could execute precise turns without counteracting its own motion, avoiding both wide curves and oscillations.

**Challenge: Uneven Spacing Between Rows**

Problem Observed: The spacing between adjacent rows was inconsistent, leading to gaps or overlaps in the workspace coverage. This reduced the efficiency of the boustrophedon pattern.
Solution:Adjustment of the spacing Parameter: The spacing parameter was carefully tuned to 1.0, ensuring even and consistent row-to-row coverage. This value provided a balance between avoiding redundant coverage (overlap) and ensuring no areas were left uncovered (gaps).
Verification with Trajectory Plots: The trajectory was visually analyzed using performance plots to confirm that the spacing was uniform across the entire workspace.fied with trajectory plots.

