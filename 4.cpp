#include <iostream>
#include <cstdlib>
#include <ctime>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    const int size = 10000;
    int arr[size];

    srand(time(0));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }

    bubbleSort(arr, size);

    std::cout << "Array after sorting: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
