#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Access and modify the last element
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    // Read the last element
    std::cout << a1.back() << '\n';

    // Modify the last element via back()
    a1.back() += 10;

    // Print the modified last element
    std::cout << a1.back() << '\n';

    // 2. Access the last element of a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    std::cout << a2.back() << '\n';

    // An empty array does not contain a last element
    [[maybe_unused]] sfs::array<int, 0> a3{};
    // a3.back(); // Undefined behavior

    return 0;
}