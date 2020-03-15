#include "../h/Vector.h"
#include <cassert>
#include <iostream>

using element_t = Vector::element_t;
using index_t = Vector::index_t;

Vector Vector::arithmeticOperation(const Vector& v, element_t (*operationFunc)(element_t, element_t)) {
    assert(v.getSize() == size && "Operands don't match in size.");
    Vector v_temp(size);
    for (index_t i{}; i<size; ++i){
        v_temp.setElement(i, (*operationFunc)(array[i], v.getElement(i)));
    }
    return v_temp;
}

Vector::Vector(index_t n){
    size = n;
    array = new element_t[n]{};
}

Vector::Vector(const Vector& vector):
    array{nullptr} {
    size = vector.size;

    delete[] array;
    array = new element_t[size]{};

    for (index_t i{}; i<size; ++i) {
        array[i] = vector.array[i];
    }
}

Vector& Vector::operator=(const Vector& vector) {
    if (this == &vector){
        return *this;
    }
    size = vector.size;

    delete[] array;
    array = new element_t[size]{};

    for (index_t i{}; i<size; ++i) {
        array[i] = vector.array[i];
    }
    return *this;
}

void Vector::fill() {
    std::cout << "Enter " << size << " values: ";
    for (index_t i{}; i < size; ++i) {
        std::cin >> array[i];
    }
}

void Vector::print(){
    std::cout << '[' << array[0];
    for (index_t i{1}; i<size; ++i){
        std::cout << ", " << array[i];
    }
    std::cout << "]\n";
}

element_t Vector::getElement(const index_t& i) const {
    assert(i>=0 || i<size && "Incorrect index");
    return array[i];
}

void Vector::setElement(index_t i, element_t x){
    assert(i>=0 || i<size && "Incorrect index");
    array[i] = x;
}

element_t Vector::dot(const Vector& v){
    assert(v.getSize() == size && "Operands don't match in size.");
    element_t product{};
    for (index_t i{0}; i<size; ++i){
        product += array[i]*v.getElement(i);
    }
    return product;
}