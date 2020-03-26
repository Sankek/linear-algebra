#include <iostream>

#include "../h/Polynome.h"

namespace mathkeklib {

    double Polynome::GetValue(double x, double y){
        double value{};
        for (Monome m : monomes_){
            value += m.GetValue(x, y);
        }
        return value;
    }

    void Polynome::AddMonome(Monome monome){
        for (Monome& m : monomes_){
            if ( (m.GetXDegree() == monome.GetXDegree()) &&
                 (m.GetYDegree() == monome.GetYDegree()) ) {
                m += monome;
                return;
            }
        }
        monomes_.push_back(monome);
    }

    void Polynome::SetFromString(std::string str){
        monomes_ = {};
        for (int i{}, last{}; i<=str.length(); ++i){
            switch (str[i]){
                case '-':
                case '+':
                case '\0':
                    if (i != 0){
                        if (str[i-1] != '^'){
                            AddMonome(Monome(str.substr(last, i-last)));
                            last = i;
                        }
                    }


            }
        }
    }

    void Polynome::print(){
        for (Monome m : monomes_){
            if (m.GetCoefficient() > 0){
                std::cout << '+';
            }
            m.print();
        }
    }

}
