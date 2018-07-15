#include "concepts.h"

#include <iterator>
#include <iostream>
#include <forward_list>
#include <vector>
#include <list>

// Our version of advance only goes forward. Not
// the same as std::advance, which can advance a
// iterator both forwards & backward. Different!

template<typename T, typename U>
void tagged_advance(T& iterator, U distance,
                    std::forward_iterator_tag) {
    while (distance--)
        iterator++;
}

template<typename T, typename U>
void tagged_advance(T& iterator, U distance,
                    std::bidirectional_iterator_tag) {
    std::forward_iterator_tag hack_category;
    tagged_advance(iterator, distance, hack_category);
}

template<typename T, typename U>
void tagged_advance(T& iterator, const U distance,
                    std::random_access_iterator_tag) {
    iterator += distance;
}

#if false // Below and above is the way we do advance using tag dispatch!
// Example based on a Boost post on: Tag Dispatch in Generic Programming.

template<typename T, typename U>
void advance(T& iterator, U distance) {
    typename std::iterator_traits<T>::category category;
    tagged_advance(iterator, distance, category);
}

#endif

// Here we use constraints instead, notice that this is a lot nicer now!
// Notice that we also additionally check that distances are an integer.

template<typename T, typename U>
    requires ForwardIterator<T> &&
             Unsigned<U> && Integral<U>
void advance(T& iterator, U distance) {
    std::cout << "forward" << std::endl;
    while (distance--)
        ++iterator;
}

template<typename T, typename U>
    requires RandomAccessIterator<T> &&
             Unsigned<U> && Integral<U>
void advance(T& iterator, U distance) {
    std::cout << "random!" << std::endl;
    iterator += distance;
}

int main(int, char**) {

    std::forward_list f { 1, 2, 3, 4, 5 };
    ForwardIterator fi { f.begin() };
    advance(fi, 2u);
    std::cout << *(fi) << std::endl;

    std::list l { 1, 2, 3, 4, 5 };

    // List does not fullfill RandomAccess.
    // Try replacing with RandomAccessIt to
    // see a nice error message telling you
    // that std::list isn't RandomAccess :)
    BidirectionalIterator li { l.begin() };
    advance(li, 2u);
    std::cout << *(li) << std::endl;

    std::vector v { 1, 2, 3, 4, 5 };
    RandomAccessIterator vi { v.begin() };
    advance(vi, 2u);
    std::cout << *(vi) << std::endl;

    return 0;
}
