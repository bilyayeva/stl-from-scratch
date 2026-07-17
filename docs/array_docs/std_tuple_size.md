# `std::tuple_size<sfs::array>`

`std::tuple_size` provides access to the number of elements in an `sfs::array` as a compile-time constant expression.

```cpp
template<class T, std::size_t N>
struct tuple_size<sfs::array<T, N>> : std::integral_constant<std::size_t, N> {};
```

## Parameters

This type trait does not have any parameters.

## Return value

Provides a compile-time constant `value` equal to the number of elements in the array.

## Exceptions

This type trait does not throw exceptions.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <tuple>
#include <sfs/array.hpp>

int main() {
    using array_type = sfs::array<int, 3>;

    static_assert(std::tuple_size<array_type>::value == 3);

    return 0;
}
```

For more examples, see: [std_tuple_size_examples.cpp](../../examples/array_examples/std_tuple_size_examples.cpp)