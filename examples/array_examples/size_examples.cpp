#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Get the size of a non-empty array
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    std::cout << a1.size() << '\n';
    // Output: 5

    // 2. Get the size of a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    std::cout << a2.size() << '\n';
    // Output: 3

    // 3. Get the size of an empty array
    const sfs::array<int, 0> a3{};

    std::cout << a3.size() << '\n';
    // Output: 0

    return 0;
}