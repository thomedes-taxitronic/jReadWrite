cmake_minimum_required(VERSION 3.15...3.30)

project(
  jReadWrite
  VERSION 1.0
  DESCRIPTION "JSON Library for use with Mbed-OS"
  LANGUAGES C)

include(CTest)
enable_testing()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")
add_compile_definitions(JWRITE_STACK_DEPTH=10)

add_library(${PROJECT_NAME} source/jRead.c source/jWrite.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY C_STANDARD 90)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(test)
