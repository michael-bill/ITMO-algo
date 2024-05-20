#include <iostream>
#include <deque>

int main() {
    using namespace std;
    int32_t n, k;
    cin >> n >> k;
    int32_t arr[n];
    for (int32_t i = 0; i < n; i++) {
        cin >> arr[i];
    }
    deque<int32_t> nums;
    // Заполняем deque для первого окна длины k
    for (int32_t i = 0; i < k; i++) {
        while (!nums.empty() && arr[i] <= arr[nums.back()]) {
            nums.pop_back();
        }
        nums.push_back(i);
    }
    // Печатаем минимумы и обновляем deque при сдвиге окна
    for (int32_t i = k; i < n; i++) {
        cout << arr[nums.front()] << ' ';
        // Удаляем индексы элементов, которые больше не в окне
        while (!nums.empty() && nums.front() <= i - k) {
            nums.pop_front();
        }
        // Удаляем индексы элементов, которые больше не могут быть минимумами
        while (!nums.empty() && arr[i] <= arr[nums.back()]) {
            nums.pop_back();
        }
        nums.push_back(i);
    }
    cout << arr[nums.front()] << endl;
    return 0;
}
