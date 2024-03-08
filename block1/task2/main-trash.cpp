/*
    Неверное решение, проходящее не все тесты
    Как оказалось, нужно использовать только один стек...
*/

#include <iostream>
#include <stack>

int32_t to_lower(int32_t s);
int32_t to_upper(int32_t s);
bool is_lower(int32_t s);
bool is_upper(int32_t s);

// Животное с видом и номером
struct animal {
    int32_t type;
    size_t number;
};

// Ловушка с видом и номером
struct trap {
    int32_t type;
    size_t number;
};

int main(int argc, char** argv) {
    using namespace std;
    string line;
    cin >> line;
    // Стек ловушек и животных
    stack<trap> traps;
    stack<animal> animals;
    // Счётчики животных и ловушек
    size_t animals_counter = -1, traps_counter = -1;
    size_t* trapped_animals = new size_t[line.size() / 2];
    for (size_t i  = 0; i < line.size(); i++) {
        int32_t s = line[i];
        // В случае, если животное
        if (is_lower(s)) {
            animals_counter++;
            int32_t t = to_upper(s);
            if (!traps.empty() && traps.top().type == t) {
                trapped_animals[traps.top().number] = animals_counter;
                traps.pop();
            } else {
                animal a = { .type = s, .number = animals_counter };
                animals.push(a);
            }
        // В случае, если ловушка
        } else if (is_upper(s)) {
            traps_counter++;
            int32_t a = to_lower(s);
            if (!animals.empty() && animals.top().type == a) {
                trapped_animals[traps_counter] = animals.top().number;
                animals.pop();
            } else {
                trap t = { .type = s, .number = traps_counter };
                traps.push(t);
            }
        }
    }
    // Все попались
    if (animals.empty() && traps.empty()) {
        cout << "Possible" << endl;
        size_t n = line.size() / 2;
        for (size_t i = 0; i < n; i++) {
            cout << trapped_animals[i] + 1 << ' ';
        }
    } else {
        cout << "Impossible" << endl;
    }
    delete[] trapped_animals;
    return 0;
}

int32_t to_lower(int32_t s) {
    if (s >= 'A' && s <= 'Z') {
        return s - 'A' + 'a';
    }
    return s;
}

int32_t to_upper(int32_t s) {
    if (s >= 'a' && s <= 'z') {
        return s - 'a' + 'A';
    }
    return s;
}

bool is_lower(int32_t s) {
    if (s >= 'a' && s <= 'z') return true;
    return false;
}

bool is_upper(int32_t s) {
    if (s >= 'A' && s <= 'Z') return true;
    return false;
}