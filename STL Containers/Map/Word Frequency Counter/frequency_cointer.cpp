#include <iostream>
#include <map>
#include <string>
#include <sstream>

int main() {
    std::map<std::string, int> frequencies;

    std::cout << "\nEnter text: ";
    std::string line;
    std::getline(std::cin, line);

    std::stringstream ss(line);
    std::string word;

    while (ss >> word) {
        frequencies[word]++;
    }

    std::cout << std::endl;
    for (const auto& [key, value] : frequencies) {
        std::cout << key << ": " << value << "\n";
    }
}