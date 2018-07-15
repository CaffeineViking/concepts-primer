#ifndef MATRIX_HH
#define MATRIX_HH

#include "concepts.h"

#include <array>
#include <ostream>
#include <stdexcept>
#include <algorithm>
#include <initializer_list>

// Not fully tested code, should *not*
// be used in production, or even in a
// hobby project. This is just to show
// that constraints can be applied for
// other things than function as well!

template<typename T, std::size_t R,
                     std::size_t C = R>
    requires Number<T>
class Matrix {
public:
    Matrix() = default;
    Matrix(std::initializer_list<T> list) {
        if (list.size() != data.size())
            throw std::out_of_range { "Non-matching matrix initializer!" };
        std::copy(list.begin(), list.end(),
                  data.begin());
    }

    constexpr std::size_t rows() const { return R; }
    constexpr std::size_t columns() const { return C; }
    constexpr std::size_t size() const { return R*C; }

    T& operator()(std::size_t row, std::size_t column) {
        if (row >= R || column >= C)
            throw std::out_of_range { "Faulty index!" };
        return data[row*C + column];
    }

    T operator()(std::size_t row, std::size_t column) const {
        if (row >= R || column >= C)
            throw std::out_of_range { "Faulty index!" };
        return data[row*C + column];
    }


    // Again, this could all probably be done better. This is
    // just an example after all :). If you find some example
    // that is more clear +- elegant, create a PR and fix it!

    template<typename U>
        requires ScalableWith<T, U> && Number<U>
    Matrix<T, R, C>& operator*=(U scalar) {
        std::for_each(data.begin(), data.end(),
                      [scalar](T& element) {
            element *= scalar;
        });

        return *this;
    }

    template<typename U>
        requires SummableWith<T, U> && Number<U>
    Matrix<T, R, C>& operator+=(U scalar) {
        std::for_each(data.begin(), data.end(),
                      [scalar](T& element) {
            element += scalar;
        });

        return *this;
    }

    template<typename U>
        requires SubtractableWith<T, U> && Number<U>
    Matrix<T, R, C>& operator-=(U scalar) {
        std::for_each(data.begin(), data.end(),
                      [scalar](T& element) {
            element -= scalar;
        });

        return *this;
    }

    Matrix<T, R, C>& operator*=(const Matrix<T, R, C>& matrix) {
        for (std::size_t i { 0 }; i < matrix.size(); ++i)
            data[i] *= matrix.data[i];
        return *this;
    }

    Matrix<T, R, C>& operator+=(const Matrix<T, R, C>& matrix) {
        for (std::size_t i { 0 }; i < matrix.size(); ++i)
            data[i] += matrix.data[i];
        return *this;
    }

    Matrix<T, R, C>& operator-=(const Matrix<T, R, C>& matrix) {
        for (std::size_t i { 0 }; i < matrix.size(); ++i)
            data[i] -= matrix.data[i];
        return *this;
    }

    Matrix<T, C, R> transpose() const {
        Matrix<T, C, R> matrix;
        // Not a good implementation. Can you figure
        // out why? :) Do you remember comp-sci 101?
        for (std::size_t i { 0 }; i < R; ++i) {
            for (std::size_t j { 0 }; j < C; ++j) {
                matrix(j, i) = (*this)(i, j);
            }
        }
    }

    template<std::size_t K>
    Matrix<T, R, C> dot(const Matrix<T, C, K>& matrix) {
        Matrix<T, R, K> temporary;
        for (std::size_t i { 0 }; i < R; ++i) {
            for (std::size_t k { 0 }; k < K; ++k) {
                T sum {  };
                for (std::size_t j { 0 }; j < C; ++j)
                    sum += (*this)(i,j) * matrix(j,k);
                temporary(i,k) = sum;
            }
        }

        return temporary;
    }

    // More operations, like cross products etc.. Should
    // be defined for this to be a more complete matrix.

private:
    std::array<T, R*C> data; // Might be bad b.c. we'll
    // run out of stack space if we aren't careful. The
    // good way to do this would be to choose depending
    // on the amounts of elements if we should allocate
    // on the stack or on the heap. Simplicity for now.
};

template<typename T, std::size_t R, std::size_t C>
std::ostream& operator<<(std::ostream& stream,
                         const Matrix<T, R, C>& matrix) {
    for (std::size_t i { 0 }; i < R; ++i) {
        for (std::size_t j { 0 }; j < C; ++j) {
            stream << matrix(i, j) << " ";
        } stream << '\n';
    }

    return stream;
}

#endif
