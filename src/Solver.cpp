#include <iostream>

#include "../h/Solver.h"

namespace mathkeklib{

    void Solver::PrintSolution() {
        if (array_y_.empty()){
            std::cout << "Equation isn't solved.\n";
        } else {
            std::cout << '[' << array_y_[0];
            for (int i{1}; i<array_y_.size(); ++i){
                std::cout << ", " << array_y_[i];
            }
            std::cout << ']';
        }
    }

    void Solver::PrintPoints(int step) {
        if (array_y_.empty()){
            std::cout << "Equation isn't solved.\n";
        } else {
            std::cout << "[(" << left_border_value_ << ", " << array_y_[0] << ')';
            int i = step;
            for (; i<array_y_.size(); i+=step){
                std::cout << ", (" << left_border_+i*step_ << ", " << array_y_[i];
            }
            std::cout << ']';
        }
    }

    void Solver::Solve() {
        array_y_.resize(static_cast<int>((right_border_-left_border_)/step_+1));

        array_y_[0] = left_border_value_;
        for (int i{1}; i<array_y_.size(); ++i){
            array_y_[i] = array_y_[i-1] + step_*function_.GetValue(left_border_+(i-1)*step_, array_y_[i-1]);
        }

    }
}