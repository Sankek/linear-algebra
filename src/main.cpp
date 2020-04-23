#include <iostream>
#include <vector>

#include "../h/Scheme.h"
#include "../h/SchemeCIR.h"

using namespace mathkeklib;

void PauseBeforeExit(){
    char ans{};
    while(true){
        std::cout << "Exit? Y/N?\n";
        std::cin >> ans;
        if (ans == 'Y'){
            exit(0);
        } else {
            std::cout << "Are you sure? ";
        }
    }
}


int main() {
    using std::cout;

    SchemeCIR CIR(100, 500);
    CIR.SetLimits(1, 3);
    CIR.SetSpeed(1);

    if (CIR.CourantCondition()){
        cout << "Courant condition (c*t/h<1) is satisfied\n";
    } else {
        cout << "Courant condition (c*t/h<1) is not satisfied\n";
    }
    cout << "CIR parameters:\n";
    cout << "c\t=\t" << CIR.GetSpeed() << '\n';
    cout << "t\t=\t" << CIR.GetTimeStep() << '\n';
    cout << "h\t=\t" << CIR.GetLengthStep() << '\n';
    cout << "L\t=\t" << CIR.GetLengthLimit() << '\n';
    cout << "T\t=\t" << CIR.GetTimeLimit() << '\n';
    cout << '\n';

    std::vector<double> Ux_0;
    std::vector<double> Ux_T;

    Ux_0 = CIR.Init();
    cout << "U(x, 0):\n";
    CIR.PrintLast();

    CIR.Calculate();

    Ux_T = CIR.GetValues();
    cout << "U(x, T):\n";
    CIR.PrintNew();

    std::cout << '\n';
    PauseBeforeExit();
    return 0;
}
