#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

class Student {
private:
    std::string name;
    int age;
    double grade;

public:
    Student(std::string name, int age, double grade);

    std::string getName() const;
    int getAge() const;
    double getGrade() const;

    void setName(std::string n);
    void setAge(int a);
    void setGrade(double g);

    bool isPassed() const;
    void information() const;
};

#endif