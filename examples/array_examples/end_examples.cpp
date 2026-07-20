#include <iostream>
#include <algorithm>
#include <sfs/array.hpp>

int main() {
    std::cout << std::boolalpha;

    // 1. Access and modify the last element
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    std::cout << *(a1.end() - 1) << '\n';
    // Output: 5

    *(a1.end() - 1) += 10;

    std::cout << *(a1.end() - 1) << '\n';
    // Output: 15

    // 2. Access the last element through a const iterator
    std::cout << *(a1.cend() - 1) << '\n';
    // Output: 15

    // *(a1.cend() - 1) += 10; // Compilation error

    // A non-empty array has different beginning and end iterators
    std::cout << (a1.end() == a1.begin()) << '\n';
    // Output: false

    // A non-empty array has different const beginning and end iterators
    std::cout << (a1.cend() == a1.cbegin()) << '\n';
    // Output: false

    // 3. Iterate using a range-based loop
    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3 4 15

    // 4. Use const iterators with a standard algorithm
    std::for_each(a1.cbegin(), a1.cend(), [](int element) {
        std::cout << element << ' ';
    });
    std::cout << '\n';
    // Output: 1 2 3 4 15

    // 5. Call end() on a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    // end() returns a const iterator when the array is const
    auto it = a2.end();

    std::cout << *(it - 1) << '\n';
    // Output: 30

    // *(it - 1) += 10; // Compilation error

    // 6. Compare the iterators of an empty array
    sfs::array<int, 0> a3{};

    std::cout << (a3.end() == a3.begin()) << '\n';
    // Output: true

    return 0;
}