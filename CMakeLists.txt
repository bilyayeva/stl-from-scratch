cmake_minimum_required(VERSION 3.15)
project(stl-from-scratch LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(array_test tests/array_test.cpp)
target_include_directories(array_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(initialization_examples examples/array_examples/initialization_examples.cpp)
target_include_directories(initialization_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(at_examples examples/array_examples/at_examples.cpp)
target_include_directories(at_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(operator_subscript_examples examples/array_examples/operator_subscript_examples.cpp)
target_include_directories(operator_subscript_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(front_examples examples/array_examples/front_examples.cpp)
target_include_directories(front_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(back_examples examples/array_examples/back_examples.cpp)
target_include_directories(back_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(data_examples examples/array_examples/data_examples.cpp)
target_include_directories(data_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(begin_examples examples/array_examples/begin_examples.cpp)
target_include_directories(begin_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(end_examples examples/array_examples/end_examples.cpp)
target_include_directories(end_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(rbegin_examples examples/array_examples/rbegin_examples.cpp)
target_include_directories(rbegin_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(rend_examples examples/array_examples/rend_examples.cpp)
target_include_directories(rend_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(empty_examples examples/array_examples/empty_examples.cpp)
target_include_directories(empty_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(size_examples examples/array_examples/size_examples.cpp)
target_include_directories(size_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(max_size_examples examples/array_examples/max_size_examples.cpp)
target_include_directories(max_size_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(fill_examples examples/array_examples/fill_examples.cpp)
target_include_directories(fill_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(swap_examples examples/array_examples/swap_examples.cpp)
target_include_directories(swap_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(comparison_operators_examples examples/array_examples/comparison_operators_examples.cpp)
target_include_directories(comparison_operators_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(std_get_examples examples/array_examples/std_get_examples.cpp)
target_include_directories(std_get_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(sfs_swap_examples examples/array_examples/sfs_swap_examples.cpp)
target_include_directories(sfs_swap_examples PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Windows
if (MSVC)   
    target_compile_options(array_test PRIVATE /W4 /WX)
# Linux/Mac
else()
    target_compile_options(array_test PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()