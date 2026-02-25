#include <iostream>
#include <vector>
#include <string>
#include "../include/school.hpp"

void mainMenu();
int getUserChoice();
void handleChoice(int choice, School& school);

int main() {
    School school;
    school.loadData();

    std::cout << "\nStudent Management System\n";

    int select_option = 0;
    while (select_option != 5) {
        mainMenu();
        select_option = getUserChoice();
        handleChoice(select_option, school);
    }

    return 0;
}

void mainMenu() {
    std::cout << "\nMenu\n";
    const std::vector<std::string> menu = {
        "Add Student",
        "Display Student",
        "Display All Students",
        "Remove Student",
        "Save & Exit"
    };
    for (size_t i = 0; i < menu.size(); ++i) {
        std::cout << i+1 << ". " << menu[i] << "\n";
    }
}

int getUserChoice() {
    std::cout << "\nSelect option: ";
    int choice;
    std::cin >> choice;

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Input should be an integer. Please try again.\n";
        return 0;
    }

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    return choice;
}

void handleChoice(int choice, School& school) {
    std::string name;
    std::vector<double> grades;
    std::vector<std::string> subjects = {
        "Mathematics", "Science", "Filipino", "TLE",
        "Araling panlipunan", "MAPEH", "English"
    };

    switch (choice) {
        case 1: {
            std::cin.ignore(1000, '\n');
            std::cout << "Student name: ";
            std::getline(std::cin, name);

            grades.clear();
            for (const auto& s : subjects) {
                double grade;
                std::cout << s << ": ";
                std::cin >> grade;
                grades.push_back(grade);
            }

            school.addStudent(name, grades);
            break;
        }

        case 2: {
            int id;
            std::cout << "Student ID: ";
            std::cin >> id;
            school.displayStudent(id);
            break;
        }

        case 3: {
            school.displayAll();
            break;
        }

        case 4: {
            int id;
            std::cout << "Student ID to remove: ";
            std::cin >> id;
            school.removeStudent(id);
            break;
        }

        case 5: {
            school.save_exit();
            std::cout << "Exiting program.\n";
            break;
        }

        default:
            std::cout << "Invalid option. Try again.\n";
    }
}