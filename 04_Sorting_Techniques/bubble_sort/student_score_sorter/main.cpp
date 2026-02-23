#include <iostream>
#include <vector>
using namespace std;

void ascending(vector<int>& scores);
void descending(vector<int>& scores);
void display(vector<int>& scores);

int main() {
    vector<int> scores;
    cout << "\nStudent Score Sorter\n" << endl;
    int s; bool again = true;
    
    for (int i = 0; again; i++) {
        cout << "Score: ";
        cin >> s;
        scores.push_back(s);

        cout << "\n0 - Repeat\n1 - Result\n" << endl;
        int entry;
        cout << "Entry: ";
        cin >> entry;

        cout << endl;
        if (entry == 0) {
            continue;
        } else if (entry == 1) {
            again = false;
        } else {
            cout << "\nInvalid\n" << std::endl;
            continue;
        }
    }

    display(scores);
    return 0;
}

void display(vector<int>& scores) {
    cout << "Ascending: ";
    ascending(scores);
    cout << endl;
    cout << "Descending: ";
    descending(scores);
    cout << endl;
}

void ascending(vector<int>& scores) {
    for (int i = 0; i < scores.size() - 1; i++) {
        for (int j = 0; j < scores.size() - i - 1; j++) {
            if (scores[j] > scores[j+1]) {
                int temp = scores[j];
                scores[j] = scores[j+1];
                scores[j+1] = temp;
            }
        }
    }
    
    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i] << " ";
    }
}

void descending(vector<int>& scores) {
    for (int i = 0; i < scores.size() - 1; i++) {
        for (int j = 0; j < scores.size() - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int temp = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < scores.size(); i++) {
        cout << scores[i] << " ";
    }
}