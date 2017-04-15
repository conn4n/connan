cmake_minimum_required(VERSION 3.7)
project(connan)

set(CMAKE_CXX_STANDARD 14)
find_package(Boost REQUIRED COMPONENTS filesystem system)
include_directories(${Boost_INCLUDE_DIRS})

set(SOURCE_FILES main.cpp OverlayMount.cpp OverlayMount.hpp StringException.hpp)
add_executable(connan ${SOURCE_FILES})
target_link_libraries(connan ${Boost_LIBRARIES})