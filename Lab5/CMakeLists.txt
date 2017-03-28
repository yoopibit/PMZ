cmake_minimum_required(VERSION 3.6)
project(Lab5)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c)
add_executable(Lab5 ${SOURCE_FILES})

target_link_libraries(Lab5 glut GLU GL m)