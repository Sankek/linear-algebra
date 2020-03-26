#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cstdlib>

#include "../h/Vector.h"
#include "../h/Matrix.h"
#include "../h/Rational.h"
#include "../h/Monome.h"
#include "../h/Polynome.h"
#include "../h/Solver.h"

using int_t = int_fast32_t;
using std::cout;
using namespace mathkeklib;

namespace RNG{
    std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}

int GetRandomNumber(int min, int max)
{
    std::uniform_int_distribution<> die{ min, max };
    return die(RNG::mersenne);
}

Rational GetRandomRational(){
    return Rational(GetRandomNumber(-2, 2), GetRandomNumber(3, 4));
}

Matrix GetRandomMatrix(int_t rows, int_t columns){
    Matrix matrix(rows, columns);
    for (int_t m{}; m<matrix.getSize(0); ++m){
        for (int_t n{}; n<matrix.getSize(1); ++n){
            matrix.setElement(m, n,
                    GetRandomNumber(-2, 2));
        }
    }
    return matrix;
}

Vector GetRandomVector(int_t size){
    Vector v(size);
    for (int_t m{}; m<v.getSize(); ++m){
        v.setElement(m, GetRandomNumber(-2, 2));
    }
    return v;
}

void PauseBeforeExit(){
    char ans{};
    while(true){
        std::cout << "Exit? Y/N?\n";
        std::cin >> ans;
        if (ans == 'Y'){
            exit(0);
        } else {
            std::cout << "Are you sure? ";
        }
    }
}

void MatrixPresentation(){
    std::cout << "--- Matrices presentation ---\n";
    std::cout << "Random 2x3 matrix A:\n";
    Matrix A{GetRandomMatrix(2, 3)};
    A.print();
    std::cout << "Random 3x4 matrix B:\n";
    Matrix B{GetRandomMatrix(3, 4)};
    B.print();
    std::cout << "Their product (A*B): \n";
    (A*B).print();
    std::cout << "Random 2x2 matrix C:\n";
    Matrix C{GetRandomMatrix(2, 2)};
    C.print();
    std::cout << "Another random 2x2 matrix D:\n";
    Matrix D{GetRandomMatrix(2, 2)};
    D.print();
    std::cout << "Their sum (C+D):\n";
    (C+D).print();
    std::cout << "Their difference (C-D):\n";
    (C-D).print();
    std::cout << "First multiplyed by 2 (2C):\n";
    (2*C).print();
}

void VectorPresentation(){
    std::cout << "--- Vectors presentation ---\n";
    std::cout << "Random 3D vector A:\n";
    Vector A{GetRandomVector(3)};
    A.print();
    std::cout << "Another random 3D vector B:\n";
    Vector B{GetRandomVector(3)};
    B.print();
    std::cout << "Their dot product (A*B):\n";
    std::cout << A*B << '\n';
    std::cout << "Their sum (A+B):\n";
    (A+B).print();
    std::cout << "Their difference (A-B):\n";
    (A-B).print();
    std::cout << "First multiplyed by 2 (2A):\n";
    (2*A).print();
}

void RationalPresentation(){
    std::cout << "--- Rational numbers presentation ---\n";
    Rational A{GetRandomRational()}, B{GetRandomRational()};
    std::cout << "Random rational numbers:\n";
    std::cout << "A: " << A << ", B:  " << B << '\n';
    if (A != 0){
        std::cout << "Inverse of A: " << A.inverse() << '\n';
    } else {
        std::cout << "There is no inverse for A\n";
    }
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
    std::cout << "A-B: " << A-B << '\n';
    std::cout << "A*B: " << A*B << '\n';
    std::cout << "A*3: " << A*3 << '\n';
    if (B != 0){
        std::cout << "A/B: " << A/B << '\n';
        std::cout << "4/B: " << 4/B << '\n';
    } else {
        std::cout << "A is not divisible by B\n";
    }
}

int main() {
    // If you want to show improper fractions change ShowProperFractions constant in Rational.cpp

//    RationalPresentation();
//    MatrixPresentation();
//    VectorPresentation();
    Solver Solver1;
    Solver1.SetBorders(0, 1);
    Solver1.SetInitialValue(0);
    Solver1.SetStep(0.01);
    std::string str = "1*x^2*y^0-2*x^0*y^1";
    Solver1.SetFunction(str);

    std::cout << "f(x, y): ";
    Solver1.PrintFunction();
    std::cout << '\n';
    std::cout << "Left border: " << Solver1.GetLeftBorder() << '\n';
    std::cout << "Right border: " << Solver1.GetRightBorder() << '\n';
    std::cout << "Step: " << Solver1.GetStep() << '\n';
    std::cout << "y(a): " << Solver1.GetInitialValue() << '\n';
    Solver1.Solve();
    Solver1.PrintSolution();

    std::cout << '\n';
    PauseBeforeExit();
    return 0;
}
