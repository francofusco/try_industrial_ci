cmake_minimum_required(VERSION 3.0)
project(foo)
add_compile_options(-std=c++11)
find_package(catkin REQUIRED COMPONENTS roscpp std_msgs)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES footils
  CATKIN_DEPENDS roscpp std_msgs
)


###########
## BUILD ##
###########

include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(foo_node src/foo_node.cpp)
target_link_libraries(foo_node ${catkin_LIBRARIES})

add_library(footils src/footils.cpp)
target_link_libraries(footils ${catkin_LIBRARIES})


#############
## TESTING ##
#############
if(CATKIN_ENABLE_TESTING)
  catkin_add_gtest(footils_test test/footils.cpp)
  target_link_libraries(footils_test footils ${catkin_LIBRARIES})
endif()


#############
## INSTALL ##
#############

# library
install(TARGETS footils
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
)

# executables
install(TARGETS foo_node
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# python scripts
catkin_install_python(PROGRAMS scripts/foopy
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# headers
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  PATTERN ".svn" EXCLUDE
)
