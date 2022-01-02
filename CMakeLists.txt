
cmake_minimum_required(VERSION 3.15)
project(CSTL C)
include_directories(chapter1)
include_directories(chapter3)


set(CMAKE_C_STANDARD 99)

add_executable(CSTL main.c)