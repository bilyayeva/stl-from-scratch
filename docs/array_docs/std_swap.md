# `std::swap(sfs::array)`

It provides an overload of the `std::swap` algorithm for `sfs::array`. `std::swap()` exchanges the contents of the `lhs` array with the contents of the `rhs` array.

This overload forwards the operation to `sfs::array::swap()`.

```cpp
template<class T, std::size_t N>
constexpr void swap(sfs::array<T, N>& lhs, sfs::array<T, N>& rhs) noexcept(noexcept(lhs.swap(rhs)));
```

## Parameters

- `lhs` : first array to exchange contents.
- `rhs` : second array to exchange contents.

## Return value

This function does not have any return value.

## Exceptions

This function does not throw exceptions if swapping elements does not throw.

Otherwise, it may throw an exception during element swapping.

## Complexity

Linear time complexity: **O(N)**.

## Basic Example

```cpp
#include <iostream>
#include <utility>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};
    sfs::array<int, 3> a2 = {4, 5, 6};

    std::swap(a1, a2);

    std::cout << a1[0] << ' '
              << a1[1] << ' '
              << a1[2] << '\n';

    return 0;
}
```

Output:

```text
4 5 6
```

For more examples, see: [std_swap_examples.cpp](../../examples/array_examples/std_swap_examples.cpp)