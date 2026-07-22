## STL From Scratch v0.1.0

The first release of STL From Scratch introduces `sfs::array`, a C++20 reimplementation of `std::array` created for exploring and learning about standard-library internals.

### Included

- Full `sfs::array` implementation
- Zero-sized `array<T, 0>` specialization
- Tests covering the public interface
- Usage examples and reference documentation
- Step-by-step implementation guide
- CMake and CTest integration

### Project goal

STL From Scratch aims to reproduce the C++20 standard-library interface, requirements, and behavior one-to-one. **Any discovered deviations** are considered bugs and will be corrected in future releases.