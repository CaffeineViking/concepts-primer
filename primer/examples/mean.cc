#include <iostream>

double mean(const double* begin,
            const double* const end) {
    double sum {  };
    const double size = end - begin;
    while (begin != end)
        sum += *begin++;
    return sum / size;
}

int main(int, char**) {

    double numbers[] { 1, 2, 3, 4, 5 };
    auto numbers_size { sizeof(numbers) / sizeof(double) };
    std::cout << mean(numbers, numbers + numbers_size)
              << std::endl;

    return 0;
}
