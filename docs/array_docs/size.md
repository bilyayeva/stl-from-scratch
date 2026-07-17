# `sfs::array<T,N>::size`

`size()` returns the number of elements in the array.

```cpp
constexpr size_type size() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns the number of elements in the array as a `size_type` value.

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

    std::cout << a1.size() << '\n';

    return 0;
}
```

Output:

```text
3
```

For more examples, see: [size_examples.cpp](../../examples/array_examples/size_examples.cpp)