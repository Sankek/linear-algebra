#include <fstream>

#include "../h/SchemeCIR.h"


namespace mathkeklib {

    void SchemeCIR::NextStep() {
        std::vector<double> temp = values_;
        values_[0] = 0;
        for (int i{1}; i <= GetLengthStepsCount(); ++i) {
            values_[i] = temp[i] -
                            GetSpeed() * GetTimeStep() / GetLengthStep() * (temp[i] - temp[i - 1]);
        }
        ++CurrentTimeStep();
    }

    void SchemeCIR::ToCSV(std::ofstream& file, const std::vector<double>& values) {
        int steps {GetLengthStepsCount()};
//        for (int step{}; step < steps; ++step){
//            file << step * GetLengthStep() << ',';
//        }
//        file << steps*GetLengthStep() <<'\n';
        for (int step{}; step < steps; ++step){
            file << values[step] << ',';
        }
        file << values[steps] << '\n';
    }

    void SchemeCIR::Print(std::vector<double> v) {
        for (int step{}; step <= GetLengthStepsCount(); ++step) {
            std::cout << '(' << step * GetLengthStep() << ", " << v[step] << "), ";
        }
        std::cout << '\n';
    }

    std::vector<double> SchemeCIR::Init() {
        values_.resize(GetLengthStepsCount() + 1);
        CurrentTimeStep() = 0;

        double x{};
        for (int i{}; i <= GetLengthStepsCount(); ++i) {
            x = GetLengthStep() * i;
            if (x >= 0.2 && x <= 0.4) {
                values_[i] = 1;
            } else {
                values_[i] = 0;
            }
        }

        return values_;
    }

    void SchemeCIR::Calculate() {
        Init();
        for (int step{1}; step <= GetTimeStepsCount(); ++step) {
            NextStep();
        }
    }

    void SchemeCIR::Calculate(std::ofstream& file) {
        Init();

        for (int step{}; step < GetLengthStepsCount(); ++step){
            file << step * GetLengthStep() << ',';
        }
        file << GetLengthStepsCount()*GetLengthStep() <<'\n';

        //        file << 0 << '\n';
        this->ToCSV(file, values_);
        for (int step{1}; step <= GetTimeStepsCount(); ++step) {
            NextStep();
//            file << CurrentTimeStep()*GetTimeStep() << '\n';
            this->ToCSV(file, values_);
        }
    }


}