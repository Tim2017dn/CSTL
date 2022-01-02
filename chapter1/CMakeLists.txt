cmake_minimum_required(VERSION 3.15)
project(chapter1 C)

set(CMAKE_C_STANDARD 99)
add_executable(stack Stack.c )
add_executable(queue Queue.c)
add_executable(list list.c)

add_library(chapter1_lib list.h list.c)