#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

// تابع ادغام دو زیرآرایه
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // ایجاد دو آرایه موقت
    std::vector<int> L(n1);
    std::vector<int> R(n2);

    // کپی داده‌ها به آرایه‌های موقت L[] و R[]
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // ادغام دو آرایه موقت به آرایه اصلی
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // کپی عناصر باقی‌مانده L[]
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // کپی عناصر باقی‌مانده R[]
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// تابع اصلی Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // مرتب‌سازی نیمه‌های چپ و راست
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // ادغام نیمه‌ها
        merge(arr, left, mid, right);
    }
}

int main() {
    // مقداردهی تصادفی برای اندازه آرایه بین 10,000 تا 100,000
    std::srand(std::time(0));
    const int SIZE = 10000 + (std::rand() % 90001); // عددی بین 10000 و 100000
    std::vector<int> arr(SIZE);

    // مقداردهی تصادفی به عناصر آرایه
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 1000000; // اعداد تصادفی بین 0 و 999999
    }

    std::cout << "اندازه آرایه: " << SIZE << "\n";
    std::cout << "آرایه قبل از مرتب‌سازی (10 عنصر اول):\n";
    for (int i = 0; i < 10 && i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "آرایه بعد از مرتب‌سازی (10 عنصر اول):\n";
    for (int i = 0; i < 10 && i < SIZE; ++i)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    return 0;
}