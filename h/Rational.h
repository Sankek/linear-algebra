#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdint>
#include <iostream>

namespace mathkeklib{

    class Rational {
    public:
        using element_t = int_fast32_t;
        using index_t = int_fast32_t;

    private:
        element_t numerator{};
        element_t denominator{1};
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
        Rational inverse() const;
        Rational divide(const Rational& q) const;
        bool isEqual(const Rational& q) const;
        bool isLess(const Rational& q) const;
        bool isLessEqual(const Rational& q) const;
        bool isGreater(const Rational& q) const;
        bool isGreaterEqual(const Rational& q) const;
    };

    Rational operator-(const Rational& q);
    Rational operator+(const Rational& q1, const Rational& q2);
    Rational operator-(const Rational& q1, const Rational& q2);
    Rational operator*(const Rational& q1, const Rational& q2);
    Rational operator/(const Rational& q1, const Rational& q2);

    Rational operator+=(Rational& q1, const Rational& q2);
    Rational operator-=(Rational& q1, const Rational& q2);
    Rational operator*=(Rational& q1, const Rational& q2);
    Rational operator/=(Rational& q1, const Rational& q2);

    bool operator==(const Rational& q1, const Rational& q2);
    bool operator!=(const Rational& q1, const Rational& q2);
    bool operator<(const Rational& q1, const Rational& q2);
    bool operator<=(const Rational& q1, const Rational& q2);
    bool operator>(const Rational& q1, const Rational& q2);
    bool operator>=(const Rational& q1, const Rational& q2);

    // The same but with int

    Rational operator+(const Rational& q1, const int& q2);
    Rational operator-(const Rational& q1, const int& q2);
    Rational operator*(const Rational& q1, const int& q2);
    Rational operator/(const Rational& q1, const int& q2);

    Rational operator+=(Rational& q1, const int& q2);
    Rational operator-=(Rational& q1, const int& q2);
    Rational operator*=(Rational& q1, const int& q2);
    Rational operator/=(Rational& q1, const int& q2);

    bool operator==(const Rational& q1, const int& q2);
    bool operator!=(const Rational& q1, const int& q2);
    bool operator<(const Rational& q1, const int& q2);
    bool operator<=(const Rational& q1, const int& q2);
    bool operator>(const Rational& q1, const int& q2);
    bool operator>=(const Rational& q1, const int& q2);


    Rational operator+(const int& q1, const Rational& q2);
    Rational operator-(const int& q1, const Rational& q2);
    Rational operator*(const int& q1, const Rational& q2);
    Rational operator/(const int& q1, const Rational& q2);

    int operator+=(int& q1, const Rational& q2);
    int operator-=(int& q1, const Rational& q2);
    int operator*=(int& q1, const Rational& q2);
    int operator/=(int& q1, const Rational& q2);

    bool operator==(const int& q1, const Rational& q2);
    bool operator!=(const int& q1, const Rational& q2);
    bool operator<(const int& q1, const Rational& q2);
    bool operator<=(const int& q1, const Rational& q2);
    bool operator>(const int& q1, const Rational& q2);
    bool operator>=(const int& q1, const Rational& q2);
}
#endif
