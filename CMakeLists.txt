cmake_minimum_required(VERSION 2.6)
project(BMB)
add_executable(BMB multiBench.cpp util.c)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")
