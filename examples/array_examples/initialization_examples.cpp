#include <cstddef>
#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Initialize with an explicit element type and size
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    for (std::size_t i{0}; i < a1.size(); ++i) {
        std::cout << a1.at(i) << ' ';
    }
    std::cout << '\n';

    // 2. Initialize using double braces
    sfs::array<int, 5> a2{{1, 2, 3, 4, 5}};

    for (std::size_t i{0}; i < a2.size(); ++i) {
        std::cout << a2.at(i) << ' ';
    }
    std::cout << '\n';

    // 3. Deduce the element type and size
    sfs::array a3 = {1, 2, 3, 4, 5};

    for (std::size_t i{0}; i < a3.size(); ++i) {
        std::cout << a3.at(i) << ' ';
    }
    std::cout << '\n';

    // 4. Copy an existing array
    sfs::array a4 = a3;

    for (std::size_t i{0}; i < a4.size(); ++i) {
        std::cout << a4.at(i) << ' ';
    }
    std::cout << '\n';

    // 5. Value-initialize every element
    sfs::array<int, 5> a5{};

    for (const int element : a5) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    // 6. Initialize the first elements and value-initialize the rest
    sfs::array<int, 5> a6 = {1, 2};

    for (const int element : a6) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    // 7. Initialize an empty array
    [[maybe_unused]] sfs::array<int, 0> a7{};

    return 0;
}