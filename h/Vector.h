#ifndef VECTOR_H
#define VECTOR_H

#include "../h/Rational.h"
#include <cstdint>

namespace mathkeklib{

    class Vector{
    public:
        using index_t = int_fast32_t ;
        using element_t = double;
    private:
        element_t *array;
        index_t size;

        Vector unaryOperation(element_t (*operationFunc)(element_t)) const;
        static element_t negativeOperation(element_t x){return -x;}

        Vector binaryOperation(const Vector& v, element_t (*operationFunc)(element_t, element_t)) const;
        Vector binaryOperation(const element_t& c, element_t (*operationFunc)(element_t, element_t)) const;
        static element_t addOperation(element_t x, element_t y){return x+y;}
        static element_t subtractOperation(element_t x, element_t y){return x-y;}
        static element_t multiplyOperation(element_t x, element_t y){return x*y;}
        static element_t divideOperation(element_t x, element_t y){return x/y;}

    public:
        Vector(index_t n=1);
        ~Vector(){delete[] array;}
        Vector(const Vector& matrix);
        Vector& operator=(const Vector& Matrix);
        void fill();
        void print();
        element_t getElement(const index_t& i) const ;
        index_t getSize() const {return size;};
        void setElement(index_t i, element_t x);

        Vector negative() const { return unaryOperation(negativeOperation);}
        Vector sum(const Vector& v) const { return binaryOperation(v, addOperation); }
        Vector subtract(const Vector& v) const { return binaryOperation(v, subtractOperation); }
        Vector multiply(const Vector& v) const { return binaryOperation(v, multiplyOperation); }
        Vector multiply(const element_t& c) const { return binaryOperation(c, multiplyOperation); };
        Vector divide(const Vector& v) const { return binaryOperation(v, divideOperation); }
        Vector divide(const element_t& c) const { return binaryOperation(c, divideOperation); }
        element_t dot(const Vector& v) const;
        bool isEqual(const Vector& v) const;

        Vector operator-() const;
        Vector operator+(const Vector& v) const;
        Vector operator-(const Vector& v) const;
        element_t operator*(const Vector& v) const;
        Vector operator*(const element_t& c) const;
        Vector operator/(const element_t& c) const;
        friend Vector operator*(const element_t& c, const Vector& v) { return v*c; }
        friend Vector operator/(const element_t& c, const Vector& v) { return v/c; }

        Vector operator+=(const Vector& v);
        Vector operator-=(const Vector& v);
        Vector operator*=(const element_t& c);
        Vector operator/=(const element_t& c);

        bool operator==(const Vector& v) const;
        bool operator!=(const Vector& v) const;
    };


    
}
#endif
