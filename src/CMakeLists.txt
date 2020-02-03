cmake_minimum_required(VERSION 3.0)

project(ADSLecture6_Demos CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_CXX_STANDARD 14)

# the following options prevent compiler-optimization issues that are unwanted in an edu process
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

#### the list of targets ####
add_executable(ex1_matrix 
        ex1_matrix/main.cpp
        ex1_matrix/matrix.cpp
        ex1_matrix/matrix.h
    )

add_executable(ex2_func_template ex2_func_template/main.cpp)

add_executable(ex3_matrix_template
        ex3_matrix_template/main.cpp
        ex3_matrix_template/matrix.hpp
    )