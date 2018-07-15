#include <range/v3/all.hpp>

#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace ranges;

template<typename T>
void print_all_elements(T& container, std::ostream& stream) {
    for (auto element : container)
        stream << element << " ";
    stream <<  std::endl;
}

int main(int, char**) {

    std::vector v { 10, 2, 6, 10, 4, 1, 9, 5, 8, 3 };
    v = std::move(v) | action::sort | action::unique;
    print_all_elements(v, std::cout);

    auto range_of_v = v | view::remove_if([](int i) { return i % 2 == 1; })
                        | view::transform([](int i) { return std::to_string(i); })
                        | view::take(4);
    print_all_elements(range_of_v, std::cout);

    return 0;
}
