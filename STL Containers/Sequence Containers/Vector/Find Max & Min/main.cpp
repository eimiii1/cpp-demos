#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int input = 0;

    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> input;

        if (input == -1) break;
        numbers.push_back(input);
    }
    
    int max = numbers[0], min = numbers[0];
    
    for (int n : numbers) {
        if (n > max) max = n;
        if (n < min) min = n;
    }
    
    std::cout << "\nMax number: " << max << "\n";
    std::cout << "Min number: " << min;
}