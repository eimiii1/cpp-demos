#include <iostream>
#include <set>

int main() {
    std::set<int> s = {1, 2, 3, 4, 6, 7, 8};

    std::cout << "Input a number: ";
    int number;
    std::cin >> number;

    auto found = s.find(number);
    if (found == s.end()) {
        std::cout << "\nNumber not found!\n";
    } else {
        std::cout << "\nNumber found!\n";
    }
    
    auto it = s.upper_bound(number);

    if (it != s.end()) {
        std::cout << "\nUpper bound: " << *it;
    } else {
        std::cout << "\nNo upper bound exists\n";
    }
    
    return 0;
}