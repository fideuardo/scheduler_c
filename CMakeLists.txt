cmake_minimum_required(VERSION 3.10)

project(scheduler_c C)

add_subdirectory(scheduler)
#add_subdirectory(scheduler/Task1)
#add_subdirectory(scheduler/Task2)
add_executable(scheduler_c modular.c)

target_link_libraries(scheduler_c PRIVATE scheduler)
