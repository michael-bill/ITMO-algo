#include <iostream>

bool canPlace(int32_t* coords, int32_t n, int32_t k, int32_t dist);

int main(int argc, char** argv) {
    // Количество стойл
    int32_t n;
    // Количество коров
    int32_t k;
    // n координат стойл
    int32_t* coords = new int32_t[n];

    std::cin >> n >> k;
    for (int32_t i = 0; i < n; i++) {
        std::cin >> coords[i];
    }

    int32_t left = 0;
    int32_t right = coords[n - 1] - coords[0];
    int32_t result = -1;

    // Бинарный поиск максимального минимального расстрояния
    while (left <= right) {
        int32_t mid = left + (right - left) / 2;
        if (canPlace(coords, n, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    std::cout << result << std::endl;

    delete[] coords;
    return 0;
}

// Можно ли разместить коров при такой минимальной дистанции
bool canPlace(int32_t* coords, int32_t n, int32_t k, int32_t dist) {
    int32_t last_cord = coords[0];
    int32_t placed = 1;
    for (int32_t i = 0; i < n; i++) {
        if (coords[i] - last_cord >= dist) {
            placed++;
            if (placed == k) {
                return true;
            }
            last_cord = coords[i];
        }
    }
    return false;
}
