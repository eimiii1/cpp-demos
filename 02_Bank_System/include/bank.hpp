#pragma once
#include <iostream>
#include <vector>
#include "account.hpp"

class Bank {
private:
    std::vector<Account> accounts;
    int nextAccountNumber = 1001;

public:
    void createAccount(const std::string& name, double initialDeposit);
    void deposit(int accountNumber, double amount);
    void withdraw(int accountNumber, double amount);
    void displayAccount(int accountNumber);

    // load files
    void loadAccountsfromFile();
};