# `sfs::array<T, N>::front`

`front()` provides access to the first element of the array. Unlike `operator[]` or `at()`, it does not require an index because it always returns the first element.

```cpp
constexpr reference front();
constexpr const_reference front() const;
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

For more examples, see: [front_examples.cpp]()