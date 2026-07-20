#include <iostream>
#include <algorithm>
#include <sfs/array.hpp>

int main() {
    std::cout << std::boolalpha;

    // 1. Access and modify the first element
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};

    std::cout << *a1.begin() << '\n';
    // Output: 1

    *a1.begin() += 10;

    std::cout << *a1.begin() << '\n';
    // Output: 11

    // 2. Access elements through a const iterator
    std::cout << *a1.cbegin() << '\n';
    // Output: 11

    // *a1.cbegin() += 10; // Compilation error

    // A non-empty array has different beginning and end iterators
    std::cout << (a1.begin() == a1.end()) << '\n';
    // Output: false
    
    // A non-empty array has different const beginning and end iterators
    std::cout << (a1.cbegin() == a1.cend()) << '\n';
    // Output: false

    // 3. Iterate using a range-based loop
    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 11 2 3 4 5

    // 4. Use const iterators with a standard algorithm
    std::for_each(a1.cbegin(), a1.cend(), [](int element) {
        std::cout << element << ' ';
    });
    std::cout << '\n';
    // Output: 11 2 3 4 5

    // 5. Call begin() on a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};

    // begin() returns a const iterator when the array is const
    auto it = a2.begin();

    std::cout << *it << '\n';
    // Output: 10

    // *it += 10; // Compilation error

    // 6. Compare the iterators of an empty array
    sfs::array<int, 0> a3{};

    std::cout << (a3.begin() == a3.end()) << '\n';
    // Output: true

    return 0;
}