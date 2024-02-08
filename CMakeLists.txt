cmake_minimum_required(VERSION 3.27)
project(attack_le_fence)

set(CMAKE_CXX_STANDARD 17)

add_executable(attack_le_fence main.cpp
        Card.cpp
        Card.h)
