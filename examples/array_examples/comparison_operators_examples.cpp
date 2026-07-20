#include <iostream>
#include <compare>
#include <sfs/array.hpp>

int main() {
    std::cout << std::boolalpha;

    sfs::array<int, 5> a1 = {1, 2, 3, 4, 5};
    sfs::array<int, 5> a2 = {5, 6, 7, 8, 9};

    // 1. Equality comparisons
    std::cout << (a1 == a2) << '\n';
    // Output: false

    std::cout << (a1 != a2) << '\n';
    // Output: true

    // 2. Relational comparisons
    std::cout << (a1 <= a2) << '\n';
    // Output: true

    std::cout << (a1 >= a2) << '\n';
    // Output: false

    std::cout << (a1 < a2) << '\n';
    // Output: true

    std::cout << (a1 > a2) << '\n';
    // Output: false

    // 3. Direct use of the three-way comparison operator
    const auto result = (a1 <=> a2);

    std::cout << (result < 0) << '\n';
    // Output: true

    std::cout << (result > 0) << '\n';
    // Output: false

    std::cout << (result == 0) << '\n';
    // Output: false

    // 4. Compare with a named comparison result
    std::cout << (result == std::strong_ordering::less) << '\n';
    // Output: true

    std::cout << (result == std::strong_ordering::equal) << '\n';
    // Output: false

    std::cout << (result == std::strong_ordering::greater) << '\n';
    // Output: false

    return 0;
}