#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
#include "../include/Student.h"

void menu();
bool addStudent(std::vector<Student>& students, std::string name, int age, double grade);
bool updateStudent(std::vector<Student>& students, std::string name, std::string newName, int newAge, double newGrade);
bool deleteStudent(std::vector<Student>& students, std::string name);
void Students(std::vector<Student>& students);
bool searchStudent(std::vector<Student>& students, std::string name);

// handlers
void inputChoice(int& choice);
void handleChoice(int& choice, std::vector<Student>& students);

int main() {
    std::vector<Student> students;

    std::cout << "\nStudent Management System\n" << std::endl;
    int choice = 0;

    
    while (choice != 6) {
        menu();
        inputChoice(choice);
        
        // clear screen
        #ifdef _WIN32
            system("cls");
        #else 
            system("clear");
        #endif

        handleChoice(choice, students);
    }
    
    std::cout << "\nExit.\n";
}

void menu() {
    std::cout << "\nMENU\n" << std::endl;
    std::vector<std::string> menu = {
        "Add a Student",
        "Update Student Information",
        "Delete a student",
        "List all students",
        "Search a student",
        "Exit"
    };

    for (int i = 0; i < menu.size(); i++) {
        std::cout << i+1 << ". " << menu[i] << "\n";
    }
}

void inputChoice(int& choice) {
    std::cout << "\nChoice: ";
    std::cin >> choice;
}

void handleChoice(int& choice, std::vector<Student>& students) {
    std::string name;
    int age;
    double grade;
    
    switch (choice) {
        case 1: {
            if (students.empty()) {
                std::cout << "\n\033[31mStudent list is empty.\033[0m\n";
                return;   
            }

            std::cout << "\nAdd a student \n" << std::endl;
            std::cout << "Name: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, name);
            
            std::cout << "Age: ";
            std::cin >> age;

            std::cout << "Grade: ";
            std::cin >> grade;
            if (addStudent(students, name, age, grade)) {
                std::cout << "\nStudent succesfully added.\n";
            } else {
                std::cout << "\nA student with this name already exists\n";
            }
        }
        break;
        
        case 2: {
            if (students.empty()) {
                std::cout << "\n\033[31mStudent list is empty.\033[0m\n";
                return;   
            }

            std::cout << "\nUpdate student information\n" << std::endl;
            std::cout << "Name: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, name);

            std::string newName;
            int newAge;
            double newGrade;

            std::cout << "\nNew Student Information: \n";
            std::cout << "New name: ";
            std::getline(std::cin, newName);

            std::cout << "New age: ";
            std::cin >> newAge;

            std::cout << "New Grade: ";
            std::cin >> newGrade;

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
            if (updateStudent(students, name, newName, newAge, newGrade)) {
                std::cout << "\nStudent Information successfully updated.\n";
            } else {
                std::cout << "\nStudent name doesn't exist.\n";
            }
        }
        break;

        case 3: {
            if (students.empty()) {
                std::cout << "\n\033[31mStudent list is empty.\033[0m\n";
                return;   
            }
            
            std::cout << "\nDelete a student\n" << std::endl;
            std::cout << "Name: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, name);

            if (deleteStudent(students, name)) {
                std::cout << "\nStudent successfully deleted\n";
            } else {
                std::cout << "\nStudent name doesn't exist.\n";
            }
        }
        break;
        
        case 4: {
            Students(students);
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nPress Enter to continue...";
            std::cin.get();
        }
        break;
        
        case 5: {
            if (students.empty()) {
                std::cout << "\n\033[31mStudent list is empty.\033[0m\n";
                return;   
            }

            std::cout << "\nSearch Student\n" << std::endl;
            std::cout << "Name: ";
            std::cin.ignore(1000, '\n');
            std::getline(std::cin, name);

            if (searchStudent(students, name)) {
                std::cout << "\nStudent found!\n";
            } else {
                std::cout << "\nStudent name doesn't exist.\n";
            }
        }
    }
}

bool addStudent(std::vector<Student>& students, std::string name, int age, double grade) {
    for (const auto& s : students) {
        if (s.getName() == name) {
            std::cout << "\nCannot add the same name.\n";
            return false;
        }
    }
    Student s(name, age, grade);
    students.push_back(s);
    return true;
}

bool updateStudent(std::vector<Student>& students, std::string name, std::string newName, int newAge, double newGrade) {
    for (auto& s : students) {
        if (s.getName() == name) {
            s.setName(newName);
            s.setAge(newAge);
            s.setGrade(newGrade);
            return true;
            break;
        }
    }
    return false;
}

bool deleteStudent(std::vector<Student>& students, std::string name) {
    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->getName() == name) {
            students.erase(it);
            std::cout << "\nStudent Deleted.\n";
            return true;
            break;
        }
    }
    return false;
}

void Students(std::vector<Student>& students) {
    const int nameWidth = 25;
    const int ageWidth = 10;
    const int gradeWidth = 10;
    const int remarkWidth = 10;

    std::cout << std::left
              << "\033[32m" << std::setw(nameWidth) << "Name" << "\033[0m"
              << "\033[33m" << std::setw(ageWidth) << "Age" << "\033[0m"
              << "\033[34m" << std::setw(gradeWidth) << "Grade" << "\033[0m"
              << "\033[35m" << std::setw(remarkWidth) << "Remarks" << "\033[0m"
              << "\n";
    
    // separator
    std::cout << std::string(nameWidth + ageWidth + gradeWidth + remarkWidth, '-') << "\n";
              
    for (const auto& s : students) {
        std::cout << std::left
                  << std::setw(nameWidth)    << s.getName()
                  << std::setw(ageWidth)     << s.getAge()
                  << std::setw(gradeWidth)   << s.getGrade()
                  << std::setw(remarkWidth)  << (s.isPassed() ? "\033[32mPASSED\033[0m"
                                                              : "\033[31mFAILED\033[0m")
                  << "\n";
    }
}

bool searchStudent(std::vector<Student>& students, std::string name) {
    for (const auto& s : students) {
        if (s.getName() == name) {
            s.information();
            return true;
            break;
        }
    }
    return false;
}