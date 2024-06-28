#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <ctime>

void heapify(std::vector<std::string>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<std::string>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(0));

    int sizes[] = {100, 1000, 10000, 100000, 1000000, 10000000};

    for (int size : sizes) {
        std::vector<std::string> words;
        for (int j = 0; j < size; ++j) {
            std::string word;
            for (int k = 0; k < rand() % 10 + 1; ++k) {
                word.push_back('a' + rand() % 26);
            }
            words.push_back(word);
        }

        clock_t start_time = clock();
        heapSort(words);
        clock_t end_time = clock();

        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;

        std::cout << "آرایه با " << size << " عنصر در " << elapsed_time << " ثانیه مرتب شد." << std::endl;
    }

    return 0;
}
