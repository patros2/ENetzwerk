cmake_minimum_required(VERSION 3.4)
project(ENetzwerk)

set (ENetzwerk_VERSION_MAJOR 0)
set (ENetzwerk_VERSION_MINOR 1)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")  # enable C++11 standard
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wabi-tag ")  # enable C++11 standard
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")  # enable C++11 standard
set (CMAKE_BUILD_TYPE Debug)


add_subdirectory(lib/docopt.cpp-master)
add_subdirectory(lib/yaml-cpp-master)
add_subdirectory(lib/NodesEdges)
add_subdirectory(lib/berechnungen/)


add_executable(ENetzwerk main.cpp)
add_dependencies(ENetzwerk docopt yaml-cpp)
include_directories(lib/yaml-cpp-master/include)
target_link_libraries (ENetzwerk LINK_PUBLIC docopt yaml-cpp NodesEdges berechnen)
#link_directories($CMAKE_SOURCE_DIR/lib/NodesEdges)

#file(COPY ${PROJECT_BINARY_DIR}/ENetzwerk DESTINATION ../)
