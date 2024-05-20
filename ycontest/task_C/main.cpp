#include <iostream>
#include <stack>
#include <unordered_map>

bool is_number(std::string s);

int main(int argc, char** argv) {
    using namespace std;
    // Стек для хранения значений переменных в текущем блоке
    unordered_map< string, stack<string> > variable_stack;
    // Счётчик присваиваний на каждом слое
    stack<int32_t> values_counter_by_layer;
    // Имена переменных, присвоенных на каждом слое
    stack<string> variables_names_by_layer;

    // Начальный блок
    values_counter_by_layer.push(0);

    string line;
    while (getline(cin, line)) {
        // Начало нового блока
        if (line == "{") {
            values_counter_by_layer.push(0);
        // Конец блока
        } else if (line == "}") {
            int32_t values_counter = values_counter_by_layer.top();
            values_counter_by_layer.pop();
            // Очистка стека после завершения блока
            for (int32_t i = 0; i < values_counter; i++) {
                variable_stack[variables_names_by_layer.top()].pop();
                variables_names_by_layer.pop();
            }
        } else {
            // Новое присваивание значения
            values_counter_by_layer.top()++;
            size_t pos = line.find('=');
            string variable = line.substr(0, pos);
            // Новая переменная
            variables_names_by_layer.push(variable);
            string value = line.substr(pos + 1);
            if (is_number(value)) {
                variable_stack[variable].push(value);
            } else {
                // Получение значения
                string out_value = variable_stack[value].empty() ? "0" : variable_stack[value].top();
                // Запись значенияs
                cout << out_value << endl;
                variable_stack[variable].push(out_value);
            }
        }
    }
    return 0;
}

// Проверка на число
bool is_number(std::string s) {
    return isdigit(s[0]) || (s[0] == '-' && isdigit(s[1]));
}
