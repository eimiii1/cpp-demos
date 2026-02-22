#include <iostream>
using namespace std;

void output(int data[], int size) {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
}

void sort(int data[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
    output(data, size);
}

int main() {
    int data[] = {-2, 45, 0, 11, -9};
    int size = 5;
    sort(data, size);
}