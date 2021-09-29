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
        main.c
        container.h
        container.c
        shape.h
        shape.c
        triangle.h
        rectangle.h
        rectangle.c
        triangle.c
        random.h
        random.c
        cicrle.c
        circle.h
        point.h exceptions.h exceptions.c)

add_executable(untitled ${SOURCE_FILES})
target_link_libraries(untitled m)
