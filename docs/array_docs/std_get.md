# `std::get(sfs::array<T,N>)`

`std::get()` accesses the `I`'th element of an array through its tuple-like interface.

```cpp
template<std::size_t I, class T, std::size_t N>
constexpr T& get(sfs::array<T,N>& a) noexcept;

template<std::size_t I, class T, std::size_t N>
constexpr T&& get(sfs::array<T,N>&& a) noexcept;

template<std::size_t I, class T, std::size_t N>
constexpr const T& get(const sfs::array<T,N>& a) noexcept;

template<std::size_t I, class T, std::size_t N>
constexpr const T&& get(const sfs::array<T,N>&& a) noexcept;
```

## Parameters

- `a` : the array to access.

## Return value

Returns a reference to the `I`'th element of the given array.

## Exceptions

This function does not throw exceptions.

If `I` is greater than or equal to the array size, the compiler generates an error.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <iostream>
#include <tuple>
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> a1 = {1, 2, 3};

    std::cout << std::get<0>(a1) << '\n';

    return 0;
}
```

Output:

```text
1
```

For more examples, see: [std_get_examples.cpp]()