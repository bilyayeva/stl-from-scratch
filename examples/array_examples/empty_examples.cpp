#include <iostream>
#include <sfs/array.hpp>

int main() {
    std::cout << std::boolalpha;

    // 1. Check a non-empty array
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    std::cout << a1.empty() << '\n';
    // Output: false

    // 2. Check a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    std::cout << a2.empty() << '\n';
    // Output: false

    // 3. Check an empty array
    const sfs::array<int, 0> a3{};

    std::cout << a3.empty() << '\n';
    // Output: true

    return 0;
}