#ifndef SCHEMECIR_H
#define SCHEMECIR_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Scheme.h"

namespace mathkeklib {

    class SchemeCIR : public Scheme {
    private:
        std::vector<double> values_{};

    protected:
        void NextStep();
        void ToCSV(std::ofstream& file, const std::vector<double>& values);
        void Print(std::vector<double> v);

    public:
        SchemeCIR(int length_steps, int time_steps) : Scheme(length_steps, time_steps) {}
        SchemeCIR() = default;

        std::vector<double> Init();
        void Calculate();
        void Calculate(std::ofstream& file);
        std::vector<double> GetValues() { return values_; }

        void PrintValues() { Print(values_);}
    };

}

#endif
