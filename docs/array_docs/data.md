# `sfs::array<T, N>::data`

`data()` provides direct access to the underlying array storage by returning a pointer to the first element.

```cpp
constexpr T* data() noexcept;
constexpr const T* data() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns a pointer to the first element:
- `T*` when called on a non-const array.
- `const T*` when called on a const array.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. In this case, `data()` returns `nullptr`. The returned pointer must not be used to access memory.

## Basic Example

```cpp
#include <iostream>
#include <cstddef>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    const int* ptr = a1.data();

    for (std::size_t i{0}; i < a1.size(); ++i) {
        std::cout << ptr[i] << ' ';
    }

    std::cout << '\n';

    return 0;
}
```

Output:

```text
1 2 3
```

For more examples, see: [data_examples.cpp]()