# `sfs::array<T,N>::operator[]`

`operator[]` provides access to an element at the specified position `pos`. Unlike `at()`, this method does not perform bounds checking. Accessing an element outside the valid range results in **undefined behavior**.

```cpp
constexpr reference operator[](size_type pos);
constexpr const_reference operator[](size_type pos) const;
```

## Parameters

- `pos` : index of the element to access. The parameter has type `size_type`, which means that it cannot represent negative values.

## Return value

Returns a reference to the requested element:
- `T&` when called on a non-const array.
- `const T&` when called on a const array.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << a1[0] << ' '
              << a1[1] << ' '
              << a1[2] << '\n';

    return 0;
}
```

Output:

```text
1 2 3
```

For more examples, see: [operator_subscript_examples.cpp]()