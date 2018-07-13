#include "factory.hh"

#include <iostream>

int main(int, char**) {
    NumberFactory deep_factory { 1984 };
    NumberFactory beef_factory { 3.141592 };

    std::cout << deep_factory.create_number()
              << std::endl;
    std::cout << beef_factory.create_number()
              << std::endl; // negative value
    return 0;
}
