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