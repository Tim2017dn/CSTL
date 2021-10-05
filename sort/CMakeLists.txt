cmake_minimum_required(VERSION 3.15)
project(CSTL C)

set(CMAKE_C_STANDARD 99)


add_executable(quicksort quicksort.c )
add_executable(InsertSort InsertSort.c  sortUtils.c ../chapter2/Stack.c)
add_executable(MergeSort MergeSort.c  sortUtils.c)
add_executable(minpq MinPQ.c sortUtils.c )