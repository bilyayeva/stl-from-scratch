# `sfs::array<T,N>::empty`

`empty()` checks whether the array contains no elements.

```cpp
constexpr bool empty() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns a `bool` value:
- `true` when the array contains no elements.
- `false` when the array contains one or more elements.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <iostream>
#include <ios>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << std::boolalpha << a1.empty() << '\n';

    return 0;
}
```

Output:

```text
false
```

For more examples, see: [empty_examples.cpp]()