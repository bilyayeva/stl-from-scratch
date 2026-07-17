# `sfs::array<T,N>::end`, `sfs::array<T,N>::cend`

`end()` returns an iterator to the position after the last element of the array. `cend()` always returns a const iterator to the position after the last element, which prevents modifying the elements through the iterator.

```cpp
constexpr iterator end() noexcept;
constexpr const_iterator end() const noexcept;
constexpr const_iterator cend() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns an iterator to the position after the last element:
- `iterator` when called on a non-const array using `end()`.
- `const_iterator` when called on a const array or using `cend()`.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. The returned iterator is `nullptr`. In this implementation, both `begin()` and `end()` return `nullptr`.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << *(a1.end() - 1) << '\n';

    return 0;
}
```

Output:

```text
3
```

For more examples, see: [end_examples.cpp](../../examples/array_examples/end_examples.cpp)