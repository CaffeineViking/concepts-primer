#include "point2.hh"

#include <iostream>

point2 centroid(const point2* begin,
                const point2* const end) {
    point2 sum {  };
    const double size = end - begin;
    while (begin != end)
        sum += *begin++;
    return sum / size;
}

int main(int, char**) {
    point2 points[] { { -1, +1 }, { +1, +1 },
                      { -1, -1 }, { +1, -1 } };
    auto points_size = sizeof(points) / sizeof(point2);
    std::cout << centroid(points, points + points_size)
              << std::endl;
    return 0;
}
