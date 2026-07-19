cmake_minimum_required(VERSION 3.15)
project(stl-from-scratch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(array_test tests/array_test.cpp)
target_include_directories(array_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(at_examples examples/array_examples/at_examples.cpp)
target_include_directories(at_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Windows
if (MSVC)   
    target_compile_options(array_test PRIVATE /W4 /WX)
# Linux/Mac
else()
    target_compile_options(array_test PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()