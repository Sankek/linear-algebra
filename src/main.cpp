#include <iostream>
#include <string>
#include "../h/Vector.h"
#include "../h/Matrix.h"
#include "../h/Rational.h"
#include <random>
#include <ctime>
#include <cstdlib>

using int_t = int_fast32_t;
using std::cout;

namespace RNG{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int GetRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die{ min, max };
    return die(RNG::mersenne);
}

Matrix GetRandomRationalMatrix(int_t rows, int_t columns){
    Matrix matrix(rows, columns);
    for (int_t m{}; m<matrix.getSize(0); ++m){
        for (int_t n{}; n<matrix.getSize(1); ++n){
            matrix.setElement(m, n,
                    Rational(GetRandomNumber(-20, 20),
                            GetRandomNumber(1, 20)));
        }
    }
    return matrix;
}

void PauseBeforeExit(){
    char ans{};
    while(true){
        cout << "Exit? Y/N?\n";
        std::cin >> ans;
        if (ans == 'Y'){
            exit(0);
        } else {
            cout << "Are you sure? ";
        }
    }
}

void MatrixPresentation(){
    std::cout << "--- Matrices presentation ---\n";
    std::cout << "Random matrix 2x3 matrix:\n";
    Matrix A{GetRandomRationalMatrix(2, 3)};
    A.print();
    std::cout << "Random matrix 3x4 matrix:\n";
    Matrix B{GetRandomRationalMatrix(3, 4)};
    B.print();
    cout << "Their product: \n";
    A.dot(B).print();
}

void VectorPresentation(){
    std::cout << "--- Vectors presentation ---\n";
    cout << "Fill two vectors with fractions, please!\n";
    Vector v1(3);
    Vector v2(3);
    v1.fill();
    cout << '\n';
    v2.fill();
    cout << "v1:\n";
    v1.print();
    cout << "v2:\n";
    v2.print();
    cout << "Dot product of v1, v2: " << v1.dot(v2) << '\n';
}

void RationalPresentation(){
    std::cout << "--- Rational numbers presentation ---\n";
    Rational A{}, B{};
    std::cout << "Enter two rational numbers (e.g. 2/3):";
    std::cin >> A >> B;
    std::cout << "A: " << A << ", B:  " << B << '\n';
    std::cout << "Inverse of A: " << A.inverse() << '\n';
    if (A<B){
        std::cout << "A<B, ";
    } else {
        std::cout << "A>=B, ";
    }
    if (A==B) {
        std::cout << "A==B, ";
    } else {
        std::cout << "A!=B, ";
    }
    std::cout << "A+B: " << A+B << '\n';
    std::cout << "A*B: " << A*B << '\n';
    std::cout << "A/B: " << A/B << '\n';
}

int main() {
    // If you want to show improper fractions change ShowProperFractions constant in Rational.cpp

    RationalPresentation();
    MatrixPresentation();
    VectorPresentation();

    cout << '\n';
    PauseBeforeExit();
    return 0;
}
