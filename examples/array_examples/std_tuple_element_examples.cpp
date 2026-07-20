#include <iostream>
#include <tuple>
#include <type_traits>
#include <sfs/array.hpp>

int main() {
    // 1. Get the element type of an integer array
    static_assert(std::is_same_v<std::tuple_element_t<0, sfs::array<int, 5>>, int>);

    std::tuple_element_t<0, sfs::array<int, 5>> value1 = 42;

    std::cout << value1 << '\n';
    // Output: 42

    // 2. Get the element type of a character array
    static_assert(std::is_same_v<std::tuple_element_t<2, sfs::array<char, 3>>, char>);

    std::tuple_element_t<2, sfs::array<char, 3>> value2 = 'A';

    std::cout << value2 << '\n';
    // Output: A

    // 3. Get the element type of a const array
    static_assert(std::is_same_v<std::tuple_element_t<1, const sfs::array<int, 3>>, const int>);

    // 4. An empty array does not have an element type
    // std::tuple_element_t<0, sfs::array<int, 0>> value3;
    // Compilation error: index is out of bounds

    return 0;
}