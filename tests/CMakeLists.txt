cmake_minimum_required(VERSION 3.16.3)

project(tests DESCRIPTION "Tests of data structures in C" LANGUAGES C)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/tests.c)

target_link_libraries(${PROJECT_NAME} PRIVATE libraries)