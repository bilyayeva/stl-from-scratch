# STL From Scratch

![C++20](https://img.shields.io/badge/C%2B%2B-20-blue)
![Educational](https://img.shields.io/badge/Project-Educational-purple)
![License](https://img.shields.io/badge/License-MIT-green)

An educational C++20 project dedicated to re-implementing components of the C++ Standard Library from scratch.

By following the C++20 standard as closely as possible and documenting every implementation, I aim to gain a deeper understanding of modern C++ and the design of the Standard Library.

> **Note:** This is a learning-focused project. Each component is implemented in the `sfs` (**S**tl-**F**rom-**S**cratch) namespace to avoid name collisions.

## Project Structure
The project is organized to separate the library logic from the educational content:

*   **`include/`**: Header-only (`.hpp`) implementations of the library components.
*   **`docs/`**: The "why" and "how" behind each implementation. This is where I document implementation details and standard requirements for each component.
*   **`tests/`**: Unit tests designed to verify correctness and ensure behavior matches the C++ Standard Library whenever applicable.
*   **`examples/`**: Practical code snippets showing how to use the implemented containers.

## Implemented Components

| Component | Status | Implementation | Documentation | Examples | Unit Tests |
| :--- | :--- | :--- | :--- | :--- | :--- |
| `sfs::array` | Implemented | [`array.hpp`](include/sfs/array.hpp) | [Overview & Guide](docs/array_docs/) | [Usage](examples/array_examples/) | [Test](tests/array_test.cpp) |
| *Coming soon* | - | - | - | - | - |

## Getting Started
As this is a **header-only** library, no complex build process is required.

1. Clone this repository.
2. Add the `include/` directory to your project's include path.
3. Simply `#include <sfs/*.hpp>` in your source files.

## Example

```cpp
#include <sfs/array.hpp>

int main() {
    sfs::array<int, 3> arr = {1, 2, 3};
    return 0;
}
```
## Why this repo exists
I believe that implementing parts of the Standard Library while following the C++ standard is one of the best ways to understand how modern C++ works. In each `docs/` folder, you will find an **Implementation Guide**. Instead of only looking at the final implementation, you can follow the entire development process step by step.

## Contributing

Since this is a learning project, I am continuously improving these implementations while expanding my understanding of modern C++. 

**Feedback is always welcome!** If you spot a bug or see a way to make the code more standard-compliant:

* **Found a bug?** Please open an issue.
* **Want to suggest a fix?** Feel free to submit a pull request!

## License

This project is licensed under the MIT License.