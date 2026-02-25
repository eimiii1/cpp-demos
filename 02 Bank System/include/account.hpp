#pragma once 
#include <iostream>
#include <cstdint>

class Account {
private:
    int accountNumber;
    std::string name;
    double balance;

public:
    Account(int number, std::string name, double balance);
    
    // Getters
    int getAccountNumber() const;
    std::string getName() const;
    double getBalance() const;

    void deposit(double amount);
    bool withdraw(double amount);
};