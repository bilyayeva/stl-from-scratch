#include <cstddef>
#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Initialize using direct-list initialization
    sfs::array<int, 5> a1{1, 2, 3, 4, 5};

    for (std::size_t i{0}; i < a1.size(); ++i) {
        std::cout << a1.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    // 2. Initialize using copy-list initialization
    sfs::array<int, 5> a2 = {1, 2, 3, 4, 5};

    for (std::size_t i{0}; i < a2.size(); ++i) {
        std::cout << a2.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    // 3. Initialize using double braces
    sfs::array<int, 5> a3{{1, 2, 3, 4, 5}};

    for (std::size_t i{0}; i < a3.size(); ++i) {
        std::cout << a3.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    // 4. Deduce the element type and size
    sfs::array a4 = {1, 2, 3, 4, 5};

    for (std::size_t i{0}; i < a4.size(); ++i) {
        std::cout << a4.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    // 5. Copy an existing array
    sfs::array a5 = a4;

    for (std::size_t i{0}; i < a5.size(); ++i) {
        std::cout << a5.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    // 6. Value-initialize every element
    sfs::array<int, 5> a6{};

    for (std::size_t i{0}; i < a6.size(); ++i) {
        std::cout << a6.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 0 0 0 0 0

    // 7. Initialize the first elements and value-initialize the rest
    sfs::array<int, 5> a7 = {1, 2};

    for (std::size_t i{0}; i < a7.size(); ++i) {
        std::cout << a7.at(i) << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 0 0 0

    // 8. Initialize an empty array
    [[maybe_unused]] sfs::array<int, 0> a8{};

    return 0;
}