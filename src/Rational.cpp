#include "../h/Rational.h"
#include <cassert>
#include <iostream>

using element_t = Rational::element_t;
using index_t = Rational::index_t;

static bool ShowProperFractions{true};

element_t GreatestCommonDivisor(element_t a, element_t b) {
    // using Euclidean algorithm
    if (a != 0 && b != 0) {
        if (a > b)
            a %= b;
        else
            b %= a;
    } else {
        if (a != 0)
            return a;
        else
            return b;
    }

    return GreatestCommonDivisor(a, b);
}

void Rational::ReduceFraction(){
    element_t gcd{GreatestCommonDivisor(std::abs(numerator), std::abs(denominator))};
    numerator /= gcd;
    denominator /= gcd;
    if (denominator < 0){
        numerator *= -1;
        denominator *= -1;
    }
}

Rational::Rational(element_t numerator_, element_t denominator_){
    assert(denominator != 0 && "Zero division!");
    numerator = numerator_;
    denominator = denominator_;
    ReduceFraction();
}


void Rational::print() {
    if (!ShowProperFractions){
        std::cout << numerator << '/' << denominator;
    } else {
        element_t f{numerator/denominator};
        if (f!=0){
            if (numerator%denominator == 0) {
                std::cout << f;
            } else {
                std::cout << f << '(' << std::abs(numerator)%denominator << '/' << denominator << ')';
            }
        } else {
            std::cout << (numerator)%denominator << '/' << denominator;
        }
    }
}

std::ostream& operator<< (std::ostream &out, const Rational &q)
{
    if (!ShowProperFractions){
        std::cout << q.numerator << '/' << q.denominator;
    } else {
        element_t f{q.numerator/q.denominator};
        if (f!=0){
            if (q.numerator%q.denominator == 0){
                out << f;
            } else {
                out << f << '(' << std::abs(q.numerator)%q.denominator << '/' << q.denominator << ')';
            }
        } else {
            out << (q.numerator)%q.denominator << '/' << q.denominator;
        }
    }
    return out;
}

std::istream& operator>> (std::istream &in, Rational &q)
{
    in >> q.numerator;
    in >> q.denominator;
    assert(q.denominator != 0 && "Zero division!");
    q.ReduceFraction();
    return in;
}

Rational Rational::sum(const Rational& q) const {
    return Rational( numerator*q.denominator+denominator*q.numerator,
            denominator*q.denominator);}

Rational operator+(const Rational& q1, const Rational& q2){
    return q1.sum(q2);
}

Rational operator+=(Rational& q1, const Rational& q2){
    q1 = q1+q2;
    return q1;
}

Rational Rational::negative(const Rational &q) const {return Rational(-numerator, denominator);}

Rational Rational::subtract(const Rational &q) const {
    return sum(negative(q));
}


Rational operator-(const Rational& q1, const Rational& q2){
    return q1.subtract(q2);
}

Rational operator-=(Rational& q1, const Rational& q2){
    q1 = q1-q2;
    return q1;
}

Rational Rational::multiply(const Rational& q) const {
    return Rational(numerator*q.numerator, denominator*q.denominator);
}


Rational operator*(const Rational& q1, const Rational& q2){
    return q1.multiply(q2);
}

Rational operator*=(Rational& q1, const Rational& q2){
    q1 = q1*q2;
    return q1;
}

Rational Rational::inverse(const Rational &q) const {
    return Rational(denominator, numerator);}

Rational Rational::divide(const Rational& q) const {
    return Rational(multiply(inverse(q)));
}


Rational operator/(const Rational& q1, const Rational& q2){
    return q1.divide(q2);
}

Rational operator/=(Rational& q1, const Rational& q2){
    q1 = q1/q2;
    return q1;
}

bool Rational::isEqual(const Rational& q) const {
    return (numerator == q.numerator) && (denominator == q.denominator);}