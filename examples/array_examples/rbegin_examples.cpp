#include <iostream>
#include <algorithm>
#include <sfs/array.hpp>

int main() {
    std::cout << std::boolalpha;

    // 1. Access and modify the first element in reverse order
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    std::cout << *a1.rbegin() << '\n';
    // Output: 5

    *a1.rbegin() += 10;

    std::cout << *a1.rbegin() << '\n';
    // Output: 15

    // 2. Access the first element in reverse order through a const iterator
    std::cout << *a1.crbegin() << '\n';
    // Output: 15

    // *a1.crbegin() += 10; // Compilation error

    // A non-empty array has different reverse beginning and end iterators
    std::cout << (a1.rbegin() == a1.rend()) << '\n';
    // Output: false

    // A non-empty array has different const reverse beginning and end iterators
    std::cout << (a1.crbegin() == a1.crend()) << '\n';
    // Output: false

    // 3. Iterate in reverse order using a standard algorithm
    std::for_each(a1.crbegin(), a1.crend(), [](int element) {
        std::cout << element << ' ';
    });
    std::cout << '\n';
    // Output: 15 4 3 2 1

    // 4. Call rbegin() on a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    // rbegin() returns a const reverse iterator when the array is const
    auto it = a2.rbegin();

    std::cout << *it << '\n';
    // Output: 30

    // *it += 10; // Compilation error

    // 5. Compare the reverse iterators of an empty array
    sfs::array<int, 0> a3{};

    std::cout << (a3.rbegin() == a3.rend()) << '\n';
    // Output: true

    return 0;
}