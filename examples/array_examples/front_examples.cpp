#include <iostream>
#include <sfs/array.hpp>

int main() {
    // 1. Access and modify the first element
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    // Read the first element
    std::cout << a1.front() << '\n';

    // Modify the first element via front()
    a1.front() += 10;

    // Print the modified first element
    std::cout << a1.front() << '\n';

    // 2. Access the first element of a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    std::cout << a2.front() << '\n';

    // An empty array does not contain a first element
    [[maybe_unused]] sfs::array<int, 0> a3{};
    // a3.front(); // Undefined behavior

    return 0;
}