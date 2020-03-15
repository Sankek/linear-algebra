#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdint>
#include <iostream>


class Rational {
public:
    using element_t = int_fast32_t;
    using index_t = int_fast32_t;

private:
    element_t numerator{};
    element_t denominator{1};
    bool proper{};
    void ReduceFraction();

public:
    Rational(element_t numerator_=0, element_t denominator_=1);
    void print();
    friend std::ostream& operator<< (std::ostream &out, const Rational &q);
    friend std::istream& operator>> (std::istream &in, Rational &q);

    element_t getNumerator() const {return numerator;}
    element_t getDenominator() const {return denominator;}

    Rational sum(const Rational& q) const;
    Rational negative(const Rational& q) const;
    Rational subtract(const Rational& q) const;
    Rational multiply(const Rational& q) const;
    Rational inverse(const Rational& q) const;
    Rational divide(const Rational& q) const;
    bool isEqual(const Rational& q) const;
};

Rational operator+(const Rational& q1, const Rational& q2);
Rational operator-(const Rational& q1, const Rational& q2);
Rational operator*(const Rational& q1, const Rational& q2);
Rational operator/(const Rational& q1, const Rational& q2);

Rational operator+=(Rational& q1, const Rational& q2);
Rational operator-=(Rational& q1, const Rational& q2);
Rational operator*=(Rational& q1, const Rational& q2);
Rational operator/=(Rational& q1, const Rational& q2);



#endif
