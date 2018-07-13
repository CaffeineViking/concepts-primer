#ifndef SFINAE_HH
#define SFINAE_HH

#include <type_traits>

template<typename T, typename U, typename = void>
struct is_equality_comparable : std::false_type {  };

template<typename T, typename U>
struct is_equality_comparable<T, U,
    typename std::enable_if<true,
    decltype(std::declval<T&>() == std::declval<U&>(),
             (void) 0)>::type> : std::true_type {  };

template<typename T, typename U>
using is_equality_comparable_t = typename
    is_equality_comparable<T, U>::type;

#endif
