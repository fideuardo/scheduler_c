cmake_minimum_required(VERSION 3.10)

project(Scheduler C)

add_subdirectory(scheduler)
add_subdirectory(scheduler/Task1)
add_subdirectory(scheduler/Task2)

add_executable(Scheduler main.c)

target_link_libraries(Scheduler PRIVATE scheduler Task1 Task2)
