#include <iostream>
#include <sfs/array.hpp>

int main() {
    // Convert a built-in array into an sfs::array
    int ca1[] = {1, 2, 3};

    // The element type and array size are deduced
    auto a1 = sfs::to_array(ca1);

    for (const int& element : a1) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
    // Output: 1 2 3

    return 0;
}