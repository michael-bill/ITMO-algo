#include <iostream>

// Функция проверки массива на равенство элементов
bool is_equal(int32_t* nums, size_t size) {
    for (size_t i = 0; i < size; i++) {
        if (nums[0] != nums[i]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char** argv) {
    using namespace std;
    // Ввод данных
    size_t n;
    cin >> n;
    int32_t* row = new int32_t[n];
    for (size_t i = 0; i < n; i++) {
        cin >> row[i];
    }
    // Сколько цветков может стоять подряд
    const int32_t offset = 2;
    // Частный случай
    if (n <= offset) {
        cout << 1 << ' ' << n;
        return 0;
    }
    // Общий случай
    int32_t counter = offset, pos = 0, res_counter = offset, res_pos = 0;
    for (size_t i = offset; i < n; i++) {
        if (is_equal(&row[i - offset], offset + 1)) {
            counter = offset;
            pos = i - (offset - 1);
        } else {
            counter++;
        }
        if (res_counter < counter) {
            res_counter = counter;
            res_pos = pos;
        }
    }
    cout << (res_pos + 1) << ' ' << (res_pos + res_counter) << endl;
    delete[] row;
    return 0;
}