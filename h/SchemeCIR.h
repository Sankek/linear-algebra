#ifndef SCHEMECIR_H
#define SCHEMECIR_H

#include <iostream>
#include <vector>

#include "Scheme.h"

namespace mathkeklib {

    class SchemeCIR : public Scheme {
    private:
        std::vector<double> values_new{};
        std::vector<double> values_old{};

    protected:
        void NextStep();
        void Print(std::vector<double> v);

    public:
        SchemeCIR(int length_steps, int time_steps) : Scheme(length_steps, time_steps) {}
        SchemeCIR() = default;

        std::vector<double> Init();
        void Calculate();
        std::vector<double> GetValues() { return values_new; }

        void PrintLast() {Print(values_old); }
        void PrintNew() { Print(values_new);}
    };

}

#endif
