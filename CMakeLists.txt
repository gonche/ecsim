cmake_minimum_required(VERSION 3.11-3.18)

add_definitions(-std=c++14)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(ecsim)

add_executable (ecsim ecsim.cpp easecurve.h easecurve.cpp)
