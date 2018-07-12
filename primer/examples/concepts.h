#ifndef CONCEPTS_PRIMER_H
#define CONCEPTS_PRIMER_H

// Copyright © 2018 Erik Sven Vasconcelos Jansson
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the “Software”), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.
//
// WARNING: these concepts are non-standard and probably also not
// complete. When the <concepts> and <ranges> header are available,
// go and use those instead. These are only here for teaching, and
// should probably not be used in production. Here be dragons!!!!

#include <type_traits>

#define concept concept bool

template<typename T, typename U> concept Same = std::is_same_v<T,U>;
template<typename T> concept Integral = std::is_integral_v<T>;
template<typename T> concept Floating = std::is_floating_point_v<T>;

template<typename T>
concept DefaultConstructible = requires {
    T();
    T{};
};

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

template<typename T, typename U>
concept SummableWith = requires(T x, T y) {
    { x + y }  -> T;
    { x += y } -> T&;
    { y += x } -> T&;
    { y + x }  -> T;
};

template<typename T>
concept Summable = SummableWith<T, T>;

template<typename T, typename U>
concept ScalableWith = requires(T x, U y) {
    { x * y } -> T;
    { x *= y } -> T&;
    { y * x } -> T;
    { x /= y } -> T&;
    { x / y } -> T;

};

#endif
