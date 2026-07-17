# `sfs::array<T,N>::back`

`back()` provides access to the last element of the array. It does not require an index because the accessed position is always the last element.

```cpp
constexpr reference back();
constexpr const_reference back() const;
```

## Parameters

This method does not have any parameters.

## Return value

Returns a reference to the last element:
- `T&` when called on a non-const array.
- `const T&` when called on a const array.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. An exception `std::out_of_range` is thrown.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << a1.back() << '\n';

    return 0;
}
```

Output:

```text
3
```

For more examples, see: [back_examples.cpp]()