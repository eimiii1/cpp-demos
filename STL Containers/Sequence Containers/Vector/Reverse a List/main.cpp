#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words;
    std::string word;

    while (true) {
        std::cout << "Enter a word: ";
        std::getline(std::cin, word);

        if (word == "EXIT") break; 

        words.push_back(word);
    }
    
    std::cout << "\n";
    for (int i = words.size() - 1; i >= 0; i--) {
        std::cout << words[i] << " ";
    }
}