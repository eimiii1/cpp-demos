#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int score;
};

void showMenu();
void addStudent(Student& s, vector<Student>& students);
void rankings(vector<Student>& students);

// a function that sorts the scoring
void sorting(vector<Student>& students);

int main() {
    cout << "Student Ranking System\n" << std::endl;
    Student s;
    vector<Student> students;
    int choice;

    while (choice != 3) {
        showMenu();
        cout << "Choose option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nStudent name: ";
                cin.ignore(1000, '\n');
                getline(cin, s.name);

                cout << "Score: ";
                cin >> s.score;

                addStudent(s, students);
            }
            break;
            case 2: rankings(students); break;
            case 3:
                cout << "\nSystem exit." << endl;
                exit(0);
            break;
        }

        sorting(students);
    }
}

void showMenu() {
    cout << "\n1. Add student\n2. Display Ranking\n3. Exit\n" << std::endl;
}

void addStudent(Student& s, vector<Student>& students) {
    students.push_back(s);
    cout << "\nStudent Added.\n";
}

void rankings(vector<Student>& students) {
    cout << "\nRankings\n" << endl;
    for (int i = 0; i < students.size(); i++) {
        cout << i+1 << ". " << students[i].name << " - " << students[i].score << "\n";
    }
}

void sorting(vector<Student>& students) {
    for (int i = 0; i < students.size() - 1; i++) {
        for (int j = 0; j < students.size() - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}