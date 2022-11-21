cmake_minimum_required(VERSION 3.23)
project(shifr)

set(CMAKE_CXX_STANDARD 20)

add_executable(shifr main.cpp header.hpp xor.cpp)
