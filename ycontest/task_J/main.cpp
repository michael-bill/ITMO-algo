#include <iostream>
#include <list>

// Основные операции
#define OP_DELETE '-'
#define OP_ADD '+'
#define OP_ADD_CENTER '*'

// Очередь с гоблинами из двух половин (для достияжения O(1) при добавлении в середину)
// Реализованы 3 основные операции
// push_back - добавление гоблина в конец очереди
// push_center - добавление привелигированного гоблина в середину очереди
// pop_front - удаление гоблина из начала очереди
class GoblinsQueue {
private:
    // Первая половина очереди
    std::list<int32_t> first_half;
    // Вторая половина очереди
    std::list<int32_t> second_half;
public:
    GoblinsQueue() = default;

    void push_back(int32_t goblin_number) {
        second_half.push_back(goblin_number);
        if (second_half.size() > first_half.size()) {
            first_half.push_back(second_half.front());
            second_half.pop_front();
        }
    }

    void push_center(int32_t goblin_number) {
        first_half.push_back(goblin_number);
        if (first_half.size() - 1 > second_half.size()) {
            second_half.push_front(first_half.back());
            first_half.pop_back();
        }
    }

    int32_t pop_front() {
        int32_t value = first_half.front();
        first_half.pop_front();
        if (second_half.size() > first_half.size()) {
            first_half.push_back(second_half.front());
            second_half.pop_front();
        }
        return value;
    }
};

int main(int argc, char** argv) {
    using namespace std;
    size_t n;
    cin >> n;
    // Очередь с гоблинами
    GoblinsQueue goblins_queue;
    int32_t goblin_number;
    char operation;
    for (size_t i = 0; i < n; i++) {
        cin >> operation;
        if (operation == OP_ADD) {
            // Добавляем обычного гоблина в конец очереди
            cin >> goblin_number;
            goblins_queue.push_back(goblin_number);
        } else if (operation == OP_ADD_CENTER) {
            // Добавляем привелигированного гоблина в середину очереди
            cin >> goblin_number;
            goblins_queue.push_center(goblin_number);
        } else if (operation == OP_DELETE) {
            // Вывод номера гоблина, что ушёл к шаману с начала очереди
            cout << goblins_queue.pop_front() << endl;
        }
    }
    return 0;
}
