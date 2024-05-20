#include <iostream>
#include <vector>
#include <set>

#define NOT_SEEN -1

int main() {
    using namespace std;
    int32_t n, k, p, car;
    cin >> n >> k >> p;

    // last_seen[i] хранит индекс последнего появления машинки i+1
    // next_use[i] хранит индекс следующего использования машинки i+1
    vector<int32_t> last_seen(n, NOT_SEEN), next_use(p, p);

    // Считываем последовательность машинок и заполняем next_use
    for (int32_t i = 0; i < p; i++) {
        cin >> car;
        car--;
        if (last_seen[car] != NOT_SEEN)
            next_use[last_seen[car]] = i;
        last_seen[car] = i;
    }

    int32_t res = 0;
    // on_floor - индексы машинок, которые сейчас на полу
    set<int32_t> on_floor;
    for (int32_t i = 0; i < p; i++) {
        if (on_floor.count(i) <= 0) {
            res++;
            if (on_floor.size() == k) {
                auto it = on_floor.end();
                on_floor.erase(prev(it));
            }
            on_floor.insert(next_use[i]);
            continue;
        }
        on_floor.erase(i);
        on_floor.insert(next_use[i]);
    }
    cout << res << endl;
    return 0;
}
