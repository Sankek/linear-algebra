#ifndef MATRIX_H
#define MATRIX_H

#include <cstdint>

class Matrix{
public:
    using index_t = int_fast32_t;
    using element_t = double;
private:
    element_t **array;
    index_t size[2];
    Matrix arithmeticOperation(const Matrix& v, element_t (*operationFunc)(element_t, element_t));

    static element_t addOperation(element_t x, element_t y){return x+y;}
    static element_t subtractOperation(element_t x, element_t y){return x-y;}
    static element_t multiplyOperation(element_t x, element_t y){return x*y;}
    static element_t divideOperation(element_t x, element_t y){return x/y;}

public:
    Matrix(index_t m=1, index_t n=1);
    ~Matrix();
    void fill();
    void print();
    element_t getElement(const index_t& m, const index_t& n) const ;
    index_t getSize(index_t i) const ;
    void setElement(index_t m, index_t n,  element_t x);

    Matrix sum(const Matrix& v){ return arithmeticOperation(v, addOperation); }
    Matrix subtract(const Matrix& v){ return arithmeticOperation(v, subtractOperation); }
    Matrix multiply(const Matrix& v){ return arithmeticOperation(v, multiplyOperation); }
    Matrix divide(const Matrix& v){ return arithmeticOperation(v, divideOperation); }
    Matrix dot(Matrix& v);
};


#endif
