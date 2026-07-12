#include <iostream>
#include <cassert>
#include <sfs/array.hpp>
#include <iomanip>

void test_initialization() {}
void test_at() {}
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