# What is `std::array`?

`std::array` is a container in the C++ standard library that wraps around a fixed-size *C-style array* (`char arr[10];`). It behaves similarly to a raw array but with **additional functionality and safety features**, making it much more convenient to use.

*Note: C-style array is also known as a regular array, raw array, or built-in array.*

## About `sfs::array`

`sfs::array` is a from-scratch implementation of `std::array` that provides the same interface, requirements, and behavior specified by the C++ standard.

The goal of this implementation is to recreate the functionality of `std::array` while maintaining compatibility with the standard container interface.

Key characteristics of `sfs::array`:

* **Fixed size at compile time**: The size of an `sfs::array` is known at the time you declare it, which makes it suitable for situations where the number of elements is fixed.

* **Contiguous memory storage**: Just like built-in arrays, all elements of `sfs::array` are stored in contiguous memory. This means that accessing and iterating over them is efficient.

* **Stored on the stack (*not the heap*)**: Because its size is known at *compile time*, `sfs::array` does not require dynamic memory allocation and is typically stored on the *stack* when created as a local variable.

* **Supports iterators**: You can use standard algorithms (`#include <algorithm>`), range-based for loops, and other iterator-based functions with `sfs::array`.

* **Provides additional functionality**: Unlike a raw array, `sfs::array` provides member functions including `size()`, bounds-checked access with `at()`, and others.

## Basic Example

```cpp
#include <array>            // Standard Library
#include <sfs/array.hpp>    // Custom Implementation

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

`sfs::array` provides the following groups of operations:

### Initialization

For examples of different ways to initialize an `sfs::array`, see [`initialization_examples.cpp`](../../examples/array_examples/initialization_examples.cpp).

### Element Access

| Function | Description |
| :--- | :--- |
| [`at()`](at.md) | Accesses an element **with** bounds checking. |
| [`operator[]`](operator_subscript.md) | Accesses an element **without** bounds checking. |
| [`front()`](front.md) | Returns the first element. |
| [`back()`](back.md) | Returns the last element. |
| [`data()`](data.md) | Returns a pointer to the underlying array storage. |

### Iterators

| Function | Description |
| :--- | :--- |
| [`begin()` <br> `cbegin()`](begin.md) | Returns an iterator to the first element. |
| [`end()` <br> `cend()`](end.md) | Returns an iterator to the position after the last element. |
| [`rbegin()` <br> `crbegin()`](rbegin.md) | Returns a *reverse* iterator to the first element. |
| [`rend()` <br> `crend()`](rend.md) | Returns a *reverse* iterator to the position after the last element. |

### Capacity

| Function | Description |
| :--- | :--- |
| [`empty()`](empty.md) | Checks whether the array contains no elements. |
| [`size()`](size.md) | Returns the number of elements in the array. |
| [`max_size()`](max_size.md) | Returns the maximum number of elements the array can contain. |

### Operations

| Function | Description |
| :--- | :--- |
| [`fill()`](fill.md) | Fills the array with a specified value. |
| [`swap()`](swap.md) | Swaps the elements of two arrays. |

### Non-member Functions

| Function | Description |
| :--- | :--- |
| [`operator==` <br> `operator<=>`](comparison_operators.md) | Compares two arrays element by element. |
| [`std::get()`](std_get.md) | Accesses an element by index. |
| [`std::swap()`](std_swap.md) | Swaps the contents of two arrays. |
| [`sfs::to_array()`](to_array.md) | Creates an `sfs::array` from a built-in array. |

### Helper Classes

| Class | Description |
| :--- | :--- |
| [`std::tuple_size<sfs::array>`](std_tuple_size.md) | Provides the number of elements in an array. |
| [`std::tuple_element<sfs::array>`](std_tuple_element.md) | Provides the type of an array element. |

### Deduction Guides

| Guide | Description |
| :--- | :--- |
| [`sfs::array deduction guides`](deduction_guides.md) | Deduces the element type and array size from constructor arguments. |

## References

The information about `std::array` behavior and requirements is based on [cppreference](https://en.cppreference.com/):

- [std::array](https://en.cppreference.com/w/cpp/container/array)