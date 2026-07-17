# `std::tuple_element<sfs::array>`

`std::tuple_element` provides compile-time access to the type of the `I`'th element of an `sfs::array` through its tuple-like interface.

```cpp
template<std::size_t I, class T, std::size_t N>
struct tuple_element<I, sfs::array<T, N>>;
```

## Parameters

This type trait does not have any parameters.

## Return value

Provides a member type `type` representing the type of the `I`'th element.

## Exceptions

This type trait does not throw exceptions.

A compile-time error occurs if `I` is greater than or equal to `N`.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <tuple>
#include <type_traits>
#include <sfs/array.hpp>

int main() {
    using array_type = sfs::array<int, 3>;

    static_assert(std::is_same_v<std::tuple_element_t<0, array_type>, int>);

    return 0;
}
```

For more examples, see: [std_tuple_element_examples.cpp](../../examples/array_examples/std_tuple_element_examples.cpp)