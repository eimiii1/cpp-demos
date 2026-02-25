#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers;
    int input = 0;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> input;

        if (input == -1) break;
        numbers.push_back(input);
    }

    bool duplicate = false;
    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (numbers[i] == numbers[j]) {
                duplicate = true;
            }
        }
    }
    
    if (duplicate) {
        std::sort(numbers.begin(), numbers.end());
        auto last = unique(numbers.begin(), numbers.end());
        numbers.erase(last, numbers.end());
    }

    std::cout << "Unique numbers: ";
    for (int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1) std::cout << ", ";
    }
}