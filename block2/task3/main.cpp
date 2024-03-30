#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define ALPH_LENGTH 26
#define FIRST_LETTER 'a'

bool comparator(char a, char b, int32_t* weights);

int main(int argc, char** argv) {
    using namespace std;
    // Строка
    string s;
    // Веса
    int32_t weights[ALPH_LENGTH];
    // Сколько раз встречалась буква в строке:
    // буква -> количество, последний найденный индекс
    map<char, pair<int32_t, int32_t> > letter_counter;

    cin >> s;
    for (size_t i = 0; i < ALPH_LENGTH; i++) {
        cin >> weights[i];
        // Поначалу ещё ничего не найдено
        letter_counter[FIRST_LETTER + i] = make_pair(0, -1);
    }

    // Строка, что будет стоять вначале и реверсивно в конце
    string start = "";

    for (size_t i = 0; i < s.length(); i++) {
        char c = s[i];
        pair<int32_t, int32_t>* v = &letter_counter[c];
        // Увеличиваем счётчик у той буквы, что нам встретилась
        v->first++;
        int32_t last_index = v->second, cur_index = i;
        // Устанавливаем новый индекс
        v->second = cur_index;
        // Если буква встретилась 2 раза, то берём её в учёт тех, что будут переставлены
        if (v->first == 2) {
            start.push_back(c);
            // Записываем туда нули, чтобы эти символы пропустить при выводе
            s[last_index] = '0';
            s[cur_index] = '0';
        }
    }

    // Сортировка начала строки по весам
    sort(
        start.begin(), start.end(),
        [&](char a, char b) {
            return comparator(a, b, weights);
        }
    );

    // Вывод начала строки
    cout << start;
    // Вывод центра с пропуском тех букв, что были переставлены
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] != '0') cout << s[i];
    }
    // Выврод конца строки (реверc начала)
    for (size_t i = start.length(); i > 0; i--) {
        cout << start[i - 1];
    }
    cout << endl;

    return 0;
}

// Сравнение двух символов по весам
bool comparator(char a, char b, int32_t* weights) {
    return weights[a - FIRST_LETTER] > weights[b - FIRST_LETTER];
}
