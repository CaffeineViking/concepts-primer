#include "matrix.hh"

#include <string>
#include <iostream>

int main(int, char**) {
    Matrix<int, 2,2> n { 1, 0,
                         0, 1 };
    Matrix<int, 2,2> m { 0, 1,
                         1, 0 };
    std::cout << n << std::endl;
    n += m; // Element-wise add.
    std::cout << n << std::endl;
    n -= m; // Element-wise sum.
    std::cout << n << std::endl;
    n *= 5; // Scalar multiplier
    std::cout << n << std::endl;
    n = n *= m; // Dot product!!
    std::cout << n << std::endl;

#if false // Set to 'true' fail.
    Matrix<std::string, 2, 2> s;
#endif

    return 0;
}
