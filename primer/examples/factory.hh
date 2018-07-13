#ifndef FACTORY_HH
#define FACTORY_HH

#include <type_traits>

#if false

struct NumberFactory {
    enum { INTEGRAL, FLOATING } number_type;

    template<typename T,
             typename = std::enable_if<
             std::is_integral_v<T>>>
    NumberFactory(T) : number_type { INTEGRAL } {}

    int create_number() const;

    template<typename T,
             typename = std::enable_if<
             std::is_floating_point_v<T>>>
    NumberFactory(T) : number_type { FLOATING } {}
};

#endif

#if false

struct NumberFactory {
    enum { INTEGRAL, FLOATING } number_type;

    template<int> struct dummy { dummy(int) {} };

    template<typename T,
             typename = std::enable_if<
             std::is_integral_v<T>>>
    NumberFactory(T, dummy<0>=0) : number_type { INTEGRAL } {}

    int create_number() const;

    template<typename T,
             typename = std::enable_if<
             std::is_floating_point_v<T>>>
    NumberFactory(T, dummy<1>=0) : number_type { FLOATING } {}
};

#endif

#if true

struct NumberFactory {
    enum { INTEGRAL, FLOATING } number_type;

    template<typename T>
        requires std::is_integral_v<T>
    NumberFactory(T) : number_type { INTEGRAL } {}

    int create_number() const;

    template<typename T>
        requires std::is_floating_point_v<T>
    NumberFactory(T) : number_type { FLOATING } {}
};

#endif

int NumberFactory::create_number() const {
    if (number_type == INTEGRAL)
        return 42;
    else return 0xDEADBEEF;
}

#endif
