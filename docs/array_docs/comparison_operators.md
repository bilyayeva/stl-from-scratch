# `sfs::array<T,N>::operator==`, `sfs::array<T,N>::operator<=>`

`operator==` checks whether the contents of `lhs` and `rhs` arrays are equal. Both arrays must have the same size.

`operator<=>` compares the contents of `lhs` and `rhs` arrays lexicographically.

```cpp
constexpr bool operator==(const array& lhs, const array& rhs);
constexpr auto operator<=>(const array& lhs, const array& rhs);
```

## Parameters

- `lhs` : first array to compare.
- `rhs` : second array to compare.

## Return value

`operator==` returns a `bool` value:
- `true` if all corresponding elements of `lhs` and `rhs` are equal.
- `false` if at least one corresponding element is different.

`operator<=>` returns a comparison category type (`std::strong_ordering`, `std::weak_ordering`, or `std::partial_ordering`) depending on the element type.

## Exceptions

These methods do not throw exceptions.

## Complexity

Linear time complexity: **O(N)**.

## Basic Example

```cpp
#include <iostream>
#include <ios>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};
    sfs::array<int, 3> a2 = {4, 5, 6};

    std::cout << std::boolalpha << (a1 == a2) << '\n';

    auto result = a1 <=> a2;

    if (result < 0) {
        std::cout << "a1 is smaller\n";
    }

    return 0;
}
```

Output:

```text
false
a1 is smaller
```

For more examples, see: [comparison_operators_examples.cpp](../../examples/array_examples/comparison_operators_examples.cpp)