cmake_minimum_required(VERSION 3.3)
project(first)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Matrix.h  Algorithm.cpp Algorithm.h Matrix.cpp Matrix.h)
add_executable(first ${SOURCE_FILES})