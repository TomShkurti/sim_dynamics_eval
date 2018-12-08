cmake_minimum_required(VERSION 2.8.3)
project(mechanical_evaluation)

find_package(catkin REQUIRED COMPONENTS roscpp roslib uv_control
	#roslint cwru_davinci_kinematics cwru_davinci_control
)

#TODO Is this necessary?
find_package(Boost REQUIRED COMPONENTS system thread)

include_directories(${catkin_INCLUDE_DIRS})

catkin_package(
	INCLUDE_DIRS ${catkin_INCLUDE_DIRS}
	#LIBRARIES
	CATKIN_DEPENDS roscpp roslib uv_control#roslint
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
	#include
	${catkin_INCLUDE_DIRS}
	${Boost_INCLUDE_DIR}
)

add_executable(long_run src/long_run.cpp)
target_link_libraries(long_run ${catkin_LIBRARIES} ${Boost_LIBRARIES})

add_executable(just_move src/just_move.cpp)
target_link_libraries(just_move ${catkin_LIBRARIES} ${Boost_LIBRARIES})
