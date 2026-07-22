# `sfs::array<T,N>::front`

`front()` provides access to the first element of the array. It does not require an index because the accessed position is always the first element.

```cpp
constexpr reference front() noexcept;
constexpr const_reference front() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns a reference to the first element:
- `T&` when called on a non-const array.
- `const T&` when called on a const array.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. Call `front()` causes undefined behavior.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << a1.front() << '\n';

    return 0;
}
```

Output:

```text
1
```

For more examples, see: [front_examples.cpp](../../examples/array_examples/front_examples.cpp)