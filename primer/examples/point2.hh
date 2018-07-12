#ifndef POINT2_HH
#define POINT2_HH

#include <ostream>

struct point2 {
    double x, y;
    point2& operator/=(const double);
    point2& operator*=(const double);
    point2& operator+=(const point2&);
};

point2 operator+(const point2&, const point2&);
point2 operator/(const point2&, const double);
point2 operator*(const point2&, const double);
point2 operator*(const double,  const point2&);

std::ostream& operator<<(std::ostream&, const point2&);

#endif
