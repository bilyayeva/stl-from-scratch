# `sfs::to_array`

`to_array()` creates an `sfs::array` from a built-in C-style array.

```cpp
template<class T, std::size_t N>
constexpr sfs::array<std::remove_cv_t<T>, N> to_array(T (&a)[N]) noexcept(std::is_nothrow_constructible_v<T, T&>);

template<class T, std::size_t N>
constexpr sfs::array<std::remove_cv_t<T>, N> to_array(T (&&a)[N]) noexcept(std::is_nothrow_constructible_v<T, T&&>);
```

## Parameters

- `a` : the built-in array to convert into `sfs::array`.

## Return value

Returns a new `sfs::array` containing copies or moved values from the given array.

## Exceptions

This function does not throw exceptions if the element type is nothrow constructible.

Otherwise, it may throw an exception during element construction.

## Complexity

Linear time complexity: **O(N)**.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    int raw_array[] = {1, 2, 3};

    sfs::array<int, 3> a1 = sfs::to_array(raw_array);

    std::cout << a1[0] << ' '
              << a1[1] << ' '
              << a1[2] << '\n';

    return 0;
}
```

Output:

```text
1 2 3
```

For more examples, see: [to_array_examples.cpp](../../examples/array_examples/to_array_examples.cpp)