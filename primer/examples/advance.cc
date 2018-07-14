#include "concepts.h"

#include <iostream>
#include <forward_list>
#include <vector>
#include <list>

template<typename T, typename U>
    requires ForwardIterator<T> && Integral<U>
void advance(T& iterator, const U distance) {
    U distance_covered {  };
    if (distance <= distance_covered) return;
    while (distance_covered++ != distance)
        ++iterator;
    std::cout << "Forward" << std::endl;
}

template<typename T, typename U>
    requires RandomAccessIterator<T> && Integral<U>
void advance(T& iterator, const U distance) {
    std::cout << "RandomAccess" << std::endl;
    iterator += distance;
}

int main(int, char**) {
    std::forward_list f { 1, 2, 3, 4, 5 };
    ForwardIterator fi { f.begin() };
    advance(fi, 2);
    std::cout << *(fi) << std::endl;

    std::list l { 1, 2, 3, 4, 5 };

    // List does not fullfill RandomAccess.
    // Try replacing with RandomAccessIt to
    // see a nice error message telling you
    // that std::list isn't RandomAccess :)
    BidirectionalIterator li { l.begin() };
    advance(li, 2);
    std::cout << *(li) << std::endl;

    std::vector v { 1, 2, 3, 4, 5 };
    RandomAccessIterator vi { v.begin() };
    advance(vi, 2);
    std::cout << *(vi) << std::endl;
    return 0;
}
