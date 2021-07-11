# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "roscpp;rospy;std_msgs;mavros_msgs;mpc0".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lmpc_handler".split(';') if "-lmpc_handler" != "" else []
PROJECT_NAME = "mpc_handler"
PROJECT_SPACE_DIR = "/home/mohzap/catkin_ws/install"
PROJECT_VERSION = "0.0.0"
