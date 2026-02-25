#include <iostream>
#include <map>
#include <string>

void show_menu();

// functions
void addUpdateStudent(std::map<std::string, int>& students, std::string name, int grade);
void searchStudent(std::map<std::string, int>& students, std::string name);
void removeStudent(std::map<std::string, int>& students, std::string name);
void printAllStudents(std::map<std::string, int>& students);

int main() {
    std::map<std::string, int> students;
    int select_option = 0;

    while (select_option != 5) {
        show_menu();
        std::cout << "\nSelect option: ";
        std::cin >> select_option;

        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif

        // input variable initializations
        std::string student;
        int grade;

        switch (select_option) {
            case 1: {
                std::cout << "\nName: ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, student);

                std::cout << "Grade: ";
                std::cin >> grade;

                // add student (update if exists)
                addUpdateStudent(students, student, grade);
            }
            break;
            case 2: {
                if (students.empty()) {
                    std::cout << "\nStudents list is empty.\n";
                    break;
                }

                std::cout << "\nName: ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, student);
                
                // search student
                searchStudent(students, student);
            }
            break;
            case 3: {
                if (students.empty()) {
                    std::cout << "\nStudents list is empty.\n";
                    break;
                }

                std::cout << "\nName: ";
                std::cin.ignore(1000, '\n');
                std::getline(std::cin, student);

                // erase student
                removeStudent(students, student);
            } break;
            case 4: printAllStudents(students); break;
            default: 
                std::cout << "\nInvalid input!\n" << std::endl;
        }
    }
    std::cout << "\nSystem exit.\n";
    return 0;
}

void show_menu() {
    std::cout << "\nMenu\n" << std::endl;
    std::cout << "1. Add/Update Student\n2. Search a Student\n3. Remove a Student\n4. Display Students\n5. Exit\n";
}

void addUpdateStudent(std::map<std::string, int>& students, std::string name, int grade) {
    if (students.find(name) == students.end()) { // means that name don't exist.
        std::cout << "\nStudent added.\n";
    } else {
        std::cout << "\nStudent updated.\n";
    }
    students[name] = grade;
}

void searchStudent(std::map<std::string, int>& students, std::string name) {
    auto it = students.find(name);  
    if (it != students.end()) {
        std::cout << "\nStudent found!\n" << std::endl;
        std::cout << it->first << ": " << it->second << "\n";
        return;
    }
    
    std::cout << "\nStudent not found!\n";
}

void removeStudent(std::map<std::string, int>& students, std::string name) {
    auto it = students.find(name);
    if (it != students.end()) {
        students.erase(name);
        std::cout << "\nStudent removed!\n" << std::endl;
        return;
    }
    
    std::cout << "\nStudent not found!\n";
}

void printAllStudents(std::map<std::string, int>& students) {
    if (students.empty()) {
        std::cout << "\nStudents list is empty.\n" << std::endl;
        return;
    }

    std::cout << std::endl;
    for (auto& [student, grade] : students) {
        std::cout << student << ": " << grade << "\n";
    }
}
