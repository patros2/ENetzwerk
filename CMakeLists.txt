cmake_minimum_required(VERSION 3.4)
project(ENetzwerk)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")  # enable C++11 standard
set (CMAKE_BUILD_TYPE Debug)


add_subdirectory(lib/docopt.cpp-master)
add_subdirectory(lib/yaml-cpp-master)

add_executable(ENetzwerk main.cpp)
add_dependencies(ENetzwerk docopt yaml-cpp)
target_link_libraries (ENetzwerk LINK_PUBLIC docopt yaml-cpp)

