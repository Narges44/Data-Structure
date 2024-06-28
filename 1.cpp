#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    const int size = 100;
    int arr[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 901 + 100;
    }

    bubbleSort(arr, size);

    cout << "آرایه مرتب شده: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
