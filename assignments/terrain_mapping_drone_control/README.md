# Assignment 3: Rocky Times Challenge - Search, Map, & Analyze

This ROS2 package implements an autonomous drone system for geological feature detection, mapping, and analysis using ORBSLAM3 and PX4 SITL simulation.

## Challenge Overview

Students will develop a controller for a PX4-powered drone to efficiently search, map, and analyze geological features in an unknown environment. The system must identify rock formations, estimate their centroids, and determine basal contact footprints while optimizing for time and energy consumption.

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
- ORBSLAM3 ROS2 package
- OpenCV
- Python 3.8+

## Installation

1. Clone this assignment package into your ROS2 workspace:
```bash
cd ~/ros2_ws/src
git clone <course_repository_url>
```

2. Install dependencies:
```bash
cd ~/ros2_ws
rosdep install --from-paths src --ignore-src -r -y
```

3. Build the package:
```bash
colcon build --packages-select terrain_mapping_drone_control
```

4. Source the workspace:
```bash
source ~/ros2_ws/install/setup.bash
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

## Extra Credit: 3D Reconstruction

For additional points, implement 3D reconstruction of cylindrical rock formations using ORBSLAM3:

### Requirements

- Subscribe to ORBSLAM3's point cloud output topic `/orbslam3/point_cloud`
- Implement cylinder fitting algorithm to reconstruct rock formations
- Estimate cylinder parameters (radius, height, orientation)
- Visualize the reconstructed 3D model in RViz

### Implementation Guidelines

1. ORBSLAM3 Integration:
```bash
# Subscribe to ORBSLAM3 topics
ros2 run terrain_mapping_drone_control orbslam_processor
```

2. Point Cloud Processing:
- Filter and segment the point cloud
- Identify potential cylindrical formations
- Apply RANSAC-based cylinder fitting

### Evaluation Metrics

Extra credit points will be awarded based on:
- Accuracy of cylinder parameter estimation
- Real-time processing capability
- Visualization quality
- Documentation of methodology

### Required Dependencies for Extra Credit
- ORBSLAM3 ROS2 package
- Point Cloud Library (PCL)
- Open3D (optional)

## License

This assignment is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License (CC BY-NC-SA 4.0). This means you are free to:

- Share: Copy and redistribute the material in any medium or format
- Adapt: Remix, transform, and build upon the material

Under the following terms:
- Attribution: You must give appropriate credit
- NonCommercial: You may not use the material for commercial purposes
- ShareAlike: If you remix, transform, or build upon the material, you must distribute your contributions under the same license

For more details: https://creativecommons.org/licenses/by-nc-sa/4.0/ 