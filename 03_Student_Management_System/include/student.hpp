#pragma once
#include <iostream>
#include <cstdint>
#include <vector>

class Student {
private:
    int8_t id;
    std::string studentName;
    std::vector<double> grades;
    double average;

public:
    Student(std::string name, std::vector<double> grades);
    
    // getters
    int8_t getID() const{return id;}
    std::string getName() const {return studentName;}
    std::vector<double> getGrades() const {return grades;}
    double getAverage() const {return average;};
    
    // setters
    void setAverage(std::vector<double>& grades) {
        double sum = 0;

        int length = sizeof(grades) / sizeof(grades[0]);
        for (int i = 0; i < length; i++) {
            sum+=grades[i];    
        }

        average = sum / length;
    }
};