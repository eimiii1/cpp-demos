#include <iostream>
#include <set>

int main() {
    std::set<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << "Input a number: ";
    int num;
    std::cin >> num;

    if (numbers.find(num) == numbers.end()) {
        std::cout << "\nNot Found.\n";
        return 1;
    }
    
    std::cout << "\nFound.\n";
    return 0;
}