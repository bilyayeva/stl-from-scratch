# What is `std::array`?

`std::array` is a container in the C++ standard library that wraps around a fixed-size *C-style array* (`char array[10];`). It behaves similarly to a raw array but with **additional functionality and safety features**, making it much more convenient to use.

*Note: Also known as a regular array, raw array, or built-in array.*

Key characteristics of `std::array`:

* **Fixed size at compile time**: The size of an `std::array` is known at the time you declare it, which makes it perfect for situations where the number of elements is fixed.

* **Contiguous memory storage**: Just like built-in arrays, all elements of `std::array` are stored in contiguous memory blocks. This means that accessing and iterating over them is very easy and efficient.

* **Stored on the stack (*not the heap*)**: Because its size is known at *compile time*, `std::array` does not require dynamic memory allocation and is typically stored on the *stack* when created as a local variable.

* **Supports iterators**: You can use standard algorithms (`#include <algorithm>`), range-based for loops, and other iterator-based functions with `std::array`.

* **Provides additional functionality**: Unlike a raw array, `std::array` has built-in member functions including `size()`, safe access with `at()`, and others.

## Basic example:

```c++
#include <array>
#include <sfs/array.hpp>

int main() {
    // Standard Library implementation
    std::array<int, 3> a1 = {1, 2, 3};
    
    // Equivalent implementation using sfs
    sfs::array<int, 3> a2 = {4, 5, 6};
    
    return 0;
}
```

For more implementation details, see:
* [array_guide](array_guide.md) *(Work in progress)*
* [array_examples](../../examples/array_examples/) *(Work in progress)*

## Supported Operations

`std::array` provides several groups of operations:

### Element Access

| Function | Description |
| :--- | :--- |
| `at()` | Accesses an element **with** bounds checking. |
| `operator[]` | Accesses an element **without** bounds checking. |
| `front()` | Returns the first element. |
| `back()` | Returns the last element. |
| `data()` | Returns a pointer to the underlying array storage. |

### Iterators

| Function | Description |
| :--- | :--- |
| `begin()` <br> `cbegin()` | Returns an iterator to the first element. |
| `end()` <br> `cend()` | Returns an iterator to the position after the last element. |
| `rbegin()` <br> `crbegin()` | Returns a *reverse* iterator to the first element. |
| `rend()` <br> `crend()` | Returns a *reverse* iterator to the position after the last element. |

## References

The information about `std::array` behavior and requirements is based on [cppreference](https://en.cppreference.com/):

- [std::array](https://en.cppreference.com/w/cpp/container/array)