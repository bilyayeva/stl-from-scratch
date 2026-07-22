# `sfs::array<T,N>::fill`

`fill()` assigns the given `value` to every element of the array.

```cpp
constexpr void fill(const_reference value);
```

## Parameters

- `value` : the value to assign to every element of the array.

## Return value

This method does not have any return value.

## Exceptions

May throw an exception if type `T` throws.

## Complexity

Linear time complexity: **O(N)**.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    a1.fill(0);

    std::cout << a1[0] << ' '
              << a1[1] << ' '
              << a1[2] << '\n';

    return 0;
}
```

Output:

```text
0 0 0
```

For more examples, see: [fill_examples.cpp](../../examples/array_examples/fill_examples.cpp)