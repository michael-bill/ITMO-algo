#include <iostream>
#include <list>

// Основные операции
#define OP_DELETE '-'
#define OP_ADD '+'
#define OP_ADD_CENTER '*'

class GoblinsQueue {
private:
    std::list<int32_t> first_half;
    std::list<int32_t> second_half;

    void queue_alignment() {
        if (first_half.size() < second_half.size()) {
            first_half.push_back(second_half.front());
            second_half.pop_front();
        } else if (first_half.size() > second_half.size()) {
            second_half.push_front(first_half.back());
            first_half.pop_back();
        }
    }
public:
    GoblinsQueue() = default;

    void push_back(int32_t goblin_number) {
        second_half.push_back(goblin_number);
        queue_alignment();
    }

    void push_center(int32_t goblin_number) {
        first_half.push_back(goblin_number);
        queue_alignment();
    }

    int32_t pop_front() {
        int32_t value = first_half.front();
        first_half.pop_front();
        queue_alignment();
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
            goblins_queue.push_center(goblin_number);
        } else if (operation == OP_DELETE) {
            // Вывод номера гоблина, что ушёл к шаману с начала очереди
            cout << goblins_queue.pop_front() << endl;
        }
    }
    return 0;
}
