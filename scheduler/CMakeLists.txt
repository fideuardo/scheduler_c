cmake_minimum_required(VERSION 3.10)

project(scheduler)

add_library(scheduler STATIC
    core/scheduler.c
)

target_link_libraries(scheduler PUBLIC Task1 Task2)

target_include_directories(scheduler PUBLIC
    core
    ${CMAKE_SOURCE_DIR}/scheduler/Task1/core
    ${CMAKE_SOURCE_DIR}/scheduler/Task1/adapt
    ${CMAKE_SOURCE_DIR}/scheduler/Task2/core
    ${CMAKE_SOURCE_DIR}/scheduler/Task2/adapt
)
