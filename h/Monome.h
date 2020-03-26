#ifndef MONOME_H
#define MONOME_H

#include <cmath>
#include <cassert>
#include <string>

namespace mathkeklib {

    // for 2 variables
    class Monome {
    private:
        int x_degree_{};
        int y_degree_{};
        double coeff_{};
    public:
        Monome(){};
        Monome(std::string str) { SetFromString(str); }

        void SetXDegree(const int& i){ x_degree_ = i; }
        void SetYDegree(const int& i){ y_degree_ = i; }
        void SetCoefficient(const double& c){ coeff_ = c; }
        void SetFromString(const std::string& str);
        double GetXDegree(){ return x_degree_; }
        double GetYDegree(){ return y_degree_; }
        double GetCoefficient(){ return coeff_; }
        double GetValue(const double& x, const double& y);

        void print();

        Monome operator+(const Monome& m);
        Monome operator-() const;
        Monome operator-(const Monome& m);
        Monome operator*(const Monome& m);

        Monome operator+=(const Monome& m);
        Monome operator-=(const Monome& m);
        Monome operator*=(const Monome& m);
    };

}

#endif
