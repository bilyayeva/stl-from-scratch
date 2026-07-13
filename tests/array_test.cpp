#include <iostream>
#include <cassert>
#include <iomanip>
#include <sfs/array.hpp>

void test_initialization() {
    sfs::array<int, 0> arr_empty;
    assert(arr_empty.size() == 0 && "arr_empty: size mismatched");

    sfs::array<double, 3>   arr_double{{0.5, 3.14, 2.76}};
    assert(arr_double.size() == 3 && "arr_double: size mismatched");
    assert(arr_double.data_[0] == 0.5 && "arr_double: arr_double[0] mismatched");
    assert(arr_double.data_[1] == 3.14 && "arr_double: arr_double[1] mismatched");
    assert(arr_double.data_[2] == 2.76 && "arr_double: arr_double[2] mismatched");

    sfs::array<sfs::array<int, 0>, 1> arr_arr = {arr_empty};
    assert(arr_arr.size() == 1 && "arr_arr: size mismatched");
    assert(arr_arr.data_[0].size() == 0 && "arr_arr[0] size mismatched");

    sfs::array arr_int = {0, 1, 2, 3, 4};
    assert(arr_int.size() == 5 && "arr_int: size mismatched");
    for (size_t i{0}; i < arr_int.size(); ++i) {
        assert(arr_int.data_[i] == static_cast<int>(i) && "arr_int: arr_int elements mismatched");
    }

    sfs::array<int, 3> arr_zeroed{};
    assert(arr_zeroed.size() == 3 && "arr_zeroed: size mismatched");
    assert(arr_zeroed.data_[0] == 0 && "arr_zeroed: arr_zeroed[0] mismatched");
    assert(arr_zeroed.data_[1] == 0 && "arr_zeroed: arr_zeroed[1] mismatched");
    assert(arr_zeroed.data_[2] == 0 && "arr_zeroed: arr_zeroed[2] mismatched");

    sfs::array<int, 3> arr_partial{42};
    assert(arr_partial.size() == 3 && "arr_partial: size mismatched");
    assert(arr_partial.data_[0] == 42 && "arr_partial: arr_partial[0] mismatched");
    assert(arr_partial.data_[1] == 0  && "arr_partial: arr_partial[1] mismatched");
    assert(arr_partial.data_[2] == 0  && "arr_partial: arr_partial[2] mismatched");
}

void test_at() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.at(0) == 10 && "arr_int: arr_int.at(0) mismatched");
    assert(arr_int.at(1) == 15 && "arr_int: arr_int.at(1) mismatched");
    assert(arr_int.at(2) == 20 && "arr_int: arr_int.at(2) mismatched");
    try {
        arr_int.at(3);
        assert(false && "arr_int: arr_int.at(3) should have thrown std::out_of_range");
    } catch (const std::out_of_range&) {}

    sfs::array<char, 0> arr_empty;
    try {
        arr_empty.at(0);
        assert(false && "arr_empty: arr_empty.at(0) should have thrown std::out_of_range");
    } catch (const std::out_of_range&) {}

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.at(0) == 10 && "const_arr_int: const_arr_int.at(0) mismatched");
    assert(const_arr_int.at(1) == 20 && "const_arr_int: const_arr_int.at(1) mismatched");
    assert(const_arr_int.at(2) == 30 && "const_arr_int: const_arr_int.at(2) mismatched");
    try {
        const_arr_int.at(3);
        assert(false && "const_arr_int: const_arr_int.at(3) should have thrown std::out_of_range");
    } catch (const std::out_of_range&) {}

    const sfs::array<char, 0> const_arr_empty;
    try {
        const_arr_empty.at(0);
        assert(false && "const_arr_empty: const_arr_empty.at(0) should have thrown std::out_of_range");
    } catch (const std::out_of_range&) {}
}

void test_element_access() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int[0] == 10 && "arr_int: arr_int[0] mismatched");
    assert(arr_int[1] == 15 && "arr_int: arr_int[1] mismatched");
    assert(arr_int[2] == 20 && "arr_int: arr_int[2] mismatched");

    arr_int[1] = 16;
    assert(arr_int[1] == 16 && "arr_int: modifier via [1] mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int[0] == 10 && "const_arr_int: const_arr_int[0] mismatched");
    assert(const_arr_int[1] == 20 && "const_arr_int: const_arr_int[1] mismatched");
    assert(const_arr_int[2] == 30 && "const_arr_int: const_arr_int[2] mismatched");
}

void test_front() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.front() == 10 && "arr_int: front() mismatched");

    arr_int.front() = 16;
    assert(arr_int.front() == 16 && "arr_int: modifier via front() mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.front() == 10 && "const_arr_int: front() mismatched");
}

void test_back() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.back() == 20 && "arr_int: back() mismatched");

    arr_int.back() = 21;
    assert(arr_int.back() == 21 && "arr_int: modifier via back() mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.back() == 30 && "const_arr_int: back() mismatched");
}

void test_data() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.data() == &arr_int[0] && "arr_int: data() pointer mismatched");
    assert(*arr_int.data() == 10 && "arr_int: data() mismatched");

    *arr_int.data() = 11;
    assert(arr_int[0] == 11 && "arr_int: modifier via data() mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.data() == &const_arr_int[0] && "const_arr_int: data() pointer mismatched");
    assert(*const_arr_int.data() == 10 && "const_arr_int: data() mismatched");

    sfs::array<char, 0> arr_empty{};
    assert(arr_empty.data() == nullptr && "arr_empty: data() pointer mismatched");

    const sfs::array<char, 0> const_arr_empty{};
    assert(const_arr_empty.data() == nullptr && "const_arr_empty: data() pointer mismatched");
}

void test_begin() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.begin() == &arr_int[0] && "arr_int: begin() pointer mismatched");
    assert(*arr_int.begin() == 10 && "arr_int: begin() mismatched");
    assert(arr_int.cbegin() == &arr_int[0] && "arr_int: cbegin() pointer mismatched");
    assert(*arr_int.cbegin() == 10 && "arr_int: cbegin() mismatched");

    *arr_int.begin() = 11;
    assert(arr_int[0] == 11 && "arr_int: modifier via begin() mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.begin() == &const_arr_int[0] && "const_arr_int: begin() pointer mismatched");
    assert(*const_arr_int.begin() == 10 && "const_arr_int: begin() mismatched");

    sfs::array<char, 0> arr_empty{};
    assert(arr_empty.begin() == nullptr && "arr_empty: begin() pointer mismatched");

    const sfs::array<char, 0> const_arr_empty{};
    assert(const_arr_empty.begin() == nullptr && "const_arr_empty: begin() pointer mismatched");
}

void test_end() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.end() == (&arr_int[0] + 3) && "arr_int: end() pointer mismatched");
    assert(arr_int.cend() == (&arr_int[0] + 3) && "arr_int: cend() pointer mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.end() == (&const_arr_int[0] + 3) && "const_arr_int: end() pointer mismatched");

    sfs::array<char, 0> arr_empty{};
    assert(arr_empty.end() == nullptr && "arr_empty: end() pointer mismatched");

    const sfs::array<char, 0> const_arr_empty{};
    assert(const_arr_empty.end() == nullptr && "const_arr_empty: end() pointer mismatched");
}

void test_rbegin() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(*arr_int.rbegin() == arr_int[2] && "arr_int: rbegin() pointer mismatched");
    assert(*arr_int.crbegin() == arr_int[2] && "arr_int: crbegin() pointer mismatched");

    *arr_int.rbegin() = 21;
    assert(arr_int[2] == 21 && "arr_int: modifier via rbegin() mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(*const_arr_int.rbegin() == const_arr_int[2] && "const_arr_int: rbegin() pointer mismatched");

    sfs::array<char, 0> arr_empty{};
    assert(arr_empty.rbegin() == arr_empty.rend() && "arr_empty: rbegin() pointer mismatched");

    const sfs::array<char, 0> const_arr_empty{};
    assert(const_arr_empty.rbegin() == const_arr_empty.rend() && "const_arr_empty: rbegin() pointer mismatched");
}

void test_rend() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(*(arr_int.rend() - 1) == arr_int[0] && "arr_int: rend() pointer mismatched");
    assert(*(arr_int.crend() - 1) == arr_int[0] && "arr_int: crend() pointer mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(*(const_arr_int.rend() - 1) == const_arr_int[0] && "const_arr_int: rend() pointer mismatched");

    sfs::array<char, 0> arr_empty{};
    assert(arr_empty.rend() == arr_empty.rbegin() && "arr_empty: rend() pointer mismatched");

    const sfs::array<char, 0> const_arr_empty{};
    assert(const_arr_empty.rend() == const_arr_empty.rbegin() && "const_arr_empty: rend() pointer mismatched");
}

void test_empty() {
    sfs::array<int, 3> arr_int{{10, 15, 20}};
    assert(arr_int.empty() == false && "arr_int: empty() mismatched");

    const sfs::array<int, 3> const_arr_int{{10, 20, 30}};
    assert(const_arr_int.empty() == false && "const_arr_int: empty() mismatched");

    sfs::array<char, 0> arr_empty{};
    assert(arr_empty.empty() == true && "arr_empty: empty() mismatched");

    const sfs::array<char, 0> const_arr_empty{};
    assert(const_arr_empty.empty() == true && "const_arr_empty: empty() mismatched");
}

void test_size() {}
void test_fill() {}
void test_swap() {}
void test_operators() {}
void test_get() {}
void test_tuple() {}

int main() {

    std::cout << std::left << std::setfill('.');
    
    std::cout << "--- RUNNING TESTS ---\n";
    std::cout << '\n';

    std::cout << std::setw(40) << "Running test_initialization";
    test_initialization();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_at";
    test_at();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_element_access";
    test_element_access();
    std::cout << " passed!\n";
    
    std::cout << std::setw(40)<< "Running test_front";
    test_front();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_back";
    test_back();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_data";
    test_data();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_begin";
    test_begin();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_end";
    test_end();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_rbegin";
    test_rbegin();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_rend";
    test_rend();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_empty";
    test_empty();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_size";
    test_size();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_fill";
    test_fill();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_swap";
    test_swap();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_operator";
    test_operators();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_get";
    test_get();
    std::cout << " passed!\n";

    std::cout << std::setw(40) << "Running test_tuple";
    test_tuple();
    std::cout << " passed!\n";

    std::cout << '\n';
    std::cout << "--- ALL TESTS PASSED ---\n";

    return 0;
}