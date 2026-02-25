#include <iostream>
#include <set>

int main() {
    std::set<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8};

    std::cout << "Enter a number: ";
    int num;
    std::cin >> num;

    auto it = numbers.upper_bound(num);

    if (it != numbers.end()) {
        std::cout << "Next bigger number: " << *it << "\n";
        return 0;
    }   

    std::cout << "\nNo bigger number exists.";
    return 1;
}