#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include "student.hpp"

class School {
private:
    std::vector<Student> students;
    int nextId = 1001;

public:
    // Add a student
    void addStudent(const std::string& name, const std::vector<double>& grades) {
        Student student(nextId, name, grades);
        students.push_back(student);
        std::cout << "\nStudent added successfully.\n";
        nextId++;
    }

    // Display a student by ID
    void displayStudent(int id) const {
        bool found = false;
        for (const auto& s : students) {
            if (s.getID() == id) {
                found = true;
                std::cout << "\nID: " << s.getID() << "\n";
                std::cout << "Name: " << s.getName() << "\n";

                std::vector<std::string> subjects = {
                    "Mathematics", "Science", "Filipino", "TLE",
                    "Araling panlipunan", "MAPEH", "English"
                };

                const auto& grades = s.getGrades();
                for (size_t i = 0; i < subjects.size() && i < grades.size(); ++i) {
                    std::cout << subjects[i] << ": " << grades[i] << "\n";
                }

                std::cout << "Average: " << std::fixed << std::setprecision(2) 
                          << s.calculateAverage() << "\n";
            }
        }

        if (!found) {
            std::cout << "Couldn't find student ID.\n";
        }
    }

    // Display all students
    void displayAll() const {
        for (const auto& s : students) {
            displayStudent(s.getID());
        }
    }

    // Load students from file
    void loadData() {
        std::ifstream inFile("data/students.txt");
        if (!inFile) {
            std::cout << "There was an error reading your file.\n";
            return;
        }

        std::string line;
        while (std::getline(inFile, line)) {
            std::istringstream iss(line);
            std::string idStr, name, gradesStr;

            if (std::getline(iss, idStr, '|') &&
                std::getline(iss, name, '|') &&
                std::getline(iss, gradesStr)) {

                int id = std::stoi(idStr);

                // Trim whitespace
                name.erase(0, name.find_first_not_of(" \t"));
                name.erase(name.find_last_not_of(" \t") + 1);

                std::vector<double> grades;
                std::istringstream gss(gradesStr);
                std::string g;
                while (std::getline(gss, g, ',')) {
                    g.erase(0, g.find_first_not_of(" \t"));
                    g.erase(g.find_last_not_of(" \t") + 1);
                    if (!g.empty()) grades.push_back(std::stod(g));
                }

                students.push_back(Student(id, name, grades));
                if (id >= nextId) nextId = id + 1;
            }
        }

        inFile.close();
    }

    // Save students to file
    void save_exit() const {
        std::ofstream outFile("data/students.txt");
        if (!outFile) {
            std::cout << "There was an error saving your file.\n";
            return;
        }

        for (const auto& s : students) {
            const auto& grades = s.getGrades();
            outFile << s.getID() << " | " << s.getName() << " | ";
            for (size_t i = 0; i < grades.size(); ++i) {
                outFile << grades[i];
                if (i < grades.size() - 1) outFile << ", ";
            }
            outFile << "\n";
        }
        std::cout << "Data saved successfully.\n";
    }

    // Remove a student by ID
    void removeStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getID() == id) {
                students.erase(it);
                std::cout << "Student removed successfully.\n";
                return;
            }
        }
        std::cout << "Student ID not found.\n";
    }
};