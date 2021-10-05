cmake_minimum_required(VERSION 3.15)
project(CSTL C)

set(CMAKE_C_STANDARD 99)
add_executable(stack Stack.c )
add_executable(queue Queue.c)