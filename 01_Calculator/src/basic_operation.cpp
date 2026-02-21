#include <iostream>
#include "../include/operations.hpp"
#include "../include/calculator.hpp"

void Basic::showOptions() {
    std::cout << "\nBasic Operations\n" << std::endl;
    std::string operations[] = {
        "Addition",
        "Subtraction",
        "Multiplication",
        "Division",
        "Go Back"
    };
    
    for (int i = 0; i < (sizeof(operations) / sizeof(operations[0])); i++) {
       std::cout << i+1 << ". " << operations[i] << "\n";
    }
}

void Basic::System() {
    Calculator calc;
    Basic basic;
    double a, b;
    double result = 0;
    bool running = true;

    int select_option;
    
    while (running) {
        basic.showOptions();
        std::cout << "\nSelect operation: ";
        std::cin >> select_option;
        
        if (select_option == 5) {
            running = false;
            continue;
        }

        std::cout << "\nEnter two number (Seperated by spaces): ";
        std::cin >> a >> b;

        switch (select_option) {
            case 1: result = calc.add(a, b); break;
            case 2: result = calc.subtract(a, b); break;
            case 3: result = calc.multiply(a, b); break;
            case 4: result = calc.divide(a, b); break;
            default:
                std::cout << "Invalid option!" << std::endl;
        }

        std::cout << "\nOutput: " << result << std::endl;
    }
}