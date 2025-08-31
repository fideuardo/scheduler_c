cmake_minimum_required(VERSION 3.10)

project(Task2)

add_library(Task2 STATIC
    adapt/task2ca.c
    core/task2c1.c
)

target_include_directories(Task2 PUBLIC
    adapt
    core
    ${CMAKE_SOURCE_DIR}/scheduler/Task1/core
    ${CMAKE_SOURCE_DIR}/scheduler/Task1/adapt
)
