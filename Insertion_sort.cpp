#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

// Insertion sort algorithm for sorting arrays of numbers
template <typename T>
void insertionSort(std::vector<T>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    srand(time(0));

    // Sorting arrays of numbers with sizes 100 to 10000000
    for (int size = 100; size <= 10000000; size *= 10) {
        std::vector<int> numbers;
        for (int i = 0; i < size; ++i) {
            numbers.push_back(rand() % 1000000); // Generate random numbers between 0 and 999999
        }

        clock_t start_time = clock();
        insertionSort(numbers);
        clock_t end_time = clock();

        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        std::cout << "Sorting time for " << size << " numbers: " << elapsed_time << " seconds\n";
    }

    // Sorting arrays of words with sizes 100 to 10000000
    for (int size = 100; size <= 10000000; size *= 10) {
        std::vector<std::string> words;
        for (int i = 0; i < size; ++i) {
            std::string word;
            for (int j = 0; j < rand() % 10 + 1; ++j) { // Generate random words with length between 1 and 10
                word.push_back('a' + rand() % 26); // Generate random lowercase letters
            }
            words.push_back(word);
        }

        clock_t start_time = clock();
        insertionSort(words);
        clock_t end_time = clock();

        double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
        std::cout << "Sorting time for " << size << " words: " << elapsed_time << " seconds\n";
    }

    return 0;
}