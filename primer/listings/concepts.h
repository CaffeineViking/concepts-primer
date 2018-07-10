#ifndef CONCEPTS_PRIMER_H
#define CONCEPTS_PRIMER_H

#include <type_traits>

#define concept concept bool

template<typename T, typename U> concept Same = std::is_same_v<T,U>;
template<typename T> concept Integral = std::is_integral_v<T>;
template<typename T> concept Floating = std::is_floating_point_v<T>;

template<typename T, typename U>
concept SwappableWith = requires(T x, U y) {
    { std::swap(x, y) } noexcept;
    { std::swap(y, x) } noexcept;
};

template<typename T>
concept Swappable = SwappableWith<T, T>;

template<typename T, typename U>
concept EqualityComparableWith = requires(T x, U y) {
    { x == y } -> bool; { x != y } -> bool;
    { y != x } -> bool; { y == x } -> bool;
};

template<typename T>
concept EqualityComparable = EqualityComparableWith<T, T>;

template<typename T, typename U>
concept StrictTotallyOrderedWith = requires(T x, U y) {
    { x > y }  -> bool; { x >= y } -> bool;
    { x <= y } -> bool; { x < y }  -> bool;
    { y > x }  -> bool; { y >= x } -> bool;
    { y <= x } -> bool; { y < x }  -> bool;
} && EqualityComparableWith<T, U>;

template<typename T>
concept StrictTotallyOrdered = StrictTotallyOrderedWith<T, T>;

#endif
