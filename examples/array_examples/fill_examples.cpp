#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Replace existing elements
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    a1.fill(15);

    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 15 15 15 15 15

    // 2. Initialize every element using fill()
    sfs::array<int, 5> a2;

    a2.fill(16);

    for (const int& element : a2) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 16 16 16 16 16

    // 3. Call fill() on an empty array
    sfs::array<int, 0> a3{};

    // No elements are modified
    a3.fill(17);

    for (const int& element : a3) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: an empty line

    return 0;
}