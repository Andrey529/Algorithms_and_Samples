#include <iostream>
#include "ComplexNumber.h"

int main() {
    std::cout << "ComplexNumber!" << std::endl;

    ComplexNumber comp1(-2, 1);
    ComplexNumber comp2(1, -1);

    ComplexNumber division = comp1 / comp2;
    std::cout << division;

    return 0;
}