cmake_minimum_required(VERSION 2.8.3)
project(ros_tutorials)


find_package(catkin REQUIRED COMPONENTS
  roscpp std_msgs
)
catkin_package(
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

add_executable(ros_tutorials_pub
  src/ros_tutorials_pub.cpp
)
add_dependencies(ros_tutorials_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_tutorials_pub
  ${catkin_LIBRARIES}
)

add_executable(ros_tutorials_sub
  src/ros_tutorials_sub.cpp
)
add_dependencies(ros_tutorials_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_tutorials_sub
  ${catkin_LIBRARIES}
)