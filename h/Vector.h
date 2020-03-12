#ifndef VECTOR_H
#define VECTOR_H

#include <cstdint>

class Vector{
public:
    using index_t = int_fast32_t ;
    using element_t = double;
private:
    element_t *array;
    index_t size;

    Vector arithmeticOperation(const Vector& v, element_t (*operationFunc)(element_t, element_t));

    static element_t addOperation(element_t x, element_t y){return x+y;}
    static element_t subtractOperation(element_t x, element_t y){return x-y;}
    static element_t multiplyOperation(element_t x, element_t y){return x*y;}
    static element_t divideOperation(element_t x, element_t y){return x/y;}

public:
    Vector(index_t n=1);
//    ~Vector(){delete[] array;}
    void fill();
    void print();
    element_t getElement(const index_t& i) const ;
    element_t getSize() const {return size;};
    void setElement(index_t i, element_t x);

    Vector sum(const Vector& v){ return arithmeticOperation(v, addOperation); }
    Vector subtract(const Vector& v){ return arithmeticOperation(v, subtractOperation); }
    Vector multiply(const Vector& v){ return arithmeticOperation(v, multiplyOperation); }
    Vector divide(const Vector& v){ return arithmeticOperation(v, divideOperation); }
    element_t dot(const Vector& v);
};

#endif
