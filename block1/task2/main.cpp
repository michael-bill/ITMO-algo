#include <iostream>
#include <stack>

// Либо животное, либо ловушка
// type - код символа
// number - порядковый номер в строке
struct zoo_object {
    int32_t type;
    size_t number;
};

int main(int argc, char** argv) {
    using namespace std;
    string line;
    cin >> line;
    // Стек для ловушек и животных
    stack<zoo_object> zoo_objects;
    // Счётчики животных и ловушек
    size_t animals_counter = -1, traps_counter = -1;
    // Массив-результат
    size_t* trapped_animals = new size_t[line.size() / 2];
    for (size_t i  = 0; i < line.size(); i++) {
        int32_t s = line[i];
        // В случае, если животное
        if (islower(s)) {
            animals_counter++;
            int32_t trap = toupper(s);
            if (!zoo_objects.empty() && zoo_objects.top().type == trap) {
                trapped_animals[zoo_objects.top().number] = animals_counter;
                zoo_objects.pop();
            } else {
                zoo_object a = { .type = s, .number = animals_counter };
                zoo_objects.push(a);
            }
        // В случае, если ловушка
        } else if (isupper(s)) {
            traps_counter++;
            int32_t animal = tolower(s);
            if (!zoo_objects.empty() && zoo_objects.top().type == animal) {
                trapped_animals[traps_counter] = zoo_objects.top().number;
                zoo_objects.pop();
            } else {
                zoo_object t = { .type = s, .number = traps_counter };
                zoo_objects.push(t);
            }
        }
    }
    // Все попались
    if (zoo_objects.empty()) {
        cout << "Possible" << endl;
        size_t n = line.size() / 2;
        for (size_t i = 0; i < n; i++) {
            cout << trapped_animals[i] + 1;
            if (i != n - 1) cout << ' ';
            else cout << endl; 
        }
    } else {
        cout << "Impossible" << endl;
    }
    delete[] trapped_animals;
    return 0;
}