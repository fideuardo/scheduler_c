cmake_minimum_required(VERSION 3.10)

project(Task1)

add_library(Task1 STATIC
    adapt/task1ca.c
    core/task1c1.c
)

target_include_directories(Task1 PUBLIC
    adapt
    core
)
