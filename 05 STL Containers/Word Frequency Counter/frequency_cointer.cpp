#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::map<std::string, int> frequencies;
    std::string line;

    std::cout << "\nEnter text: ";
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::string word;

    while (ss >> word) {
            frequencies[word]++;
    }

    for (const auto& [key, value] : frequencies) {
        std::cout << key << ": " << value << "\n";
    }
}