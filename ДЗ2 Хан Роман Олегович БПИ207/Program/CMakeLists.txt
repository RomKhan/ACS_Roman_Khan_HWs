cmake_minimum_required(VERSION 3.20)
project(untitled C)

# project name and language
project(task1 LANGUAGES CXX)

set(CMAKE_C_STANDARD 99)
set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        source/main.cpp
        headers/container.h
        source/container.cpp
        headers/shape.h
        source/shape.cpp
        headers/triangle.h
        headers/rectangle.h
        source/rectangle.cpp
        source/triangle.cpp
        headers/random.h
        source/random.cpp
        source/cicrle.cpp
        headers/circle.h
        headers/point.h
        headers/exceptions.h
        source/exceptions.cpp source/testGenerator.cpp headers/testGenerator.h)

add_executable(untitled ${SOURCE_FILES})
target_link_libraries(untitled m)
