#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 5, 4, 6, 7, 6, 6, 5, 4};

    for (int i = 0; i < 14; i++) {
        if (arr[i] == 6) {
            arr[i] = 0;
        }
    }
    
    for (int i = 0; i < 14; i++) {
        cout << arr[i] << " ";
    }
}