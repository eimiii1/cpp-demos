#include <iostream>
#include "../include/operations.hpp"
#include "../include/calculator.hpp"

void Advanced::showOptions() {
    std::cout << "\nAdvanced Operations\n" << std::endl;
    std::string operations[] = {
        "power of N",
        "Square Root",
        "Factorial",
        "Get Sine of n",
        "Get Cosine of n",
        "Get Tangent of n",
        "Get log of n",
        "Get log base 10 of n",
        "Go Back"
    };

    for (int i = 0; i < (sizeof(operations) / sizeof(operations[0])); i++) {
        std::cout << i+1 << ". " << operations[i] << "\n";
    }
}

void Advanced::System() {
    Calculator calc;
    Advanced adv;
    int num;
    double result = 0;
    bool running = true;

    int select_option;

    while (running) {
        adv.showOptions();
        std::cout << "\nSelect operation: ";
        std::cin >> select_option;

        if (select_option == 9) {
            running = false;
            continue;
        }

        #ifdef _WIN32
            system("cls");
        #else  
            system("clear");
        #endif

        std::cout << std::endl;

        switch (select_option) {
            case 1: {
                std::cout << "Enter base number: ";
                double base;
                std::cin >> base;
                std::cout << "Enter exponent number: ";
                double exp;
                std::cin >> exp;

                result = calc.power(base, exp);
            }
            break;
            
            case 2: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.squareRoot(num);
            }
            break;

            case 3: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.factorial(num);
            }
            break;

            case 4: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.sine(num);
            }
            break;

            case 5: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.cosine(num);
            }
            break;

            case 6: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.tangent(num);
            }
            break;

            case 7: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.logN(num);
            }
            break;

            case 8: {
                std::cout << "Enter a number: ";
                std::cin >> num;

                result = calc.log10N(num);
            }
            break;

            default: 
                std::cout << "Invalid option!" << std::endl;
                break;
        }
        
        std::cout << "\nOutput: " << result << std::endl;
    }
}