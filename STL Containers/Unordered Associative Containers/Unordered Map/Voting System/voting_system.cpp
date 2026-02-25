#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

void showMenu();
void candidatesList(std::unordered_map<std::string, int>& candidates);
void castVote(std::unordered_map<std::string, int>& candidates, std::string name);
void showResults(std::unordered_map<std::string, int>& candidates);

int main() {
    std::unordered_map<std::string, int> candidates {
        {"Louie", 0},
        {"Jewel", 0},
        {"Jeanclaude", 0},
    };

    int choice = 0;

    while (choice != 3) {
        showMenu();
        std::cout << "\nSelect option: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                candidatesList(candidates);
                std::cout << "\nEnter candidate name: ";
                std::string candidate;
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, candidate);
                
                if (candidate == "END") break;

                castVote(candidates, candidate);
            }
            break;

            case 2: showResults(candidates); break;
            case 3: break;
            default: std::cout << "\nInvalid input.\n";
        }
    }
    std::cout << "\nVoting System exit.\n";
}

void showMenu() {
    std::cout << "\n1. Cast a vote\n2. Show results\n3. Exit\n" << std::endl;
}

void candidatesList(std::unordered_map<std::string, int>& candidates) {
    std::cout << "\n";

    int numbering = 0;
    for (auto it = candidates.begin(); it != candidates.end(); it++, numbering++) {
        std::cout << numbering+1 << ". " << it->first << "\n";
    }
}

void castVote(std::unordered_map<std::string, int>& candidates, std::string name) {
    if (candidates.find(name) != candidates.end()) {
        candidates[name]++;
        return;
    }
    
    std::cout << "Candidate is not on the list.\n";
}

void showResults(std::unordered_map<std::string, int>& candidates) {
    bool noVotes = true;
    for (const auto& [name, count] : candidates) {
        if (count > 0) {
            noVotes = false;
        }
    }
    
    if (noVotes) {
        std::cout << "\nNo votes.\n";
        return;
    }
    
    int maxVotes = 0;
    for (const auto& [name, count] : candidates) {
        if (count > maxVotes) {
            maxVotes = count;
        }
    }

    std::vector<std::string> winners;
    for (const auto& [name, count] : candidates) {
        if (count == maxVotes) {
            winners.push_back(name);
        }
    }
    
    std::sort(winners.begin(), winners.end());
    
    std::cout << "\nWinners: \n";
    for (const auto& winner : winners) {
        std::cout << winner << "\n";
    }
}