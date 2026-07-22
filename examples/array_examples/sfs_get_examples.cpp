#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Access and modify elements by compile-time index
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << sfs::get<0>(a1) << ' '
              << sfs::get<1>(a1) << ' '
              << sfs::get<2>(a1) << '\n';
    // Output: 1 2 3

    sfs::get<0>(a1) += 10;

    std::cout << sfs::get<0>(a1) << '\n';
    // Output: 11

    // 2. Access an element of a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    std::cout << sfs::get<0>(a2) << ' '
              << sfs::get<1>(a2) << ' '
              << sfs::get<2>(a2) << '\n';
    // Output: 10 20 30

    // sfs::get<1>(a2) += 10; // Compilation error

    // 3. Invalid compile-time index
    // sfs::get<3>(a1); // Compilation error: index is out of bounds

    // 4. Access an empty array
    [[maybe_unused]] sfs::array<int, 0> a3{};

    // sfs::get<0>(a3); // Compilation error: an empty array has no elements

    return 0;
}