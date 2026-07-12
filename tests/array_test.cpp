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
}

void test_element_access() {}
void test_front() {}
void test_back() {}
void test_data() {}
void test_begin() {}
void test_end() {}
void test_rbegin() {}
void test_rend() {}
void test_empty() {}
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