cmake_minimum_required(VERSION 3.0)
project(foo)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)
catkin_package()
include_directories(${catkin_INCLUDE_DIRS})

add_executable(foo src/foo_node.cpp)
target_link_libraries(foo ${catkin_LIBRARIES})
