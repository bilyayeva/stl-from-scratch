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

* any suitable element type, including user-defined types;
* any number of elements known at compile time.

Therefore, we need to make it a class template.

We will use:

* `T` to represent the element type;
* `N` to represent the number of elements.

```cpp
template<class T, std::size_t N>
struct array {
    T data_[N];
};
```

> `std::size_t` comes from the standard library header `<cstddef>`.

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

## 7. Implementing `max_size()`

The next member function is `max_size()`. It returns the maximum number of elements that the container can hold.

For a dynamically sized container, the current size and the maximum size can be different. An `sfs::array`, however, has a fixed number of elements determined by `N`. It cannot grow after it is created.

Therefore, `max_size()` always returns the same value as `size()`:

```cpp
[[nodiscard]] constexpr size_type max_size() const noexcept {
    return this->size();
}
```

Although `max_size()` does not provide much additional information for a fixed-size array, it is part of the standard container interface.

## 8. Implementing `empty()`

The `empty()` member function checks whether the array contains no elements.

It returns a Boolean value, so its return type is `bool`:

```cpp
bool empty() {
    return (N == 0);
}
```

Like `size()`, this function does not modify the array and cannot throw an exception. Its result can also be evaluated at compile time.

We will therefore add `const`, `noexcept`, `constexpr`, and `[[nodiscard]]`:

```cpp
[[nodiscard]] constexpr bool empty() const noexcept {
    return (N == 0);
}
```

## 9. Implementing `at()`

The next member function is `at()`. It provides checked access to the element at position `pos`.

The position is an index, so we will use the `size_type` alias introduced earlier:

```cpp
at(size_type pos)
```

The function must return a reference to the selected element. Instead of repeatedly writing `value_type&`, we will introduce another standard type alias:

```cpp
using reference = value_type&;
```

Our initial function declaration is therefore:

```cpp
reference at(size_type pos) {}
```

Returning a reference allows the caller to read or modify the selected element:

```cpp
sfs::array<int, 3> values = {1, 2, 3};

values.at(1) = 10;
```

After this assignment, the array contains:

```text
1, 10, 3
```

### Checking the position

The valid positions of an array with size `N` begin at `0` and end at `N - 1`.

In other words, `pos` is valid when:

```cpp
pos < this->size()
```

If `pos` is greater than or equal to the size, it does not refer to an existing element:

```cpp
pos >= this->size()
```

In that case, `at()` must throw a `std::out_of_range` exception. Otherwise, it returns a reference to the requested element:

```cpp
reference at(size_type pos) {
    if (pos >= this->size()) {
        throw std::out_of_range("sfs::array::at: position out of range");
    }
    return data_[pos];
}
```

> `std::out_of_range` comes from the standard library header `<stdexcept>`.

### Adding `constexpr`

The function can still be marked as `constexpr`, even though it contains a `throw` expression. When evaluated at compile time, the position must be valid. If the function reaches `throw`, the expression cannot be evaluated at compile time and causes a compilation error.

For example:

```cpp
constexpr sfs::array<int, 3> values = {1, 2, 3};

static_assert(values.at(1) == 2);
```

### Adding `[[nodiscard]]`

Calling `at()` and ignoring the returned reference is usually unintended, so we will add `[[nodiscard]]`.

We cannot mark `at()` as `noexcept` because it may throw a `std::out_of_range` exception.

This overload is not a `const` member function because it returns a modifiable reference.

The completed non-const overload is:

```cpp
[[nodiscard]] constexpr reference at(size_type pos) {
    if (pos >= this->size()) {
        throw std::out_of_range("sfs::array::at: position out of range");
    }

    return data_[pos];
}
```

### Adding a `const` overload

The current overload cannot be called on a `const` array. We therefore need another overload that is a `const` member function and returns a constant reference.

First, we will introduce the `const_reference` alias:

```cpp
using const_reference = const value_type&;
```

The `const` overload is:

```cpp
[[nodiscard]] constexpr const_reference at(size_type pos) const {
    if (pos >= this->size()) {
        throw std::out_of_range("sfs::array::at: position out of range");
    }

    return data_[pos];
}
```

This allows us to access elements of a `const` array without modifying them:

```cpp
const sfs::array<int, 3> values = {1, 2, 3};

int value = values.at(1); // Valid
values.at(1) = 10;        // Compilation error
```

## 10. Implementing `operator[]`

Next, we will implement `operator[]`. Like `at()`, it provides access to the element at position `pos`.

The important difference is that `operator[]` does not check whether the position is valid. We can therefore take the implementation of `at()` and remove the bounds check:

```cpp
[[nodiscard]] constexpr reference operator[](size_type pos) {
    return data_[pos];
}
```

We also need a `const` overload that returns `const_reference`:

```cpp
[[nodiscard]] constexpr const_reference operator[](size_type pos) const {
    return data_[pos];
}
```

Unlike `at()`, `operator[]` does not verify that `pos` refers to an existing element. Accessing an element outside the valid range results in undefined behavior:

```cpp
sfs::array<int, 3> values = {1, 2, 3};

values[3]; // Undefined behavior
```

For an array containing three elements, the valid positions are `0`, `1`, and `2`.

## 11. Implementing `front()`

The `front()` member function returns a reference to the first element of the array. Since the first element is always stored at position `0`, its implementation is very straightforward:

```cpp
[[nodiscard]] constexpr reference front() noexcept {
    return data_[0];
}
```

We also need a `const` overload that returns `const_reference`:

```cpp
[[nodiscard]] constexpr const_reference front() const noexcept {
    return data_[0];
}
```

Both overloads are marked as `[[nodiscard]]` because ignoring the returned reference is usually unintended. They are also `noexcept` because they only return a reference to the underlying storage and cannot throw an exception.

## 12. Implementing `back()`

The `back()` member function returns a reference to the last element. Since the array contains `N` elements, the last element is stored at position `N - 1`.

We need both a modifiable and a `const` overload:

```cpp
[[nodiscard]] constexpr reference back() noexcept {
    return data_[N - 1];
}

[[nodiscard]] constexpr const_reference back() const noexcept {
    return data_[N - 1];
}
```

Again, both overloads are marked as `[[nodiscard]]` because ignoring the returned reference is usually unintended. They are also `noexcept` because they only return a reference to the underlying storage and cannot throw an exception.

## 13. Implementing `data()`

The `data()` member function returns a pointer to the first element of the array. To represent pointer types, we will introduce two new aliases:

```cpp
using pointer       = value_type*;
using const_pointer = const value_type*;
```

The non-const overload returns `pointer`, allowing the elements to be modified through the returned pointer:

```cpp
[[nodiscard]] constexpr pointer data() noexcept {
    return data_;
}
```

The `const` overload returns `const_pointer`, allowing access to the elements without modifying them:

```cpp
[[nodiscard]] constexpr const_pointer data() const noexcept {
    return data_;
}
```

Both overloads are marked as `[[nodiscard]]` and `noexcept`.

## 14. Implementing Iterators

Now we will implement iterators. Since the elements of `sfs::array` are stored contiguously in memory, a simple pointer provides all the functionality we need.

First, we will introduce the iterator aliases:

```cpp
using iterator       = value_type*;
using const_iterator = const value_type*;
```

An `iterator` points to a modifiable element, while a `const_iterator` points to an element that cannot be modified through the iterator.

For reverse iteration, we will use `std::reverse_iterator` from the standard library:

```cpp
using reverse_iterator       = std::reverse_iterator<iterator>;
using const_reverse_iterator = std::reverse_iterator<const_iterator>;
```

> `std::reverse_iterator` comes from the standard library header `<iterator>`.

### Implementing `begin()` and `end()`

`begin()` returns an iterator to the first element:

```cpp
[[nodiscard]] constexpr iterator begin() noexcept {
    return &data_[0];
}

[[nodiscard]] constexpr const_iterator begin() const noexcept {
    return &data_[0];
}
```

`end()` returns an iterator one position past the last element:

```cpp
[[nodiscard]] constexpr iterator end() noexcept {
    return &data_[N];
}

[[nodiscard]] constexpr const_iterator end() const noexcept {
    return &data_[N];
}
```

The iterator returned by `end()` must not be dereferenced. It only marks the end of the range.

### Implementing `cbegin()` and `cend()`

`cbegin()` and `cend()` always return constant iterators, even when they are called on a non-const array:

```cpp
[[nodiscard]] constexpr const_iterator cbegin() const noexcept {
    return this->begin();
}

[[nodiscard]] constexpr const_iterator cend() const noexcept {
    return this->end();
}
```

### Implementing reverse iterators

`rbegin()` returns a reverse iterator to the last element, while `rend()` represents the position before the first element.

A `std::reverse_iterator` uses an ordinary iterator as its base. Therefore, `rbegin()` is constructed from `end()`, and `rend()` is constructed from `begin()`:

```cpp
[[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
    return reverse_iterator(this->end());
}

[[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator(this->end());
}

[[nodiscard]] constexpr reverse_iterator rend() noexcept {
    return reverse_iterator(this->begin());
}

[[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator(this->begin());
}
```

The constant reverse iterator functions are implemented in the same way:

```cpp
[[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
    return this->rbegin();
}

[[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
    return this->rend();
}
```

All iterator functions are marked as `[[nodiscard]]` because ignoring the returned iterator is usually unintended. They are also `constexpr` and `noexcept` because they only create or return iterators and cannot throw exceptions.

These functions allow `sfs::array` to work with range-based loops, standard algorithms, and pointer arithmetic. Since non-const iterators are ordinary pointers, they can also be used to modify the elements.

## 15. Implementing `fill()`

The `fill()` member function assigns the given value to every element of the array:

```cpp
constexpr void fill(const_reference value) {
    for (size_type i{0}; i < N; ++i) {
        data_[i] = value;
    }
}
```

This is our first member function with the return type `void`. It modifies the array directly and does not return a value.

The parameter uses `const_reference` because `fill()` only needs to read the provided value. Passing it by reference also avoids making an unnecessary copy when the function is called.

Unlike many of our previous functions, `fill()` is not marked as `noexcept`. Assigning `value` to an element may call the assignment operator of `value_type`, and that operator may throw an exception.

## 16. Implementing `swap()`

The `swap()` member function exchanges every element of the current array with the corresponding element of another array:

```cpp
constexpr void swap(array& other) noexcept(std::is_nothrow_swappable_v<value_type>) {
    using std::swap;

    for (size_type i{0}; i < N; ++i) {
        swap(data_[i], other.data_[i]);
    }
}
```

Like `fill()`, `swap()` returns `void` because it modifies the two arrays directly and does not need to return anything.

The `other` parameter is a non-const reference because its elements must also be modified during the exchange.

The `noexcept` specification is conditional:

```cpp
noexcept(std::is_nothrow_swappable_v<value_type>)
```

> `std::is_nothrow_swappable_v` comes from the standard library header `<type_traits>`.

`std::is_nothrow_swappable_v<value_type>` is `true` when two objects of `value_type` can be swapped without throwing an exception. Therefore, `array::swap()` is `noexcept` only when swapping its elements is also `noexcept`.

We first make `std::swap` available:

```cpp
using std::swap;
```

> `std::swap` comes from the standard library header `<utility>`.

We then call `swap()` without the `std::` prefix:

```cpp
swap(data_[i], other.data_[i]);
```

This enables argument-dependent lookup (ADL). ADL searches the namespace associated with `value_type` for a custom `swap()` overload. If no appropriate custom overload exists, `std::swap` is used as the fallback.

Calling `std::swap()` directly would prevent ADL from finding such a custom overload.

## 17. Implementing `operator==`

The equality operator checks whether two arrays contain the same elements in the same order. We can implement it using `std::equal`:

```cpp
[[nodiscard]] friend constexpr bool operator==(const array& lhs, const array& rhs) {
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}
```

> `std::equal` comes from the standard library header `<algorithm>`.

The new keyword here is `friend`. Although the operator is defined inside `array`, it is a non-member function. Declaring it as a friend allows it to access the private members of `array` if necessary.

Defining the operator this way also allows argument-dependent lookup (ADL) to find it when two `sfs::array` objects are compared:

```cpp
first == second;
```

Both parameters are constant references because the comparison does not modify either array.

`std::equal` compares the corresponding elements using their equality operator and returns `true` only if every pair of elements is equal. Since both arrays have the same type, they always contain the same number of elements.

The operator is not marked as `noexcept` because comparing two elements may throw an exception.

## 18. Implementing `operator<=>`

The three-way comparison operator, also known as the spaceship operator, compares two arrays lexicographically. Both `operator<=>` and `std::lexicographical_compare_three_way` are available only in C++20 and newer.

We can use `std::lexicographical_compare_three_way`:

```cpp
[[nodiscard]] friend constexpr auto operator<=>(
    const array& lhs,
    const array& rhs
) {
    return std::lexicographical_compare_three_way(
        lhs.begin(), lhs.end(),
        rhs.begin(), rhs.end()
    );
}
```

> `std::lexicographical_compare_three_way` comes from the standard library header `<algorithm>`.

Lexicographical comparison examines corresponding elements from left to right. The result is determined by the first pair of elements that are not equivalent. If all corresponding elements are equivalent, the arrays are considered equivalent.

The return type is declared as `auto` because the exact comparison category depends on `value_type`. It may be `std::strong_ordering`, `std::weak_ordering`, or `std::partial_ordering`.

> `std::strong_ordering`, `std::weak_ordering`, and `std::partial_ordering` come from the standard library header `<compare>`.

After defining `operator<=>`, the compiler can use it to support the following relational operators:

```cpp
<
<=
>
>=
```

Both parameters are constant references because comparing the arrays does not modify them.

The operator is not marked as `noexcept` because comparing the elements may throw an exception.

## 19. Implementing Non-Member `swap()`

We already implemented `swap()` as a member function. However, generic code commonly calls `swap()` as a non-member function:

```cpp
swap(first, second);
```

To support this form, we will add a non-member overload:

```cpp
template<class T, std::size_t N>
constexpr void swap(sfs::array<T, N>& lhs, sfs::array<T, N>& rhs) noexcept(noexcept(lhs.swap(rhs))) {
    lhs.swap(rhs);
}
```

The function simply delegates the work to the member `swap()`.

Its `noexcept` specification is conditional:

```cpp
noexcept(noexcept(lhs.swap(rhs)))
```

The inner `noexcept` checks whether calling `lhs.swap(rhs)` can throw. The outer `noexcept` uses that result as the exception specification of the non-member function.

Therefore, the non-member `swap()` is `noexcept` exactly when the member `swap()` is also `noexcept`.

The parameters are non-const references because the elements of both arrays must be modified.

Providing this overload also allows argument-dependent lookup (ADL) to find the appropriate `swap()` function for `sfs::array`.

## 20. Implementing `get<I>()`

The `get<I>()` function provides compile-time access to an element of the array. Unlike `at()` and `operator[]`, the position is passed as a template argument:

```cpp
sfs::array<int, 3> values = {1, 2, 3};

int value = sfs::get<1>(values);
```

Here, `I` represents the position and must be known at compile time.

We use `static_assert` to verify that the position is valid:

```cpp
static_assert(I < N, "sfs::get: index out of bounds");
```

If `I` is outside the array's valid range, compilation fails with the provided error message.

### Overload for a non-const lvalue

The first overload accepts a non-const lvalue array and returns a modifiable lvalue reference:

```cpp
template<std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr T& get(sfs::array<T, N>& a) noexcept {
    static_assert(I < N, "sfs::get: index out of bounds");
    return a[I];
}
```

### Overload for a const lvalue

When the array is `const`, the function returns a constant lvalue reference:

```cpp
template<std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr const T& get(const sfs::array<T, N>& a) noexcept {
    static_assert(I < N, "sfs::get: index out of bounds");
    return a[I];
}
```

### Overload for a non-const rvalue

For a non-const rvalue array, the function returns an rvalue reference:

```cpp
template<std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr T&& get(sfs::array<T, N>&& a) noexcept {
    static_assert(I < N, "sfs::get: index out of bounds");
    return std::move(a[I]);
}
```

> `std::move` comes from the standard library header `<utility>`.

`std::move` converts the selected element into an rvalue, allowing it to be moved from.

### Overload for a const rvalue

The final overload accepts a const rvalue array and returns a constant rvalue reference:

```cpp
template<std::size_t I, class T, std::size_t N>
[[nodiscard]] constexpr const T&& get(const sfs::array<T, N>&& a) noexcept {
    static_assert(I < N, "sfs::get: index out of bounds");
    return std::move(a[I]);
}
```

All overloads are marked as `[[nodiscard]]` because ignoring the returned reference is usually unintended. They are also `constexpr` and `noexcept` because accessing an element with a valid compile-time position does not throw an exception.

## 21. Implementing `to_array()`

The `to_array()` function converts a built-in C-style array into an `sfs::array`. We need two overloads: one copies from an lvalue array, while the other moves from an rvalue array.

### Converting an lvalue array

```cpp
template<class T, std::size_t N>
[[nodiscard]] constexpr sfs::array<std::remove_cv_t<T>, N> to_array(T (&a)[N]) noexcept(std::is_nothrow_constructible_v<std::remove_cv_t<T>, T&>) {
    return [&a]<std::size_t... I>(std::index_sequence<I...>) {
        return sfs::array<std::remove_cv_t<T>, N>{{a[I]...}};
    }(std::make_index_sequence<N>{});
}
```

> `std::remove_cv_t` comes from the standard library header `<type_traits>`.
> `std::index_sequence`, and `std::make_index_sequence` come from the standard library header `<utility>`.
> `std::is_nothrow_constructible_v` comes from the standard library header `<type_traits>`.

The parameter:

```cpp
T (&a)[N]
```

is an lvalue reference to a built-in array containing `N` elements of type `T`. Taking it by reference prevents the array from decaying into a pointer and allows the compiler to deduce its size.

The return type uses `std::remove_cv_t`:

```cpp
sfs::array<std::remove_cv_t<T>, N>
```

It removes the `const` or `volatile` qualifier from the element type. For example, converting a `const int[3]` produces an `sfs::array<int, 3>`.

### Generating the element positions

We use `std::index_sequence` and `std::make_index_sequence` to generate the positions from `0` to `N - 1`:

```cpp
std::make_index_sequence<N>{}
```

For an array of size three, this produces:

```cpp
std::index_sequence<0, 1, 2>
```

The sequence is passed to an explicitly templated lambda:

```cpp
[&a]<std::size_t... I>(std::index_sequence<I...>) {
    return sfs::array<std::remove_cv_t<T>, N>{{a[I]...}};
}
```

The pack expansion:

```cpp
a[I]...
```

expands to:

```cpp
a[0], a[1], a[2]
```

Because `a[I]` is an lvalue expression, the elements are copied into the resulting `sfs::array`.

### Converting an rvalue array

The second overload accepts an rvalue built-in array:

```cpp
template<class T, std::size_t N>
[[nodiscard]] constexpr sfs::array<std::remove_cv_t<T>, N> to_array(T (&&a)[N]) noexcept(std::is_nothrow_constructible_v<std::remove_cv_t<T>, T&&>) {
    return [&a]<std::size_t... I>(std::index_sequence<I...>) {
        return sfs::array<std::remove_cv_t<T>, N>{{
            std::move(a[I])...
        }};
    }(std::make_index_sequence<N>{});
}
```

The parameter:

```cpp
T (&&a)[N]
```

is an rvalue reference to a built-in array.

Although `a` has an rvalue-reference type, the expression `a` is an lvalue because it has a name. Therefore, each element must be explicitly converted into an rvalue using `std::move`:

```cpp
std::move(a[I])...
```

This allows the elements to be moved into the resulting `sfs::array`. It is especially useful for move-only types.

### Conditional `noexcept`

Both overloads use a conditional `noexcept` specification.

For the lvalue overload:

```cpp
noexcept(std::is_nothrow_constructible_v<
    std::remove_cv_t<T>, T&
>)
```

For the rvalue overload:

```cpp
noexcept(std::is_nothrow_constructible_v<
    std::remove_cv_t<T>, T&&
>)
```

`std::is_nothrow_constructible_v` checks whether the destination element can be constructed without throwing. The lvalue overload checks copy construction, while the rvalue overload checks move construction.

Both functions are marked as `[[nodiscard]]` because ignoring the newly created array is usually unintended. They are also `constexpr`, allowing the conversion to be performed at compile time when the element type supports it.

This implementation also requires C++20 because it uses explicitly templated lambdas:

```cpp
[]<std::size_t... I>(...)
```

## 22. Adding a Deduction Guide

A deduction guide allows the compiler to determine the element type and array size from the initializer:

```cpp
template<class T, class... U>
array(T, U...) -> array<T, 1 + sizeof...(U)>;
```

`T` is the type of the first element, while `sizeof...(U)` is the number of remaining elements. Therefore:

```cpp
sfs::array values{1, 2, 3};
```

is deduced as:

```cpp
sfs::array<int, 3>
```

## 23. Adding Tuple Protocol Support

To make `sfs::array` compatible with structured bindings, we specialize `std::tuple_size` and `std::tuple_element`:

```cpp
namespace std {

    template<class T, std::size_t N>
    struct tuple_size<sfs::array<T, N>>: std::integral_constant<std::size_t, N> {};

    template<std::size_t I, class T, std::size_t N>
    struct tuple_element<I, sfs::array<T, N>> {
        static_assert(I < N, "std::tuple_element: index out of bounds");
        using type = T;
    };

}
```

> `std::integral_constant` comes from the standard library header `<type_traits>`.

`std::tuple_size` describes how many elements the array contains. It inherits from `std::integral_constant`, storing `N` as a compile-time constant.

`std::tuple_element` describes the type of the element at position `I`. Since every element of an `sfs::array` has the same type, its `type` is always `T`.

The `static_assert` ensures that `I` refers to an existing element.

These specializations, together with the previously implemented `sfs::get<I>()` overloads, enable structured bindings:

```cpp
sfs::array<int, 3> values{1, 2, 3};

auto [first, second, third] = values;
```

> The tuple protocol declarations are provided by the `<tuple>` header.

## 24. Supporting `array<T, 0>`

The primary implementation uses:

```cpp
T data_[N];
```

However, standard C++ does not allow an array with zero elements. To support `sfs::array<T, 0>`, we provide a partial specialization:

```cpp
template<class T>
struct array<T, 0> {
    // ...
};
```

It is a partial specialization, not an explicit specialization, because `T` is still a template parameter.

### Empty storage

We use an empty placeholder instead of `T[0]`:

```cpp
struct empty_element {};

[[no_unique_address]] empty_element data_{};
```

The `[[no_unique_address]]` attribute, available since C++20, allows the compiler to avoid allocating separate storage for the empty placeholder when possible.

Importantly, this implementation does not require `T` to be default-constructible.

### Element access

An empty array has no valid element. Therefore, both `at()` overloads always throw:

```cpp
[[nodiscard]] constexpr reference at(size_type) {
    throw std::out_of_range("sfs::array::at: position >= size (N == 0)");
}

[[nodiscard]] constexpr const_reference at(size_type) const {
    throw std::out_of_range("sfs::array::at: position >= size (N == 0)");
}
```

The unchecked access functions still have to exist:

```cpp
[[nodiscard]] constexpr reference operator[](size_type) noexcept {
    return *data();
}

[[nodiscard]] constexpr const_reference operator[](size_type) const noexcept {
    return *data();
}

[[nodiscard]] constexpr reference front() noexcept {
    return *data();
}

[[nodiscard]] constexpr const_reference front() const noexcept {
    return *data();
}

[[nodiscard]] constexpr reference back() noexcept {
    return *data();
}

[[nodiscard]] constexpr const_reference back() const noexcept {
    return *data();
}
```

Calling any of these functions results in undefined behavior because there is no element to return.

`data()` returns a null pointer:

```cpp
[[nodiscard]] constexpr pointer data() noexcept {
    return nullptr;
}

[[nodiscard]] constexpr const_pointer data() const noexcept {
    return nullptr;
}
```

### Iterators

Because the array contains no elements, `begin()` and `end()` represent the same position:

```cpp
[[nodiscard]] constexpr iterator begin() noexcept {
    return nullptr;
}

[[nodiscard]] constexpr const_iterator begin() const noexcept {
    return nullptr;
}

[[nodiscard]] constexpr const_iterator cbegin() const noexcept {
    return this->begin();
}

[[nodiscard]] constexpr iterator end() noexcept {
    return nullptr;
}

[[nodiscard]] constexpr const_iterator end() const noexcept {
    return nullptr;
}

[[nodiscard]] constexpr const_iterator cend() const noexcept {
    return this->end();
}

[[nodiscard]] constexpr reverse_iterator rbegin() noexcept {
    return reverse_iterator( this->end() );
}

[[nodiscard]] constexpr const_reverse_iterator rbegin() const noexcept {
    return const_reverse_iterator( this->end() );
}

[[nodiscard]] constexpr const_reverse_iterator crbegin() const noexcept {
    return this->rbegin();
}

[[nodiscard]] constexpr reverse_iterator rend() noexcept {
    return reverse_iterator( this->begin() );
}

[[nodiscard]] constexpr const_reverse_iterator rend() const noexcept {
    return const_reverse_iterator( this->begin() );
}

[[nodiscard]] constexpr const_reverse_iterator crend() const noexcept {
    return this->rend();
}
```

Consequently, the array represents an empty range. The constant and reverse iterator functions can be implemented using these functions in the same way as in the primary template.

### Capacity

The capacity functions return constant results:

```cpp
[[nodiscard]] constexpr bool empty() const noexcept {
    return true;
}

[[nodiscard]] constexpr size_type size() const noexcept {
    return 0;
}

[[nodiscard]] constexpr size_type max_size() const noexcept {
    return this->size();
}
```

### Operations

There are no elements to fill or exchange, so both operations do nothing:

```cpp
constexpr void fill(const_reference) noexcept {}

constexpr void swap(array&) noexcept(std::is_nothrow_swappable_v<T>) {}
```

### Comparisons

Two empty arrays are always equal and lexicographically equivalent:

```cpp
[[nodiscard]] friend constexpr bool operator==(const sfs::array<T, 0>& lhs, const sfs::array<T, 0>& rhs) {
    return true;
}

[[nodiscard]] friend constexpr auto operator<=>(const sfs::array<T, 0>& lhs, const sfs::array<T, 0>& rhs) {
    return std::strong_ordering::equal;
}
```

This completes support for `sfs::array<T, 0>`.

## 25. Adding the Final Alias

The final alias is `difference_type`:

```cpp
using difference_type = std::ptrdiff_t;
```

> `std::ptrdiff_t` comes from the standard library header `<cstddef>`.

`std::ptrdiff_t` is a signed integer type used to represent the difference between two pointers or iterators.

Even though our implementation does not use it directly, it is part of the standard `array` interface and may be required by generic code.

Add this alias to both the primary template and the `array<T, 0>` specialization.

## Final Note

This guide focused on implementing each part of `sfs::array` step by step. To see how all the pieces fit together, you can find the complete implementation in [`array.hpp`](../../include/sfs/array.hpp).