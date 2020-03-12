cmake_minimum_required(VERSION 3.15)
project(homework1)

set(CMAKE_CXX_STANDARD 20)

add_executable(homework1 src/main.cpp h/Matrix.h h/Vector.h src/Matrix.cpp src/Vector.cpp)