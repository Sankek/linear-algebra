#include <iostream>
#include <string>
#include "../h/Vector.h"
#include "../h/Matrix.h"

int main() {
    std::cout << "--- MATRIX PRESENTATION ---\n";
    Matrix m(2, 3);
    Matrix n(3, 3);

    m.setElement(0,2,3);
    m.setElement(1,1,4);

    n.fill();

    std::cout << "Matrix M:\n";
    m.print();
    std::cout << "---\n" << "Matrix N:\n";
    n.print();
    std::cout << "---\n";
    std::cout << "Matrix product MN:\n";
    m.dot(n).print();

    std::cout << "\n------------------------------------------------------------\n\n";

    std::cout << "--- VECTOR PRESENTATION ---\n";
    std::cout << "Input vectors' size:\n";
    int v_size;
    std::cin >> v_size;
    Vector v1(v_size);
    Vector v2(v_size);

    for (int i{}; i<v_size; ++i){
        v1.setElement(i, i);
        v2.setElement(i, i*i);
    }

    std::cout << "v1:\n";
    v1.print();
    std::cout << "v2:\n";
    v2.print();
    std::cout << "Dot product of v1, v2: " << v1.dot(v2) << '\n';
    std::cout << "Sum of v1, v2: \n";
    v1.sum(v2).print();

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
    return 0;
}
