import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/farhan-sw/Documents/Github/learn-ros2/section3/ros2_ws/install/my_py_pkg'
