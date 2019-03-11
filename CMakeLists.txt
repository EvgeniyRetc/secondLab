cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
project(secondLab)
add_subdirectory(src/LibrarySort)
add_subdirectory(src/LibraryReadWrite)
add_subdirectory(src/test)
add_subdirectory(googletest)

