#include <iostream>
#include <vector>
#include <fstream>
#include "../../include/bank.hpp"

void Bank::createAccount(const std::string& name, double initialDeposit) {
    Account newAccount(nextAccountNumber, name, initialDeposit);
    accounts.push_back(newAccount);

    std::cout << "\nAccount created! Account Number: " << nextAccountNumber << "\n";
    nextAccountNumber++;
    
    std::ofstream outFile("data/accounts.txt", std::ios::app);
    if (!outFile) {
        std::cout << "Error opening file for writing.\n\n";
        return;
    }

        outFile << newAccount.getAccountNumber() << " " 
                << newAccount.getName() << " "
                << newAccount.getBalance() << "\n";
    
    outFile.close();
    std::cout << "Accounts saved successfully!\n";
}

void Bank::deposit(int accountNumber, double amount) {
    bool found = false;

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            acc.deposit(amount);
            saveAccountsfromFile();
            std::cout << "Deposit successful! New balance: " << acc.getBalance() << "\n";
            found = true;
            break;
        }
    }
    
    if (!found) {
        std::cout << "Account not found!\n";
    }
}

void Bank::withdraw(int accountNumber, double amount) {
    bool found = true;

    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            found = true;
            if (acc.withdraw(amount)) {
                std::cout << "Withdraw successful! New Balance: " << acc.getBalance() << "\n";
                saveAccountsfromFile();
            } else {
                std::cout << "Insufficient balance!\n";
            }
            break;
        }
    }
    
    if (!found) {
        std::cout << "Account not found!\n";
    }
}

void Bank::displayAccount(int accountNumber) {
    bool found = false;
    for (const auto& acc : accounts) {
        if (acc.getAccountNumber() == accountNumber) {
            found = true;
            std::cout << "Account number: " << acc.getAccountNumber() << "\n";
            std::cout << "Name: " << acc.getName() << "\n";
            std::cout << "Balance: " << acc.getBalance() << "\n";
            break;
        }
    }
    
    if (!found) {
        std::cout << "Account not found!\n";
    }
}

void Bank::loadAccountsfromFile() {
    std::ifstream inFile("data/accounts.txt");
    if (!inFile) {
        std::cout << "No accounts file found.\n";
        return;
    }
    
    int accNum;
    std::string name;
    double balance;

    while (inFile >> accNum >> name >> balance) {
        accounts.emplace_back(accNum, name, balance);

        if (accNum >= nextAccountNumber) nextAccountNumber = accNum + 1;
    }
}

void Bank::saveAccountsfromFile() {
    std::ofstream outFile("data/accounts.txt");
    if (!outFile) {
        std::cout << "No accounts file found.\n";
        return;
    }

    for (const auto& acc : accounts) {
        outFile << acc.getAccountNumber() << " "
                << acc.getName() << " "
                << acc.getBalance() << "\n";
    }
    outFile.close();
}