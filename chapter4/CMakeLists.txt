cmake_minimum_required(VERSION 3.15)
project(chapter4 C)

set(CMAKE_C_STANDARD 99)

#add_directory(../chapter1)
include_directories(../chapter1)
#link_libraries(chapter1_lib)



add_executable(graph graph.c)

target_include_directories(graph PUBLIC ../chapter1)
target_link_directories(graph PUBLIC ../chapter1)
target_link_libraries(graph chapter1_lib)


