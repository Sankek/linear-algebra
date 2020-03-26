#ifndef MATRIX_H
#define MATRIX_H

#include "../h/Rational.h"
#include <cstdint>

namespace mathkeklib{

    class Matrix{
    public:
        using index_t = int_fast32_t;
        using element_t = double;
    private:
        element_t **array;
        index_t size[2]{};

        Matrix unaryOperation(element_t (*operationFunc)(element_t)) const;
        static element_t negativeOperation(element_t x){return -x;}
        
        Matrix binaryOperation(const Matrix& v, element_t (*operationFunc)(element_t, element_t)) const;
        Matrix binaryOperation(const element_t& c, element_t (*operationFunc)(element_t, element_t)) const;
        static element_t addOperation(element_t x, element_t y){return x+y;}
        static element_t subtractOperation(element_t x, element_t y){return (x-y);}
        static element_t multiplyOperation(element_t x, element_t y){return x*y;}
        static element_t divideOperation(element_t x, element_t y){return x/y;}

    public:
        Matrix(index_t m=1, index_t n=1);
        ~Matrix();
        Matrix(const Matrix& matrix);
        Matrix& operator=(const Matrix& Matrix);
        void fill();
        void print();
        element_t getElement(const index_t& m, const index_t& n) const ;
        index_t getSize(index_t i) const ;
        void setElement(index_t m, index_t n,  element_t x);

        Matrix negative() const { return unaryOperation(negativeOperation); }
        Matrix sum(const Matrix& v) const { return binaryOperation(v, addOperation); }
        Matrix subtract(const Matrix& v) const { return binaryOperation(v, subtractOperation); }
        Matrix multiply(const Matrix& v) const { return binaryOperation(v, multiplyOperation); }
        Matrix multiply(const element_t& c) const { return binaryOperation(c, multiplyOperation); }
        Matrix divide(const Matrix& v) const { return binaryOperation(v, divideOperation); }
        Matrix divide(const element_t& c) const { return binaryOperation(c, divideOperation); }
        Matrix dot(const Matrix& v) const;
        bool isEqual(const Matrix& v) const;

        Matrix operator-() const;
        Matrix operator+(const Matrix& v) const;
        Matrix operator-(const Matrix& v) const;
        Matrix operator*(const Matrix& v) const;
        Matrix operator*(const element_t& c) const;
        Matrix operator/(const element_t& c) const;
        friend Matrix operator*(const element_t& c, const Matrix& v) { return v*c; }
        friend Matrix operator/(const element_t& c, const Matrix& v) { return v/c; }

        Matrix operator+=(const Matrix& v);
        Matrix operator-=(const Matrix& v);
        Matrix operator*=(const element_t& c);
        Matrix operator/=(const element_t& c);

        bool operator==(const Matrix& v) const;
        bool operator!=(const Matrix& v) const;
        
    };
}


#endif
