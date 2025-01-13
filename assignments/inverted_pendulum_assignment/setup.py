from setuptools import setup

package_name = 'inverted_pendulum_assignment'

setup(
    name=package_name,
    version='0.0.1',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', ['launch/pendulum.launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='course_admin',
    maintainer_email='admin@example.com',
    description='Inverted pendulum control assignment package',
    license='Apache License 2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'pendulum_model = inverted_pendulum_assignment.pendulum_model:main',
            'pendulum_controller = inverted_pendulum_assignment.pendulum_controller:main',
            'safety_monitor = inverted_pendulum_assignment.safety_monitor:main',
        ],
    },
) 