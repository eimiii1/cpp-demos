#include <iostream>
#include "../../include/account.hpp"

Account::Account(int number, std::string name, double balance)
    : accountNumber(number), name(name), balance(balance) {}

// Getters
int Account::getAccountNumber() const {return accountNumber;}
std::string Account::getName() const {return name;}
double Account::getBalance() const {return balance;}

// Functions
void Account::deposit(double amount) {balance+=amount;}
bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -=amount;
        return true;
    }
    return false;
}