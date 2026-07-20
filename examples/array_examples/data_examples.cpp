#include <iostream>
#include <cassert>
#include <cstddef>
#include <sfs/array.hpp>

int main() {
    // 1. Access and modify elements through a pointer
    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};
    int* p1 = a1.data();

    // Read elements using pointer arithmetic
    for (std::size_t i{0}; i < a1.size(); ++i) {
        std::cout << *(p1 + i) << ' ';
    }
    std::cout << '\n';

    // Modify elements through the returned pointer
    for (std::size_t i{0}; i < a1.size(); ++i) {
        *(p1 + i) += 1;
    }

    // Print the modified array
    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';

    // 2. Access elements of a non-modifiable array
    const sfs::array<int, 3> a2 = {10, 20, 30};
    const int* p2 = a2.data();

    for (std::size_t i{0}; i < a2.size(); ++i) {
        std::cout << *(p2 + i) << ' ';
    }
    std::cout << '\n';

    // 3. Obtain the data pointer of an empty array
    sfs::array<int, 0> a3{};
    int* p3 = a3.data();

    // sfs::array<T, 0>::data() returns nullptr
    assert(p3 == nullptr);

    return 0;
}