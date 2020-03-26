#include "../h/Vector.h"
#include <cassert>
#include <iostream>

using element_t = mathkeklib::Vector::element_t;
using index_t = mathkeklib::Vector::index_t;

namespace mathkeklib {

    Vector Vector::binaryOperation(const Vector &v, element_t (*operationFunc)(element_t, element_t)) const {
        assert(v.getSize() == size && "Operands don't match in size.");
        Vector v_temp(size);
        for (index_t i{}; i < size; ++i) {
            v_temp.setElement(i, (*operationFunc)(array[i], v.getElement(i)));
        }
        return v_temp;
    }

    Vector Vector::binaryOperation(const element_t &c, element_t (*operationFunc)(element_t, element_t)) const {
        Vector v_temp(size);
        for (index_t i{}; i < size; ++i) {
            v_temp.setElement(i, (*operationFunc)(array[i], c));
        }
        return v_temp;
    }

    Vector Vector::unaryOperation(element_t (*operationFunc)(element_t)) const {
        Vector v_temp(size);
        for (index_t i{}; i < size; ++i) {
            v_temp.setElement(i, (*operationFunc)(array[i]));
        }
        return v_temp;
    }

    Vector::Vector(index_t n) {
        size = n;
        array = new element_t[n]{};
    }

    Vector::Vector(const Vector &vector) :
            array{nullptr} {
        size = vector.size;

        delete[] array;
        array = new element_t[size]{};

        for (index_t i{}; i < size; ++i) {
            array[i] = vector.array[i];
        }
    }

    Vector &Vector::operator=(const Vector &vector) {
        if (this == &vector) {
            return *this;
        }
        size = vector.size;

        delete[] array;
        array = new element_t[size]{};

        for (index_t i{}; i < size; ++i) {
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

    void Vector::print() {
        std::cout << '[' << array[0];
        for (index_t i{1}; i < size; ++i) {
            std::cout << ", " << array[i];
        }
        std::cout << "]\n";
    }

    element_t Vector::getElement(const index_t &i) const {
        assert(i >= 0 || i < size && "Incorrect index");
        return array[i];
    }

    void Vector::setElement(index_t i, element_t x) {
        assert(i >= 0 || i < size && "Incorrect index");
        array[i] = x;
    }

    element_t Vector::dot(const Vector &v) const {
        assert(v.getSize() == size && "Operands don't match in size.");
        element_t product{};
        for (index_t i{0}; i < size; ++i) {
            product += array[i] * v.getElement(i);
        }
        return product;
    }

    bool Vector::isEqual(const Vector &v) const {
        if (size != v.size){
            return false;
        } else {
            for (index_t i{}; i<size; ++i){
                if (array[i] != v.array[i]){
                    return false;
                }
            }
        }
        return true;
    }

    Vector Vector::operator-() const {
        return negative();
    }

    Vector Vector::operator+(const Vector& v) const {
        return sum(v);
    }

    Vector Vector::operator-(const Vector& v) const {
        return sum(v.negative());
    }

    element_t Vector::operator*(const Vector& v) const{
        return dot(v);
    }

    Vector Vector::operator*(const element_t& c) const{
        return multiply(c);
    }

    Vector Vector::operator/(const element_t& c) const{
        return divide(c);
    }

    Vector Vector::operator+=(const Vector& v){
        *this = *this + v;
        return *this;
    }

    Vector Vector::operator-=(const Vector& v){
        *this = *this - v;
        return *this;
    }

    Vector Vector::operator*=(const element_t& c) {
        *this = (*this * c);
        return *this;
    }

    Vector Vector::operator/=(const element_t& c) {
        *this = (*this * c);
        return *this;
    }

    bool Vector::operator==(const Vector& v) const {
        return this->isEqual(v);
    }
    bool Vector::operator!=(const Vector& v) const {
        return !(this->isEqual(v));
    }
}