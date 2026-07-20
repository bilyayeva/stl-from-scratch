#include <iostream>
#include <cstddef>
#include <sfs/array.hpp>

int main() {
    // 1. Access and modify elements
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    // Read elements without bounds checking
    for (std::size_t i{0}; i < a1.size(); ++i) {
        std::cout << a1[i] << ' ';
    }
    std::cout << '\n';

    // Modify elements via operator[]
    for (std::size_t i{0}; i < a1.size(); ++i) {
        a1[i] += 10;
    }

    // Print the modified elements
    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    // 2. Access elements from a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    for (std::size_t i{0}; i < a2.size(); ++i) {
        std::cout << a2[i] << ' ';
    }
    std::cout << '\n';

    // operator[] does not perform bounds checking
    // a1[5]; // Undefined behavior: valid indices are 0 through 4

    // An empty array does not contain any valid elements
    [[maybe_unused]] sfs::array<int, 0> a3{};
    // a3[0]; // Undefined behavior

    return 0;
}