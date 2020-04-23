#include "../h/SchemeCIR.h"


namespace mathkeklib {

    void SchemeCIR::NextStep() {
        values_new[0] = values_old[0];
        for (int i{1}; i < GetLengthStepsCount(); ++i) {
            values_new[i] = values_old[i] -
                            GetSpeed() * GetTimeStep() / GetLengthStep() * (values_old[i] - values_old[i - 1]);
        }
    }

    void SchemeCIR::Print(std::vector<double> v) {
        for (int step{}; step < GetLengthStepsCount(); ++step) {
            std::cout << '(' << step * GetLengthStep() << ", " << v[step] << "), ";
        }
        std::cout << '\n';
    }

    std::vector<double> SchemeCIR::Init() {
        values_new.resize(GetLengthStepsCount());
        values_old.resize(GetLengthStepsCount());

        double x{};
        for (int i{}; i < GetLengthStepsCount(); ++i) {
            x = GetLengthStep() * i;
            if (x >= 0.2 && x <= 0.4) {
                values_old[i] = 1;
            } else {
                values_old[i] = 0;
            }

            values_new[i] = 0;
        }

        return values_old;
    }

    void SchemeCIR::Calculate() {
        Init();
        for (int step{}; step < GetTimeStepsCount(); ++step) {
            NextStep();
        }
    }


}