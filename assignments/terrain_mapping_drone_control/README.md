# Assignment 3: Rocky Times Challenge - Search, Map, & Analyze

This ROS2 package implements an autonomous drone system for geological feature detection, mapping, and analysis using an RGBD camera and PX4 SITL simulation.

## Challenge Overview

Students will develop a controller for a PX4-powered drone to efficiently search, map, and analyze geological features in an unknown environment. The system must identify rock formations, estimate their centroids, and determine basal contact footprints while optimizing for time and energy consumption.
![image](https://github.com/user-attachments/assets/a176275d-f305-495b-8f0f-89e83ef838e2)

### Evaluation Criteria

The assignment will be evaluated based on:
- Total time taken to complete the mission
- Total energy units consumed during operation
- Accuracy of centroid estimates for rock formations
- Precision of basal contact footprint estimation
- Performance across multiple trials (10 known + 5 unknown scenes)

### Key Requirements

- Autonomous takeoff and landing capabilities
- Efficient search strategy implementation
- Real-time feature detection and mapping
- Energy-conscious path planning
- Accurate geological feature analysis
- Robust performance across different scenarios

## Prerequisites

- ROS2 Humble
- PX4 SITL Simulator
- RTAB-Map ROS2 package
- OpenCV
- Python 3.8+

## Repository Setup

### If you already have a fork of the course repository:

```bash
# Navigate to your local copy of the repository
cd ~/RAS-SES-598-Space-Robotics-and-AI

# Add the original repository as upstream (if not already done)
git remote add upstream https://github.com/DREAMS-lab/RAS-SES-598-Space-Robotics-and-AI.git

# Fetch the latest changes from upstream
git fetch upstream

# Checkout your main branch
git checkout main

# Merge upstream changes
git merge upstream/main

# Push the updates to your fork
git push origin main
```

### If you don't have a fork yet:

1. Fork the course repository:
   - Visit: https://github.com/DREAMS-lab/RAS-SES-598-Space-Robotics-and-AI
   - Click "Fork" in the top-right corner
   - Select your GitHub account as the destination

2. Clone your fork:
```bash
cd ~/
git clone https://github.com/YOUR_USERNAME/RAS-SES-598-Space-Robotics-and-AI.git
```

### Create Symlink to ROS2 Workspace

```bash
# Create symlink in your ROS2 workspace
cd ~/ros2_ws/src
ln -s ~/RAS-SES-598-Space-Robotics-and-AI/assignments/terrain_mapping_drone_control .
```

## Building and Running

```bash
# Build the package
cd ~/ros2_ws
colcon build --packages-select terrain_mapping_drone_control --symlink-install

# Source the workspace
source install/setup.bash

# Launch the simulation with visualization
ros2 launch terrain_mapping_drone_control challenge.launch.py
```

## Usage

1. Launch the simulation environment and your solution:
```bash
ros2 launch terrain_mapping_drone_control challenge.launch.py
```

2. Monitor mission progress:
```bash
ros2 topic echo /drone/mission_status
```

3. Visualize the mapping process:
```bash
ros2 run rqt_image_view rqt_image_view
```

## Configuration

Customize your solution through the following configuration files:

- `config/challenge_params.yaml`: Mission parameters and thresholds
- `config/sensor_config.yaml`: Sensor and camera configurations
- `launch/challenge.launch.py`: Simulation and algorithm parameters

### Key Parameters

- `search_strategy`: Algorithm for area exploration
- `feature_detection_params`: Rock formation detection parameters
- `energy_threshold`: Maximum energy units allowed
- `time_limit`: Maximum mission duration
- `analysis_precision`: Required accuracy for measurements

## Submission Requirements

1. Your complete ROS2 package with implemented solution
2. Documentation of your approach and algorithms
3. Performance analysis across 10 test trials
4. Brief video demonstration (2-3 minutes)

## Leaderboard

The leaderboard will be available mid-Spring break and will display:
- Team rankings based on composite scores
- Individual performance metrics
- Statistics from both known and unknown trial runs

## Scoring Formula

Final score is calculated based on:
```
Score = w1*(Time_Efficiency) + w2*(Energy_Efficiency) + 
        w3*(Centroid_Accuracy) + w4*(Footprint_Accuracy)
```
Where w1, w2, w3, and w4 are weight factors that will be revealed during evaluation.

## Scoring Breakdown (Total: 150 points)

### Main Assignment (100 points)

#### Implementation (40 points)
- Autonomous Navigation System (15 points)
  - Takeoff and landing capabilities (5 points)
  - Path planning implementation (5 points)
  - Obstacle avoidance (5 points)

- Feature Detection (15 points)
  - Rock formation detection accuracy (8 points)
  - Real-time mapping capability (7 points)

- System Integration (10 points)
  - ROS2 node architecture (5 points)
  - Topic/service organization (5 points)

#### Performance Metrics (40 points)
- Mission Completion (15 points)
  - Successfully identifying and estimating rock geometry features (8 points)
  - Landing at designated location (7 points)

- Efficiency Metrics (15 points)
  - Time efficiency (8 points)
  - Energy consumption (7 points)

- Accuracy Metrics (10 points)
  - Centroid estimation error (5 points)
  - Basal contact footprint error (5 points)

#### Documentation and Analysis (20 points)
- Technical Documentation (10 points)
  - System architecture description (3 points)
  - Algorithm explanations (4 points)
  - Installation/usage instructions (3 points)

- Performance Analysis (10 points)
  - Test results analysis (5 points)
  - Performance optimization discussion (5 points)

### Extra Credit: 3D Reconstruction (50 points)

#### SLAM Implementation (25 points)
- SLAM Integration (15 points)
  - System setup and configuration (5 points)
  - Real-time mapping capability (5 points)
  - Point cloud generation (5 points)

- Feature Reconstruction (10 points)
  - Cylinder fitting implementation (5 points)
  - Parameter estimation accuracy (5 points)

#### Analysis and Visualization (15 points)
- 3D Model Quality (8 points)
  - Reconstruction accuracy (4 points)
  - Point cloud density/coverage (4 points)

- Visualization (7 points)
  - RViz integration (4 points)
  - User interface/controls (3 points)

#### Documentation and Innovation (10 points)
- Technical Write-up (5 points)
  - Methodology description (2 points)
  - Results analysis (3 points)

- Innovation (5 points)
  - Novel approaches/improvements (3 points)
  - Performance optimizations (2 points)

### Minimum Requirements
- Must score at least 70 points in main assignment to be eligible for extra credit
- Extra credit implementation must maintain real-time performance
- All code must be properly documented and tested

### Bonus Points (up to 10 additional points)
- Exceptional innovation in approach
- Outstanding performance metrics
- Novel visualization techniques
- Significant optimizations

## License

This assignment is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License (CC BY-NC-SA 4.0). This means you are free to:

- Share: Copy and redistribute the material in any medium or format
- Adapt: Remix, transform, and build upon the material

Under the following terms:
- Attribution: You must give appropriate credit
- NonCommercial: You may not use the material for commercial purposes
- ShareAlike: If you remix, transform, or build upon the material, you must distribute your contributions under the same license

For more details: https://creativecommons.org/licenses/by-nc-sa/4.0/ 
