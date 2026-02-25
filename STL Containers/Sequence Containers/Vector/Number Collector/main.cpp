#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int input = 0;
    int sum = 0;
    double average = 0;

    while (true) {
        std::cout << "Enter number: ";
        std::cin >> input;

        if (input == -1) break;
        numbers.push_back(input);
        
    }
    
    std::cout << "\nNumbers: ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) {
            std::cout << ", ";
        }
    }
}