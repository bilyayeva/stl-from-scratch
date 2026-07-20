#include <iostream>
#include <algorithm>
#include <sfs/array.hpp>

int main() {
    std::cout << std::boolalpha;

    // 1. Access and modify the last element in reverse order
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    std::cout << *(a1.rend() - 1) << '\n';
    // Output: 1

    *(a1.rend() - 1) += 10;

    std::cout << *(a1.rend() - 1) << '\n';
    // Output: 11

    // 2. Access the last element in reverse order through a const iterator
    std::cout << *(a1.crend() - 1) << '\n';
    // Output: 11

    // *(a1.crend() - 1) += 10; // Compilation error

    // A non-empty array has different reverse beginning and end iterators
    std::cout << (a1.rend() == a1.rbegin()) << '\n';
    // Output: false

    // A non-empty array has different const reverse beginning and end iterators
    std::cout << (a1.crend() == a1.crbegin()) << '\n';
    // Output: false

    // 3. Iterate in reverse order using a standard algorithm
    std::for_each(a1.crbegin(), a1.crend(), [](int element) {
        std::cout << element << ' ';
    });
    std::cout << '\n';
    // Output: 5 4 3 2 11

    // 4. Call rend() on a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    // rend() returns a const reverse iterator when the array is const
    auto it = a2.rend();

    std::cout << *(it - 1) << '\n';
    // Output: 10

    // *(it - 1) += 10; // Compilation error

    // 5. Compare the reverse iterators of an empty array
    sfs::array<int, 0> a3{};

    std::cout << (a3.rend() == a3.rbegin()) << '\n';
    // Output: true

    return 0;
}