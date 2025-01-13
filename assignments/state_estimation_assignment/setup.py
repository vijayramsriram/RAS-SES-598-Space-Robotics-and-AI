from setuptools import setup

package_name = 'state_estimation_assignment'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/state_estimation.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='course_admin',
    maintainer_email='admin@example.com',
    description='State estimation assignment package',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'kalman_filter = state_estimation_assignment.kalman_filter:main',
            'particle_filter = state_estimation_assignment.particle_filter:main',
            'sensor_simulator = state_estimation_assignment.sensor_simulator:main',
        ],
    },
) 