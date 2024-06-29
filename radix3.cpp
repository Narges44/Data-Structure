#include <iostream>
#include <vector>
#include <ctime>

// تابعی برای یافتن بیشترین عدد در آرایه
int getMax(std::vector<int>& arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

// تابع اجرای Radix Sort برای آرایه‌ای از اعداد صحیح
void radixSort(std::vector<int>& arr) {
    // یافتن بیشترین عدد در آرایه
    int max = getMax(arr, arr.size());

    // اجرای مرتب‌سازی بر اساس رقم‌های مختلف اعداد
    for (int exp = 1; max / exp > 0; exp *= 10) {
        std::vector<int> output(arr.size());
        int count[10] = {0};

        // محاسبه تعداد اعداد با توجه به رقم exp
        for (int i = 0; i < arr.size(); ++i)
            count[(arr[i] / exp) % 10]++;

        // محاسبه موقعیت واقعی اعداد در آرایه خروجی
        for (int i = 1; i < 10; ++i)
            count[i] += count[i - 1];

        // ایجاد آرایه خروجی مرتب شده
        for (int i = arr.size() - 1; i >= 0; --i) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // کپی کردن آرایه خروجی به آرایه اصلی
        for (int i = 0; i < arr.size(); ++i)
            arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr;
    std::srand(std::time(0));
    int size = 1000000 + std::rand() % 9000001;  // حجمی بین 1000000 و 10000000

    // تولید اعداد تصادفی برای آرایه
    for (int i = 0; i < size; ++i) {
        arr.push_back(std::rand() % 10000000);  // اعداد تصادفی بین 0 تا 9999999
    }

    // چاپ آرایه قبل از مرتب‌سازی
    std::cout << "آرایه قبل از مرتب‌سازی:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        // برای جلوگیری از چاپ طولانی، هر 100 عدد را چاپ می‌کنیم
        if ((i + 1) % 100 == 0)
            std::cout << std::endl;
    }
    std::cout << "\n";

    // اجرای Radix Sort بر روی آرایه
    radixSort(arr);

    // چاپ آرایه بعد از مرتب‌سازی
    std::cout << "آرایه بعد از مرتب‌سازی:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
        // برای جلوگیری از چاپ طولانی، هر 100 عدد را چاپ می‌کنیم
        if ((i + 1) % 100 == 0)
            std::cout << std::endl;
    }
    std::cout << "\n";

    return 0;
}