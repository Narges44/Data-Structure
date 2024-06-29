#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

void shellSort(std::vector<int>& arr) {
    int n = arr.size();
    
    // محاسبه دنباله گام
    for (int gap = n/2; gap > 0; gap /= 2) {
        // Insertion Sort برای هر زیرآرایه با فاصله gap
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            
            // انتقال عنصر‌ها به سمت جلو تا جایی که باید
            for (; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // قرار دادن عنصر temp در محل خالی
            arr[j] = temp;
        }
    }
}

int main() {
    const int SIZE = 100000;
    std::vector<int> arr(SIZE);

    // مقداردهی تصادفی به عناصر آرایه
    std::srand(std::time(0));
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 1000000; // اعداد تصادفی بین 0 و 999999
    }

    std::cout << "آرایه قبل از مرتب‌سازی:\n";
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    shellSort(arr);

    std::cout << "آرایه بعد از مرتب‌سازی:\n";
    for (int i = 0; i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}