#include <iostream>
#include <string>

#include "../h/Monome.h"

namespace mathkeklib{


    double Monome::GetValue(const double& x, const double& y){
        assert((x!=0 || x_degree_ >= 0) && "Zero division!");
        assert((y!=0 || y_degree_ >= 0) && "Zero division!");
        return coeff_ * pow(x, x_degree_) * pow(y, y_degree_);
    }

    void Monome::SetFromString(const std::string& str){
        int x_enc{}, y_enc{};

        x_enc = str.find('x');
        y_enc = str.find('y', x_enc);

        assert(x_enc>0 && y_enc>0 && "Invalid input");

        coeff_ = std::stod(str.substr(0, x_enc-1));
        x_degree_ = std::stoi(str.substr(x_enc+2, y_enc-x_enc-3));
        y_degree_ = std::stoi(str.substr(y_enc+2, str.length()-y_enc-1));
    }

    void Monome::print(){
        std::cout << coeff_ << "*x^" << x_degree_ << "*y^" << y_degree_;
    }

    Monome Monome::operator+(const Monome& m){
        assert((x_degree_ == m.x_degree_) && (y_degree_ == m.y_degree_)
               && "Undefined operation+ with Monomes of different degrees");
        Monome m_temp{m};
        m_temp.coeff_ = coeff_ + m.coeff_;
        return m_temp;
    }

    Monome Monome::operator-() const {
        Monome m_temp{*this};
        m_temp.coeff_ = -coeff_;
        return m_temp;
    }

    Monome Monome::operator-(const Monome& m){
        return *this+(-m);
    }

    Monome Monome::operator*(const Monome& m){
        Monome m_temp{m};
        m_temp.x_degree_ = x_degree_ + m.x_degree_;
        m_temp.y_degree_ = y_degree_ + m.y_degree_;
        m_temp.coeff_ = coeff_ * m.coeff_;
        return m_temp;
    }

    Monome Monome::operator+=(const Monome& m){
        *this = *this + m;
        return *this;
    }

    Monome Monome::operator-=(const Monome& m){
        *this = *this - m;
        return *this;
    }

    Monome Monome::operator*=(const Monome& m){
        *this = *this * m;
        return *this;
    }

}