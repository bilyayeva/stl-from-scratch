# `sfs::array<T,N>::max_size`

`max_size()` returns the maximum number of elements the array can contain. For `sfs::array`, this value is always equal to `size()`.

```cpp
constexpr size_type max_size() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns the maximum number of elements the array can contain as a `size_type` value.

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

    std::cout << a1.max_size() << '\n';

    return 0;
}
```

Output:

```text
3
```

For more examples, see: [max_size_examples.cpp]()