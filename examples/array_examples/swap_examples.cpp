#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Swap the elements of two arrays
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};
    sfs::array<int, 5> a2 = {6, 7, 8, 9, 10};

    // Print the arrays before swapping
    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    for (const int& element : a2) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 6 7 8 9 10

    a1.swap(a2);

    // Print the arrays after swapping
    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 6 7 8 9 10

    for (const int& element : a2) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 5

    // 2. Swap two empty arrays
    sfs::array<int, 0> a3{};
    sfs::array<int, 0> a4{};

    // This operation has no effect
    a3.swap(a4);

    for (const int& element : a3) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: an empty line

    for (const int& element : a4) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: an empty line

    return 0;
}