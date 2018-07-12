#include "concepts.h"
#include "point2.hh"

#include <iostream>
#include <string>

template<typename T>
    requires DefaultConstructible<T> &&
             SummableWith<T, T> &&
             ScalableWith<T, double>
T average(const T* begin,
          const T* const end) {
    T sum {  };
    const double size = end - begin;
    while (begin != end)
        sum += *begin++;
    return sum / size;
}

int main(int, char**) {
    double numbers[] { 1, 2, 3, 4, 5 };
    auto numbers_size { sizeof(numbers) / sizeof(double) };
    std::cout << average(numbers, numbers + numbers_size)
              << std::endl;

    point2 points[] { { -1, +1 }, { +1, +1 },
                      { -1, -1 }, { +1, -1 } };
    auto points_size = sizeof(points) / sizeof(point2);
    std::cout << average(points, points + points_size)
              << std::endl;

#if false // switch to 'true' to see a error message!
    std::string strings[] { "1", "2", "3", "4", "5" };
    auto strings_size = sizeof(strings) / sizeof(std::string);
    std::cout << average(strings, strings + strings_size)
              << std::endl;
#endif
    return 0;
}
