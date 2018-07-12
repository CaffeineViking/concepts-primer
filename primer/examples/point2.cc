#include "point2.hh"

point2& point2::operator/=(const double scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

point2& point2::operator*=(const double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

point2& point2::operator+=(const point2& point) {
    x += point.x;
    y += point.y;
    return *this;
}

point2 operator+(const point2& p1, const point2& p2) {
    point2 temporary { p1 };
    temporary += p2;
    return temporary;
}

point2 operator/(const point2& point, const double scalar) {
    point2 temporary { point };
    temporary /= scalar;
    return temporary;
}

point2 operator*(const point2& point, const double scalar) {
    point2 temporary { point };
    temporary *= scalar;
    return temporary;
}

point2 operator*(const double scalar, const point2& point) {
    point2 temporary { point };
    temporary *= scalar;
    return temporary;
}

std::ostream& operator<<(std::ostream& stream, const point2& point) {
    stream << '(' << point.x << ","
                  << point.y <<  ')';
    return stream;
}
