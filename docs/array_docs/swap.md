# `sfs::array<T,N>::swap`

`swap()` exchanges the contents of the array with the contents of `other`.

```cpp
constexpr void swap(array& other) noexcept(std::is_nothrow_swappable_v<T>);
```

## Parameters

- `other` : the array to exchange contents with.

## Return value

This method does not have any return value.

## Exceptions

May throw an exception if swapping two elements of type `T` throws.

## Complexity

Linear time complexity: **O(N)**.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};
    sfs::array<int, 3> a2 = {4, 5, 6};

    a1.swap(a2);

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

For more examples, see: [swap_examples.cpp](../../examples/array_examples/swap_examples.cpp)