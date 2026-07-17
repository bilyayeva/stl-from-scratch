# `sfs::array<T,N>::begin`, `sfs::array<T,N>::cbegin`

`begin()` returns an iterator to the first element of the array. `cbegin()` always  returns a const iterator to the first element, which prevents modifying the elements through the iterator.

```cpp
constexpr iterator begin() noexcept;
constexpr const_iterator begin() const noexcept;
constexpr const_iterator cbegin() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns an iterator to the first element:
- `iterator` when called on a non-const array using `begin()`.
- `const_iterator` when called on a const array or using `cbegin()`.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. The returned iterator is equal to `end()`. In this implementation, both `begin()` and `end()` return `nullptr`.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << *a1.begin() << '\n';

    return 0;
}
```

Output:

```text
1
```

For more examples, see: [begin_examples.cpp](../../examples/array_examples/begin_examples.cpp)