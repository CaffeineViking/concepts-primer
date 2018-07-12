#include <iostream>
#include <chrono>
#include <thread>

#include "concepts.h"

int main(int, char**) {
#ifndef __cpp_concepts
    // Will only work in GCC-based compilers, but seems
    // no other compilers supports concept lite anyway.
    static_assert(false, "No concepts support found!");
#endif

    // For those interested in "neat" terminal effects:
    // "\x1B[32;1m" - is the bright green terminal code
    // "\x1B[0m\r"  - is for the "clear any color" code
    //         ^^---- is the "carriage return" and will
    //                in most shells, "clear" this row.
    // Finally, you just sleep inbetween call to these.
    // Tip: replaces the need for ncurse in many cases.

    for (std::size_t i { 0 }; i < 3; ++i) {
        std::cout << "\x1B[32;1m"
                << "---------|               |---------"
                << "\x1B[0m\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "\x1B[32;1m"
                << "---------| Ready to Roll |---------"
                << "\x1B[0m\r" << std::flush;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::cout << "\x1B[32;1m"
              << "---------| Ready to Roll |---------"
              << "\x1B[0m" << std::endl;

    return 0;
}
