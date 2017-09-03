cmake_minimum_required(VERSION 2.8.12)

project(brickwall)
SET( CMAKE_CXX_FLAGS  "-std=c++11" )

add_executable(brickwall buildwall.cpp brickwall.h brickwall.cpp)
