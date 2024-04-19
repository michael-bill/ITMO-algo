#include <iostream>
#include <list>

// Основные операции
#define OP_DELETE '-'
#define OP_ADD '+'
#define OP_ADD_CENTER '*'

int main(int argc, char** argv) {
    using namespace std;

    size_t n;
    cin >> n;
    // Очередь с гоблинами
    list<int32_t> goblins_queue;
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
            auto it = goblins_queue.begin();
            advance(it, goblins_queue.size() / 2);
            cin >> goblin_number;
            goblins_queue.insert(it, goblin_number);
        } else if (operation == OP_DELETE) {
            // Вывод номера гоблина, что ушёл к шаману с начала очереди
            cout << goblins_queue.front() << endl;
            goblins_queue.pop_front();
        }
    }
    return 0;
}
