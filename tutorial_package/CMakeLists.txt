cmake_minimum_required(VERSION 3.0.2)

project(tutorial_package)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  my_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES tutorial_package
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(pub_node src/pub_node.cpp)
add_dependencies(pub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(pub_node
  ${catkin_LIBRARIES}
)

add_executable(sub_node src/sub_node.cpp)
add_dependencies(sub_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(sub_node
  ${catkin_LIBRARIES}
)

add_executable(client_node src/client_node.cpp)
add_dependencies(client_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(client_node ${catkin_LIBRARIES})

add_executable(server_node src/server_node.cpp)
add_dependencies(server_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(server_node ${catkin_LIBRARIES})