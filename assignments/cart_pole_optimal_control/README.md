### Cart-Pole System Performance Analysis with Different LQR Cost Matrices

#### Objective:
The goal of this report is to analyze the behavior of a cart-pole system under different **Linear Quadratic Regulator (LQR)** cost matrices. We will compare two sets of cost matrices and examine the system's stability and control force usage.

### **1. Introduction:**
The **cart-pole system** consists of a cart that moves horizontally on a track, with a pole mounted on top. The task is to keep the pole balanced upright by controlling the horizontal position of the cart. The system is controlled by an **LQR controller**, which minimizes a quadratic cost function.

The performance of the system depends heavily on the values of the **state cost matrix (Q)** and the **control cost matrix (R)** used in the LQR controller.

### **2. LQR Cost Matrices:**
In the LQR controller, the following cost function is minimized:
$$
J = \int_0^\infty \left( x^T Q x + u^T R u \right) dt
$$
Where:
- \( x \) is the state vector of the system (cart position, cart velocity, pole angle, pole angular velocity),
- \( u \) is the control input (force applied to the cart),
- \( Q \) is the state cost matrix, and
- \( R \) is the control cost matrix.

#### **Default Parameters**:
- **State cost matrix (`Q`)**: 
$$
Q = \text{diag}(1.0, 1.0, 10.0, 10.0)
$$
- **Control cost matrix (`R`)**: 
$$
R = 0.1
$$

#### **Modified Parameters** (Your input):
- **State cost matrix (`Q`)**: 
$$
Q = {diag}(1.0, 1.0, 50.0, 50.0)
$$
- **Control cost matrix (`R`)**: 
$$
R = 0.01
$$

### **3. Performance with Default Parameters**:

- **Initial Condition**: At the beginning, the pole's deviation from the upright position is small, with the **max pole angle deviation** being 0.047 radians. The **RMS cart position error** is 0.136 m, and the system applies an initial control force of 1.517 N.

- **Midway Through Operation**: As the system continues to run, the **cart position error** increases to 0.758 m, and the **peak control force** rises to 26.436 N. This indicates that the system is struggling to stabilize the pole. The control force is not sufficient to keep the pole balanced, and the pole’s **max angle deviation** increases to 1.706 radians.

- **Final Stage (Pole Falling)**: Eventually, the pole falls as the **control force** spikes to 301.772 N, far beyond what is typically necessary to stabilize the system. The **max pole angle deviation** reaches 1.706 radians, and the **RMS cart position error** becomes 0.940 m, signaling the failure of the control system to stabilize the pole.

The terminal log from the default parameters shows the following output:
```
[lqr_controller-7] [INFO] [1740034445.621724473] [lqr_controller]: Max Pole Angle Deviation: 0.047 rad
[lqr_controller-7] [INFO] [1740034445.621949379] [lqr_controller]: RMS Cart Position Error: 0.136 m
[lqr_controller-7] [INFO] [1740034445.622176123] [lqr_controller]: Peak Control Force Used: 14.420 N
...
[lqr_controller-7] [INFO] [1740034471.242496170] [lqr_controller]: Max Pole Angle Deviation: 1.706 rad
[lqr_controller-7] [INFO] [1740034471.242963200] [lqr_controller]: Peak Control Force Used: 301.772 N
```

### **4. Performance with Modified Parameters (Your input)**:

With the new **LQR cost matrices**:
- **State cost matrix (`Q`)**: 
\[
Q = \text{diag}(1.0, 1.0, 50.0, 50.0)
\]
- **Control cost matrix (`R`)**: 
\[
R = 0.01
\]

The system becomes much more stable:

- **Initial Condition**: The **max pole angle deviation** is reduced to 0.036 radians, and the **RMS cart position error** is reduced to 0.053 m. The control force is initially higher (**48.875 N**), which allows the system to make stronger corrections.

- **Midway Through Operation**: The **RMS cart position error** stays around 0.053 m, and the **max pole angle deviation** remains low at **0.049 rad**. The **peak control force** increases to 55.210 N, but the system does not experience instability. The pole stays upright and is successfully balanced.

- **Final Stage (Pole Upright Indefinitely)**: The pole continues to stay upright, and the system maintains stable performance, with the **control force** being used to a manageable level. The pole does not fall, and the cart position error remains small.

The terminal log from the modified parameters shows:
```
[lqr_controller-7] [INFO] [1740036272.188791386] [lqr_controller]: RMS Cart Position Error: 0.053 m
[lqr_controller-7] [INFO] [1740036272.189026876] [lqr_controller]: Peak Control Force Used: 48.875 N
...
[lqr_controller-7] [INFO] [1740036826.465840687] [lqr_controller]: State: [[ 0.01588653  0.08279201 -0.03615926 -0.04823479]], Control force: -14.760N
[lqr_controller-7] [INFO] [1740036826.466356983] [lqr_controller]: RMS Cart Position Error: 0.053 m
[lqr_controller-7] [INFO] [1740036826.476755903] [lqr_controller]: Peak Control Force Used: 55.210 N
```

### **5. Analysis of Results:**

#### **Comparison of Control Behavior**:
1. **Default Parameters**:
   - **Pole Angle Deviation**: Starts at **0.047 rad** and increases to **1.706 rad**, indicating the system is unable to keep the pole upright as the control force is insufficient.
   - **Cart Position Error**: The error increases significantly, indicating instability in the cart’s movement as the pole falls.
   - **Control Force**: Starts at 1.517 N but escalates to over **301 N** in an attempt to stabilize the system, which is not enough to prevent failure.

2. **Modified Parameters**:
   - **Pole Angle Deviation**: Remains at **0.036 rad** and stays close to this value, indicating the pole remains balanced.
   - **Cart Position Error**: Stays around **0.053 m**, showing better control over the cart's horizontal position.
   - **Control Force**: Initially higher (**48.875 N**) but remains within a manageable range, allowing the system to stabilize and keep the pole upright indefinitely.

#### **Why the Parameters Affect Stability**:
- **State Cost (`Q`)**: Increasing the weights for the pole angle and cart position in the state cost matrix (`Q`) makes the controller **more sensitive to deviations in these states**. This results in **stronger corrective actions** by the controller to keep the pole upright.
  
- **Control Cost (`R`)**: Lowering the control cost (`R`) allows the controller to apply **stronger control forces** when needed. In the default case, a higher control cost limited the force that could be applied to the cart, leading to an inability to stabilize the pole. With a smaller `R`, the controller is free to apply larger forces, which leads to more effective stabilization.

### **6. Conclusion:**
- With the **default LQR cost matrices**, the system exhibits instability, with the pole falling within a few seconds due to insufficient control force and a lack of strong correction to maintain balance.
- By increasing the **state cost matrix (`Q`)** and decreasing the **control cost matrix (`R`)**, the system becomes much more stable, allowing the pole to remain upright indefinitely with reasonable control force usage.

This analysis demonstrates the importance of tuning the **LQR cost matrices** to achieve stable control in dynamic systems like the cart-pole problem.
