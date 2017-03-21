cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES main.c lab3.c lab3.h lab3_prv.h)
add_executable(untitled ${SOURCE_FILES})

target_link_libraries(untitled glut GLU GL m)