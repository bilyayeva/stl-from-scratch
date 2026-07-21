# `sfs::array` Guide

> **Note:** In this guide, I will omit include directives and include guards to keep the code examples clean and focused.

## 1. Underlying Storage

Let us begin with a brief explanation. `sfs::array` is a wrapper around a built-in array.

For example, the underlying storage for an array containing three integers could look like this:

```cpp
int data_[3];
```

This built-in array will eventually store all elements belonging to our `sfs::array`.

## 2. Choosing Between `struct` and `class`

Because we are creating an array with member functions, we need to place its storage inside either a `struct` or a `class`.

Both can be used, but the underlying storage **must be public**. An aggregate cannot have private or protected direct non-static data members. If `data_` were private, our type would not be an aggregate, and aggregate initialization would not work.

A `struct` makes its members public by default:

```cpp
struct array {
    int data_[3];
};
```

A `class` can also be used, but we must explicitly add a `public` section:

```cpp
class array {
public:
    int data_[3];
};
```

Both versions support aggregate initialization:

```cpp
array a = {1, 2, 3};
```

However, we will use a `struct` because it is more concise and naturally communicates that its underlying storage is public.

> **Important:** It does not matter whether we use `struct` or `class`. What matters is that `data_` remains public so that `array` can remain an aggregate.

You might assume that we need to add a constructor and a destructor, but we do not.

In particular, declaring our own constructor would prevent `array` from being an aggregate. The compiler-generated destructor is sufficient because the built-in array automatically destroys its elements.

## 3. Making the Array Generic

At the moment, our array can store exactly three integers. We want it to support:

- any suitable element type, including user-defined types;
- any number of elements known at compile time.

Therefore, we need to make it a class template.

We will use:

- `T` to represent the element type;
- `N` to represent the number of elements.

```cpp
template<class T, std::size_t N>
struct array {
    T data_[N];
};
```

We can now create arrays with different element types and sizes:

```cpp
array<int, 3> integers = {1, 2, 3};
array<double, 2> doubles = {1.5, 2.5};
```

For the first declaration, the compiler substitutes:

```text
T = int
N = 3
```

Therefore, the underlying storage for this specialization is:

```cpp
int data_[3];
```

For the second declaration, the compiler substitutes:

```text
T = double
N = 2
```

So its underlying storage is:

```cpp
double data_[2];
```

Each combination of `T` and `N` creates a different specialization of the `array` class template. In this example, `array<int, 3>` and `array<double, 2>` are two distinct types.

## 4. Adding the `sfs` Namespace

Our implementation should be placed in its own namespace. This keeps its names organized and prevents them from conflicting with names from other libraries.

I will use the namespace `sfs`, which stands for *STL From Scratch*:

```cpp
namespace sfs {

template<class T, std::size_t N>
struct array {
    T data_[N];
};

}
```

We can now refer to our type as:

```cpp
sfs::array<int, 3>
```

For example:

```cpp
sfs::array<int, 3> a = {1, 2, 3};
```

This clearly distinguishes `sfs::array` from `std::array`.

## 5. Introducing `value_type`

Next, we will add our first type alias:

```cpp
using value_type = T;
```

A type alias gives an existing type another name. Here, `value_type` is another name for the template parameter `T`.

It describes the type of each element stored in the array.

Now we can add it to the structure:

```cpp
namespace sfs {

template<class T, std::size_t N>
struct array {
    using value_type = T;

    value_type data_[N];
};

}
```

These two declarations mean exactly the same thing:

```cpp
T data_[N];
value_type data_[N];
```

However, `value_type` describes the role of the type more clearly: it is the type of each value stored in the array.

I will introduce the remaining type aliases later, when we implement the member functions that use them.

## 6. Implementing Member Functions

Now we can begin implementing the member functions of `sfs::array`.

### Implementing `size()`

The first and simplest member function is `size()`. It returns the number of elements stored in the array.

The size is represented by the template parameter `N`, so the initial implementation is:

```cpp
std::size_t size() {
    return N;
}
```

Since `std::size_t` is the type used to represent the size of the array, we will introduce the standard `size_type` alias:

```cpp
using size_type = std::size_t;
```

This gives us a more descriptive name to use throughout the implementation:

```cpp
size_type size() {
    return N;
}
```

The basic implementation works, but we can describe the behavior of the function more accurately by adding several specifiers and an attribute.

#### `const`

Calling `size()` does not modify the array. We should therefore make it a `const` member function:

```cpp
size_type size() const {
    return N;
}
```

This also allows us to call `size()` on a `const` array:

```cpp
const sfs::array<int, 3> values = {1, 2, 3};

values.size();
```

#### `noexcept`

The function only returns `N` and performs no operation that can throw an exception. We can therefore mark it as `noexcept`:

```cpp
size_type size() const noexcept {
    return N;
}
```

#### `constexpr`

The value of `N` is known at compile time because it is a template parameter. Marking `size()` as `constexpr` allows its result to be used in constant expressions:

```cpp
constexpr size_type size() const noexcept {
    return N;
}
```

For example:

```cpp
constexpr sfs::array<int, 3> values = {1, 2, 3};

static_assert(values.size() == 3);
```

#### `[[nodiscard]]`

Calling `size()` without using its return value is usually a mistake, so we will add `[[nodiscard]]` to allow the compiler to warn us when the returned value is ignored. Our final implementation is:

```cpp
[[nodiscard]] constexpr size_type size() const noexcept {
    return N;
}
```