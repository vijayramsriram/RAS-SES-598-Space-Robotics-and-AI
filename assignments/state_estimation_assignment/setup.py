from setuptools import setup
import os
from glob import glob

package_name = 'state_estimation_assignment'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='Jnaneshwar Das',
    maintainer_email='jdas5@asu.edu',
    description='ROS2 package for SES/RAS 598 state estimation assignments',
    license='MIT',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'kalman_filter = state_estimation_assignment.kalman_filter:main',
            'particle_filter = state_estimation_assignment.particle_filter:main',
            'sensor_simulator = state_estimation_assignment.sensor_simulator:main',
        ],
    },
) 