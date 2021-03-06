cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
find_package (Eigen REQUIRED)
include_directories (${Eigen_INCLUDE_DIRS})

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
#set(ROS_BUILD_TYPE RelWithDebInfo)

rosbuild_init()
rosbuild_add_boost_directories()
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

rosbuild_genmsg()
#rosbuild_gensrv()
#include_directories(include)

#common commands for building c++ executables and libraries
#rosbuild_add_library(${PROJECT_NAME} src/example.cpp)
rosbuild_add_library(${PROJECT_NAME} 	#src/mpc/lbmpc.cpp
										src/mpc/stdmpc.cpp
										src/optimizer/qpOASES.cpp
										src/example_models/tanks_system.cpp
										src/example_models/tanks_system_simulator.cpp
										src/example_models/ardrone.cpp
										src/example_models/ardrone_simulator.cpp
										src/example_models/ardrone_hovering.cpp)
#target_link_libraries(${PROJECT_NAME} another_library)
#rosbuild_add_boost_directories()
#rosbuild_link_boost(${PROJECT_NAME} thread)
#rosbuild_add_executable(example examples/example.cpp)

rosbuild_add_executable(modelval src/model_validation.cpp)

rosbuild_add_executable(ardronempc_node src/ardronempc_node.cpp)
target_link_libraries(ardronempc_node ${PROJECT_NAME} -lrt)

rosbuild_add_executable(ardrone_gazebo_mpc_node src/ardrone_gazebo_mpc_node.cpp)
target_link_libraries(ardrone_gazebo_mpc_node ${PROJECT_NAME} -lrt)


rosbuild_add_executable(stdmpc_node src/stdmpc_node.cpp)
target_link_libraries(stdmpc_node ${PROJECT_NAME} -lrt)
#rosbuild_add_executable(lbmpc_node src/lbmpc_node.cpp)
#target_link_libraries(lbmpc_node ${PROJECT_NAME})

rosbuild_link_boost(ardronempc_node thread)
rosbuild_link_boost(stdmpc_node thread)

