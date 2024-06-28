#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

void selectionSort(std::vector<std::string>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

int main() {
    srand(time(0));

    // Sorting arrays of words with sizes 100 to 10000000
    for (int size = 100; size <= 10000000; size *= 10) {
        std::vector<std::string> arr;
        for (int i = 0; i < size; ++i) {
            std::string word;
            for (int j = 0; j < rand() % 10 + 1; ++j) { // Generate random words with length between 1 and 10
                word.push_back('a' + rand() % 26); // Generate random lowercase letters
            }
            arr.push_back(word);
        }

        clock_t start_time = clock();
        selectionSort(arr);
        clock_t end_time = clock();

        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        std::cout << "Sorting time for " << size << " words: " << elapsed_time << " seconds\n";
    }

    return 0;
}