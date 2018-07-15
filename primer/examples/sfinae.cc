#include "sfinae.hh"

#include "concepts.h"

#include <vector>

template<typename T, typename U>
bool check(const T& x, const U& y) {
    return x == y;
}

template<typename T, typename U, typename =
     is_equality_comparable_t<T, U>>
bool check_sfinae(const T& x, const U& y) {
    return x == y;
}

template<typename T, typename U>
    requires EqualityComparableWith<T, U>
bool check_concepts(const T& x, const U& y) {
    return x == y;
}

int main(int, char**) {

    check(4, 2);
    check(4.0, 2.0);
    check(4.0, 2);

    std::vector v2 { 2 };

#if false

    check(4, v2);

#endif

    std::vector v4 { 4 };

#if false

    check_sfinae(2, v4);

#endif

#if false

    check_concepts(2, v4);

#endif

    return 0;
}
