# Deduction Guides for `sfs::array`

Deduction guides allow the compiler to deduce the element type and the size of an `sfs::array` from the constructor arguments.

```cpp
template<class T, class... U>
array(T, U...) -> array<T, 1 + sizeof...(U)>;
```

## Parameters

This method does not have any parameters.

## Return value

Deduces the type of the array as `sfs::array<T, N>`, where `N` is the number of arguments.

## Exceptions

Compilation fails if the arguments do not have the same type.

## Complexity

Constant time complexity: **O(1)**.

## Basic Example

```cpp
#include <iostream>
#include <sfs/array.hpp>

int main() {
    sfs::array a = {1, 2, 3};

    std::cout << a.size() << '\n';

    return 0;
}
```

Output:

```text
3
```

For more examples, see: [deduction_guides_examples.cpp](../../examples/array_examples/deduction_guides_examples.cpp)