#include <iostream>
using namespace std;

int main() {
    int nums[6];

    for (int i = 0; i < 6; i++) {
        cout << "Number: ";
        cin >> nums[i]; 
    }
    
    // sort (ascending)
    for (int i = 0; i < 6 - 1; i++) {
        for (int j = 0; j < 6 - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    
    cout << endl;

    // print numbers
    for (int i = 0; i < 6; i++) {
        cout << nums[i];
        if (i < 6 - 1) {
            cout << ", ";
        }
    }
    
    // largest numbers
    cout << "\n\n3 Largest numbers: ";
    for (int i = 6 - 3; i < 6; i++) {
        cout << nums[i];
        if (i < 6 - 1) {
            cout << ", ";
        }
    }
    
    // smallest numbers
    cout << "\n3 Smallest numbers: ";
    for (int i = 0; i < 6 - 3; i++) {
        cout << nums[i];
        if (i < 3 - 1) {
            cout << ", ";
        }
    }
}