#include <iostream>
#include <string>
#include "../include/bank.hpp"

void menu() {
    std::cout << "\nMenu\n" << std::endl;
    std::string menu[] = {
        "Create account",
        "Deposit",
        "Withdraw",
        "Display account",
        "Exit"
    };

    int length = sizeof(menu) / sizeof(menu[0]);
    for (int i = 0; i < length; i++) {
        std::cout << i+1 << ". " << menu[i] << "\n";
    }
}

int main() {
    Bank bank;
    bank.loadAccountsfromFile();

    std::cout << "\nATM\n" << std::endl;
    int select_option;
    bool running = true;

    while (running) {
        menu();
        std::cout << "\nSelect option: ";
        std::cin >> select_option;

        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif
            
        if (select_option == 5) {
            running = false;
            continue;
        }
            
        switch (select_option) {
            case 1: {
                std::cout << "Set name: ";
                std::string getName;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, getName);

                std::cout << "Set Initial Deposit: ";
                double initialDeposit;
                std::cin >> initialDeposit;

                bank.createAccount(getName, initialDeposit);
            }
            break;

            case 2: {
                std::cout << "Account number: ";
                int inputNumber;
                std::cin >> inputNumber;

                std::cout << "Amount: ";
                int getAmount;
                std::cin >> getAmount;

                bank.deposit(inputNumber, getAmount);
            }
            break;

            case 3: {
                std::cout << "Account number: ";
                int inputNumber;
                std::cin >> inputNumber;

                std::cout << "Amount: ";
                int getAmount;
                std::cin >> getAmount;

                bank.withdraw(inputNumber, getAmount);
            }
            break;

            case 4: {
                std::cout << "Account number: ";
                int inputNumber;
                std::cin >> inputNumber;

                bank.displayAccount(inputNumber);
            }
            break;
            default: std::cout << "Invalid option!\n" << std::endl;
        }
    }
    std::cout << "Exit System." << std::endl;
}