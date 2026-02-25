#pragma once
#include <iostream>
#include <vector>
#include <string>

class Student {
private:
    int id;
    std::string studentName;
    std::vector<double> grades;

public:
    Student(int id, const std::string& name, const std::vector<double>& grades) 
        : id(id), studentName(name), grades(grades) {}

    // Getters
    int getID() const { return id; }
    std::string getName() const { return studentName; }
    std::vector<double> getGrades() const { return grades; }

    double calculateAverage() const {
        if (grades.empty()) return 0.0;
        double sum = 0.0;
        for (double g : grades) sum += g;
        return sum / grades.size();
    }
};