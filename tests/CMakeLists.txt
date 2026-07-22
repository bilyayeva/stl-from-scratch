add_executable(array_test array_test.cpp)
target_link_libraries(array_test PRIVATE sfs)

add_test(NAME array_test COMMAND array_test)

# Windows
if (MSVC)   
    target_compile_options(array_test PRIVATE /W4 /WX)
# Linux/Mac
else()
    target_compile_options(array_test PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()