# `sfs::array<T,N>::rbegin`, `sfs::array<T,N>::crbegin`

`rbegin()` returns a reverse iterator to the first element of the reversed array, which corresponds to the last element of the original array. `crbegin()` returns a const reverse iterator to the first element of the reversed array, which prevents modifying the elements through the iterator.

```cpp
constexpr reverse_iterator rbegin() noexcept;
constexpr const_reverse_iterator rbegin() const noexcept;
constexpr const_reverse_iterator crbegin() const noexcept;
```

## Parameters

This method does not have any parameters.

## Return value

Returns a reverse iterator to the first element of the reversed array:
- `reverse_iterator` when called on a non-const array using `rbegin()`.
- `const_reverse_iterator` when called on a const array or using `crbegin()`.

## Exceptions

This method does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Notes

When `N == 0`, the array does not contain any elements. The returned iterator is equal to `rend()`. In this implementation, both `rbegin()` and `rend()` are constructed from `end()`, which is `nullptr`.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << *a1.rbegin() << '\n';

    return 0;
}
```

Output:

```text
3
```

For more examples, see: [rbegin_examples.cpp]()