#include <iostream>

// Функция одного дня эксперимента
int64_t do_experiment(int64_t a, int64_t b, int64_t c, int64_t d) {
    int64_t bac_counter = a * b - c;
    if (bac_counter <= 0) return 0;
    if (bac_counter > d) return d;
    return bac_counter;
}

int main(int argc, char** argv) {
    using namespace std;
    int64_t a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int64_t res = a, last_res = -1;
    // Прогон k дней эксперимента
    for (int64_t i = 0; i < k && res != 0 && res != last_res; i++) {
        res = do_experiment(last_res = res, b, c, d);
    }
    cout << res << endl;
    return 0;
}