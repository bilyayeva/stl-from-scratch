#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <sfs/array.hpp>

int main() {
    // 1. Access and modify elements
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};
    
    // Read elements using bounds-checked access
    for (std::size_t i{0}; i < a1.size(); ++i) {
        std::cout << a1.at(i) << ' ';
    }
    std::cout << '\n';

    // Modify elements via at()
    for (std::size_t i{0}; i < a1.size(); ++i) {
        a1.at(i) += 10;
    }

    // Read elements using range-based loop
    for (const int& elem : a1) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';

    // An invalid position throws std::out_of_range
    try {
        std::cout << a1.at(5) << '\n';
    } catch (const std::out_of_range& error) {
        std::cerr << "Error: " << error.what() << '\n';
    }

    // 2. Access elements from a non-modifiable array
    const sfs::array<int, 3> a2 = {1, 2, 3};

    for (std::size_t i{0}; i < a2.size(); ++i) {
        std::cout << a2.at(i) << ' ';
    }
    std::cout << '\n';

    // 3. Access an empty array
    sfs::array<int, 0> a3{};

    // Every access attempt throws std::out_of_range
    try {
        std::cout << a3.at(0) << '\n';
    } catch (const std::out_of_range& error) {
        std::cerr << "Error: " << error.what() << '\n';
    }

    return 0;
}