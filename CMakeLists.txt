cmake_minimum_required(VERSION 3.15)
project(stl-from-scratch LANGUAGES CXX)

add_library(sfs INTERFACE)
target_include_directories(sfs INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(sfs INTERFACE cxx_std_20)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_EXAMPLES "Build examples" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples/array_examples)
endif()