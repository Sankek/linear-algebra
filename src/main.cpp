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

void MatrixPresentation(){
    Matrix A{GetRandomRationalMatrix(2, 3)};
    A.print();
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    Matrix B{GetRandomRationalMatrix(3, 4)};
    B.print();
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "Their product: \n";
    A.dot(B).print();
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
}

void VectorPresentation(){
    cout << "\nFill two vectors with fractions, please!\n";
    Vector v1(3);
    Vector v2(3);
    v1.fill();
    cout << '\n';
    v2.fill();
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
    cout << "v1:\n";
    v1.print();
    cout << "v2:\n";
    v2.print();
    cout << "Dot product of v1, v2: " << v1.dot(v2) << '\n';
}

int main() {
    MatrixPresentation();
    VectorPresentation();

    cout << '\n';
    char ans{};
    while(true){
        cout << "Exit? Y/N?\n";
        std::cin >> ans;
        if (ans == 'Y'){
            return 0;
        } else {
            cout << "Are you sure? ";
        }
    }
    return 0;
}
