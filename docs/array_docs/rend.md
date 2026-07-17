# `sfs::array<T,N>::rend`, `sfs::array<T,N>::crend`

`rend()` returns a reverse iterator to the position after the last element of the reversed array, which corresponds to the position before the first element of the original array. `crend()` returns a const reverse iterator to the same position, which prevents modifying the elements through the iterator.

```cpp
constexpr reverse_iterator rend() noexcept;
constexpr const_reverse_iterator rend() const noexcept;
constexpr const_reverse_iterator crend() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns a reverse iterator the to position after the last element of the reversed array:
- `reverse_iterator` when called on a non-const array using `rend()`.
- `const_reverse_iterator` when called on a const array or using `crend()`.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. The returned iterator is equal to `rbegin()`. In this implementation, both `rbegin()` and `rend()` are constructed from `end()`, which is `nullptr`.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << *(a1.rend() - 1) << '\n';

    return 0;
}
```

Output:

```text
1
```

For more examples, see: [rend_examples.cpp]()