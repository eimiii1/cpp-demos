#include "../include/Student.h"
#include <iostream>

Student::Student(std::string name, int age, double grade) :
    name(name), age(age), grade(grade) {};

std::string Student::getName() const {return name;}
int Student::getAge() const {return age;}
double Student::getGrade() const {return grade;}

void Student::setName(std::string n) {name = n;}
void Student::setAge(int a) {age = a;}
void Student::setGrade(double g) {grade = g;}

bool Student::isPassed() const {
    return this->grade > 75;
}

void Student::information() const {
    std::cout << "\nStudent Information\n" << std::endl;

    std::cout << "Name: " << this->name << "\n";
    std::cout << "Age: " << this->age << "\n";
    std::cout << "Grade: " << this->grade << "\n";
    std::cout << "Remark: " << (isPassed() ? "\033[32mPASSED\033[0m"
                                           : "\033[31mFAILED\033[0m") << "\n";
}