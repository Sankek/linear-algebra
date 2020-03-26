#ifndef SOLVER_H
#define SOLVER_H

#include <vector>
#include <string>

#include "Polynome.h"

namespace mathkeklib {

    // Solver for y' = f(x, y) equation where x is on [a, b],
    // y(a) is known, f(x, y) is polynome
    class Solver {
    private:
        double step_{0.01};
        double left_border_{0};
        double right_border_{1};
        double left_border_value_{0};
        std::vector<double> array_y_{};
        Polynome function_{};
    public:
        Solver(){};
        Solver(std::string str) { function_.SetFromString(str); }
        void SetStep(double h) { step_ = h; }
        void SetBorders(double a, double b) { left_border_ = a; right_border_ = b; }
        void SetFunction(std::string str) { function_.SetFromString(str); }
        void SetInitialValue(double x) { left_border_value_ = x; }
        double GetStep() { return step_; }
        double GetLeftBorder() { return left_border_; }
        double GetRightBorder() { return right_border_; }
        double GetInitialValue() { return left_border_value_; }

        void PrintSolution();
        void PrintPoints(int step = 1);
        void PrintFunction() { function_.print(); }
        void Solve();
    };

}

#endif
