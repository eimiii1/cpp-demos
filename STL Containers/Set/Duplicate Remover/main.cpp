#include <iostream>
#include <set>

int main() {
    std::set<int> numbers;
    int MAX_list = 5;

    for (int i = 0; i < MAX_list; i++) {
        std::cout << "Number: ";
        int number;
        std::cin >> number;
        numbers.insert(number);
    }

    int index = 0;
    for (auto it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << " ";
    }
}