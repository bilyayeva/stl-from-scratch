#include <iostream>
#include <tuple>
#include <sfs/array.hpp>

int main() {
    // 1. Get the array size at compile time
    constexpr std::size_t sz1 = std::tuple_size_v<sfs::array<int, 5>>;

    std::cout << sz1 << '\n';
    // Output: 5

    static_assert(std::tuple_size_v<sfs::array<int, 5>> == 5);

    // 2. Get the size of an empty array at compile time
    using empty_array_type = sfs::array<int, 0>;

    constexpr std::size_t sz2 = std::tuple_size_v<empty_array_type>;

    std::cout << sz2 << '\n';
    // Output: 0

    static_assert(std::tuple_size_v<empty_array_type> == 0);

    return 0;
}