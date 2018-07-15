#include "concepts.h"

#include <vector>
#include <iostream>

template<template<class> typename C, typename T>
    requires Summable<T>
T sum(const C<T>& container) {
    T total_sum {  };
    for (auto value : container)
        total_sum += value;
    return total_sum;
}

template<template<class> typename C, typename T>
    requires Integral<T> || Floating<T>
T sum_numbers(const C<T>& container) requires Summable<T> {
    T total_sum {  };
    for (auto value : container)
        total_sum += value;
    return total_sum;
}

template<auto N>
    requires Even<N>
int square_even() {
    return N*N;
}

template<auto N>
    requires Even<N> &&
             Number<decltype(N)>
int square_only_even_numbers() {
    return N*N;
}






// Just read The Hitchhiker's Guide!
constexpr bool the_answer(int value) {
    return value == 42;
}

template<auto N>
    requires the_answer(N)
void check_with_deep_thought() {
    std::cout << "good guess!"
              << std::endl;
}

int main(int, char**) {

    std::cout << square_even<4>() << std::endl;
    // square_even<3>(); // will fail, 3 isn't Even!

    std::vector v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::cout << sum(v) << std::endl; // will be 55.

    std::vector<std::string> vs { "1",  "2",  "3" };
    // std::cout << sum_numbers(vs) << std::endl; :(
    // constraints not satisfied: std::string is not
    // a Number, and doesn't support the % operator.

    check_with_deep_thought<42>();

    return 0;
}
