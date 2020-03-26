#ifndef POLYNOME_H
#define POLYNOME_H

#include <vector>
#include <string>

#include "../h/Monome.h"

namespace mathkeklib {

    // for 2 variables
    class Polynome {
    private:
        std::vector<Monome> monomes_{};
    public:
        Polynome(){};
        Polynome(std::string str) { SetFromString(str); }
        void AddMonome(Monome m);
        void SetFromString(std::string str);
        double GetValue(double x, double y);

        void print();
    };

}

#endif
