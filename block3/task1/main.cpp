#include <iostream>
#include <queue>
#include <unordered_set>

int main() {
    using namespace std;
    int32_t n, k, p;
    cin >> n >> k >> p;

    // Результат - минимальное количество операций
    int32_t res = 0;
    // Очередь запросов на машинки от Пети
    queue<int32_t> requests;
    // Множество машинок на полу
    unordered_set<int32_t> on_floor;
    int32_t car;
    for (int32_t i = 0; i < p; i++) {
        cin >> car;
        requests.push(car);
    }
    while (!requests.empty()) {
        car = requests.front();
        // Если машинка уже не лежит на полу
        if (on_floor.count(car) == 0) {
            if (on_floor.size() < k) {
                // Если на полу меньше K машинок, просто ставим новую
                on_floor.insert(car);
                res++;
            } else {
                // Иначе, убираем одну из имеющихся машинок и ставим новую
                on_floor.erase(on_floor.begin());
                on_floor.insert(car);
                res++;
            }
        }
        requests.pop();
    }
    cout << res << endl;
    return 0;
}
