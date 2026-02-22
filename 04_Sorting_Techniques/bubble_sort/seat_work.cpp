#include <iostream>
using namespace std;

void print(int arr[100], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void sort(int arr[100], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[100];
    int size;

    cout << "Number of elements: ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        cout << "Element value: ";
        cin >> arr[i];
    }

    cout << endl;
    sort(arr, size);
    print(arr, size);
}