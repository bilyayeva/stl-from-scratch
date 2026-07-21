# `sfs::array` Guide

> **Note:** In this guide, I will omit include directives and include guards to keep the code examples clean and focused.

## 1. Underlying Storage

Let us begin with a brief explanation. `sfs::array` is a wrapper around a built-in array.

For example, the underlying storage for an array containing three integers could look like this:

```cpp
int data_[3];
```

This built-in array will eventually store all elements belonging to our `sfs::array`.