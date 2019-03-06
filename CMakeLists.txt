cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
project(secondLab)
add_subdirectory(LibrarySort)
add_subdirectory(LibraryReadWrite)
add_subdirectory(test)

