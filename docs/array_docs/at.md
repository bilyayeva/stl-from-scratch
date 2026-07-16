# `sfs::array<T, N>::at`

`at()` provides access to an element at the specified position `pos`. Unlike `operator[]`, this method performs bounds checking to ensure that the requested position is valid. If `pos` is greater than or equal to the size of the array, `std::out_of_range` is thrown.

```cpp
constexpr reference at(size_type pos);
constexpr const_reference at(size_type pos) const;
```

## Parameters

- `pos` : index of the element to access. The parameter has type `size_type`, which means that it cannot represent negative values.

## Return value

Returns a reference to the requested element:
- `T&` when called on a non-const array.
- `const T&` when called on a const array.

## Exceptions

Throws `std::out_of_range` if `pos` is greater than or equal to the size of the array.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << a1.at(0) << ' '
              << a1.at(1) << ' '
              << a1.at(2) << '\n';

    return 0;
}
```

Output:

```text
1 2 3
```

For more examples, see: [at_examples.cpp]()