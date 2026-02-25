#include <iostream>
#include <vector>
#include <string>
#include "../include/operations.hpp"

void clear();

int main() {
    Basic basic;
    Advanced adv;

    double a, b;
    int select_option;
    
    while (select_option != 3) {
        std::cout << "\nCalculator\n" << std::endl;
        std::cout << "1. Basic Operations\n2. Advanced Operations\n3. Exit\n";
        std::cout << "\nSelect option: ";
        std::cin >> select_option;

        clear();

        switch (select_option) {
            case 1: basic.System(); break;
            case 2: adv.System(); break;
            case 3:
                std::cout << "System exit.\n" << std::endl;
                std::exit(0); 
                break;
            default:
                std::cout << "Invalid option!\n";
                break;
        }
    }
}
void clear() {
    #ifdef _WIN32
        system("cls");
    #else 
        system("clear");
    #endif
}