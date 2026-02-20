cmake_minimum_required(VERSION 3.16.3)

project(libraries DESCRIPTION "Libraries for data structures in C" LANGUAGES C)

file(GLOB LIBC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")
add_library(${PROJECT_NAME} ${LIBC_FILES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)