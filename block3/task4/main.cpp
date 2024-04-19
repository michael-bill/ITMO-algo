#include <iostream>

// Нахождение минимального элемента в окне заданного размером k
int32_t min_in_window(int32_t k, int32_t* arr) {
    int32_t min = arr[0];
    for (int32_t i = 1; i < k; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}

int main(int argc, char** argv) {
    size_t n, k;
    std::cin >> n >> k;
    int32_t arr[k], min, num, last_num;
    // Заполняем первое окно и считаем первый минимум
    std::cin >> min;
    arr[0] = min;
    for (size_t i = 1; i < k; i++) {
        std::cin >> num;
        arr[i] = num;
        if (min > num) min = num;
    }
    std::cout << min << ' ';
    // Двигаемся по последовательности
    for (size_t i = k; i < n; i++) {
        std::cin >> num;
        last_num = arr[i % k];
        arr[i % k] = num;
        // Если новое число меньше минимума в окне, то выводим его
        if (min >= num) min = num;
        // Иначе находим новый минимум
        else if (min == last_num) {
            min = min_in_window(k, arr);
        }
        std::cout << min << ' ';
    }
    return 0;
}
