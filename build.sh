#!/bin/bash

# Define project root and build directory
PROJECT_ROOT="$(dirname "$(readlink -f "$0")")"
BUILD_DIR="${PROJECT_ROOT}/build"
SOURCE_DIR="${PROJECT_ROOT}"

function cmake_build() {
    echo "--- Configuring CMake and Building Project ---"
    mkdir -p "${BUILD_DIR}"
    cmake -S "${SOURCE_DIR}" -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE=Debug
    if [ $? -ne 0 ]; then
        echo "CMake configuration failed."
        exit 1
    fi
    cmake --build "${BUILD_DIR}"
    if [ $? -ne 0 ]; then
        echo "Project build failed."
        exit 1
    fi
    echo "--- CMake Configuration and Build Complete ---"
}

function build() {
    echo "--- Building Project ---"
    if [ ! -d "${BUILD_DIR}" ]; then
        echo "Build directory does not exist. Please run 'cmake_build' first."
        exit 1
    fi
    cmake --build "${BUILD_DIR}"
    if [ $? -ne 0 ]; then
        echo "Project build failed."
        exit 1
    fi
    echo "--- Build Complete ---"
}

function clean() {
    echo "--- Cleaning Build Output ---"
    cmake_clean
    echo "--- Build Output Cleaned ---"
}

function cmake_clean() {
    echo "--- Cleaning All CMake Generated Files ---"
    rm -rf "${BUILD_DIR}"
    echo "--- CMake Clean Complete ---"
}

# Main script logic
case "$1" in
    cmake_build)
        cmake_build
        ;;
    build)
        build
        ;;
    clean)
        clean
        ;;
    cmake_clean)
        cmake_clean
        ;;
    *)
        echo "Usage: $0 {cmake_build|build|clean|cmake_clean}"
        exit 1
        ;;
esac
