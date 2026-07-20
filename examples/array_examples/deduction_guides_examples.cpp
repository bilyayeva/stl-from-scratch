#include <iostream>
#include <type_traits>
#include <sfs/array.hpp>

int main() {
    // 1. Deduce an array of five integers
    sfs::array a1 = {1, 2, 3, 4, 5};

    static_assert(std::is_same_v<decltype(a1), sfs::array<int, 5>>);

    std::cout << a1.size() << '\n';
    // Output: 5

    // 2. Deduce an array of three doubles
    sfs::array a2 = {1.5, 2.5, 3.5};

    static_assert(std::is_same_v<decltype(a2), sfs::array<double, 3>>);

    for (const double element : a2) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 1.5 2.5 3.5

    // 3. Deduce an array of characters
    sfs::array a3 = {'A', 'B', 'C'};

    static_assert(std::is_same_v<decltype(a3), sfs::array<char, 3>>);

    for (const char element : a3) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: A B C

    // All elements must have the same type
    // sfs::array a4 = {1, 2.5, 3};
    // Compilation error: the element types are different

    return 0;
}