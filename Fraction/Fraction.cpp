#include "Fraction.h"
#include <iostream>

int main() {
    try {
        Fraction f1(5, 10); 
        Fraction f2(9, 3); 

        std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
        std::cout << "f1 + f2 = " << f1 + f2 << std::endl;
        std::cout << "f1 - f2 = " << f1 - f2 << std::endl;
        std::cout << "f1 * f2 = " << f1 * f2 << std::endl;
        std::cout << "f1 / f2 = " << f1 / f2 << std::endl;
        std::cout << "f1 == f2: " << (f1 == f2 ? "true" : "false") << std::endl;
        std::cout << "f1 != f2: " << (f1 != f2 ? "true" : "false") << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
        return 1; 
    }

    return 0; 
}
