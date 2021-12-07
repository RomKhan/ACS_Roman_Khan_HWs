cmake_minimum_required(VERSION 3.20)
project(HW5 C)

# project name and language
project(task1 LANGUAGES CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS -pthread)
set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        main.c
        buffer.h
        print.h
        print.c)

add_executable(HW5 ${SOURCE_FILES})
target_link_libraries(HW5 m)
