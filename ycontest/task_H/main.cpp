#include <iostream>
#include <vector>
#include <algorithm>

bool comparator(int32_t a, int32_t b);

int main(int argc, char** argv) {
    using namespace std;
    // Количество товаров
    int32_t n;
    // Параметр акции
    int32_t k;
    cin >> n >> k;
    // Цены на товары
    vector<int32_t> prices(n);
    for (size_t i = 0; i < n; i++) {
        cin >> prices[i];
    }

    // Сортировка
    sort(prices.begin(), prices.end(), comparator);
    
    // Подсчёт суммы со скидкой
    int32_t total = 0;
    for (size_t i = 0; i < n; i++) {
        if ((i + 1) % k != 0) {
            total += prices[i];
        }
    }

    cout << total << endl;
    return 0;
}

// Компаратор для сортировки в обратном порядке
bool comparator(int32_t a, int32_t b) {
    return a > b;
}
