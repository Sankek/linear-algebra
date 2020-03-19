#include "../h/Matrix.h"
#include <cassert>
#include <iostream>

using element_t = mathkeklib::Matrix::element_t;
using index_t = mathkeklib::Matrix::index_t;

namespace mathkeklib {

    Matrix Matrix::arithmeticOperation(const Matrix &v, element_t (*operationFunc)(element_t, element_t)) {
        assert((v.getSize(0) == size[0]) && (v.getSize(1) == size[1]) && "Operands don't match in size.");
        Matrix matr_temp(size[0], size[1]);
        for (index_t m{0}; m < size[0]; ++m) {
            for (index_t n{0}; n < size[1]; ++n) {
                matr_temp.setElement(m, n, (*operationFunc)(array[m][n], v.getElement(m, n)));
            }
        }
        return matr_temp;
    }

    index_t Matrix::getSize(index_t i) const {
        assert(i >= 0 && i <= 1 && "Incorrect index");
        return size[i];
    }

    Matrix::Matrix(index_t m, index_t n) {
        size[0] = m;
        size[1] = n;

        array = new element_t *[m]{};
        for (index_t i{}; i < m; ++i) {
            array[i] = new element_t[n]{};
        }
    }

    Matrix::~Matrix() {
        for (index_t i{}; i < size[0]; ++i) {
            delete[] array[i];
        }
        delete[] array;
    }

    Matrix::Matrix(const Matrix &matrix) :
            array{nullptr} {

        size[0] = matrix.size[0];
        size[1] = matrix.size[1];
        if (array) {
            for (index_t i{}; i < size[0]; ++i) {
                if (array[i]) {
                    delete[] array[i];
                }
            }
            delete[] array;
        }

        array = new element_t *[size[0]]{};
        for (index_t i{}; i < size[0]; ++i) {
            array[i] = new element_t[size[1]]{};
        }

        for (index_t m{}; m < size[0]; ++m) {
            for (index_t n{}; n < size[1]; ++n) {
                array[m][n] = matrix.array[m][n];
            }
        }
    }

    Matrix &Matrix::operator=(const Matrix &matrix) {
        if (this == &matrix) {
            return *this;
        }

        size[0] = matrix.size[0];
        size[1] = matrix.size[1];

        for (index_t i{}; i < size[0]; ++i) {
            delete[] array[i];
        }
        delete[] array;

        array = new element_t *[size[0]]{};
        for (index_t i{}; i < size[0]; ++i) {
            array[i] = new element_t[size[1]]{};
        }

        for (index_t m{}; m < size[0]; ++m) {
            for (index_t n{}; n < size[1]; ++n) {
                array[m][n] = matrix.array[m][n];
            }
        }
        return *this;
    }

    void Matrix::fill() {
        std::cout << "Enter " << size[0] * size[1] << " values: \n";
        for (index_t m{}; m < size[0]; ++m) {
            for (index_t n{}; n < size[1]; ++n) {
                std::cin >> array[m][n];
            }
        }
    }

    void Matrix::print() {
        for (index_t m{}; m < size[0]; ++m) {
            std::cout << '[' << array[m][0];
            for (index_t n{1}; n < size[1]; ++n) {
                std::cout << ", " << array[m][n];
            }
            std::cout << "]\n";
        }
    }

    element_t Matrix::getElement(const index_t &m, const index_t &n) const {
        assert(m >= 0 && m < size[0] && "Incorrect index");
        assert(n >= 0 && n < size[1] && "Incorrect index");
        return array[m][n];
    }

    void Matrix::setElement(index_t m, index_t n, element_t x) {
        assert(m >= 0 && m < size[0] && "Incorrect index");
        assert(n >= 0 && n < size[1] && "Incorrect index");
        array[m][n] = x;
    }

    Matrix Matrix::dot(Matrix &v) {
        assert(size[1] == v.getSize(0) && "Operands don't match in size.");
        Matrix matr_temp(size[0], v.getSize(1));
        element_t sum{};
        for (index_t m{}; m < size[0]; ++m) {
            for (index_t n{}; n < v.getSize(1); ++n) {
                for (index_t i{}; i < size[1]; ++i) {
                    sum += array[m][i] * v.getElement(i, n);
                }
                matr_temp.setElement(m, n, sum);
                sum = 0;
            }
        }
        return matr_temp;
    }
}
