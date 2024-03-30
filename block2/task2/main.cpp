#include <iostream>
#include <vector>
#include <algorithm>

bool comparator(std::string a, std::string b);

int main(int argc, char** argv) {
    using namespace std;
    vector<string> nums;
    string row;
    while (cin >> row) {
        nums.push_back(row);
    }

    // Сортировка, применяя свой компаратор
    sort(nums.begin(), nums.end(), comparator);

    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
    }
    cout << endl;
    return 0;
}

// Функция-компаратор двух строк для верной сортировки
// Сцепляет строки и смотрит, где получилось больше число
bool comparator(std::string a, std::string b) {
    return a + b > b + a;
}
