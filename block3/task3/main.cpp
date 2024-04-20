#include <iostream>
#include <map>

struct block {
    int32_t start;
    int32_t end;
};

int main(int argc, char** argv) {
    using namespace std;
    // n - количество ячеек памяти, m - количество запросов
    int32_t n, m;
    cin >> n >> m;
    // map номер -> блок, занятые блоки, отсортированные по номеру
    map<int32_t, block> number_block;
    // multimap размер -> блок, освобождённые блоки, отсортированные по размеру
    multimap<int32_t, block> size_block;
    // map начало -> блок, освобождённые блоки, отсортированные по началу
    map<int32_t, block> start_block;

    int32_t query;
    cin >> query;
    // Заполняем самый первый блок
    if (query > n) {
        cout << -1 << endl;
    } else {
        number_block[1] = { 1, query };
        cout << 1 << endl;
    }

    // Заполняем свободное пространство
    if (query != n) {
        if (query > n) query = 0;
        size_block.insert({n - query, { query + 1, n } });
        start_block[query + 1] = { query + 1, n };
    }

    for (int32_t i = 2; i <= m; i++) {
        cin >> query;
        // Запрос на выделение памяти
        if (query > 0) {
            int32_t block_size = query;
            // Поиск блока из освобождённых, в который можно влезть
            auto it = size_block.lower_bound(block_size);
            if (block_size <= it->first) {
                // Найден блок, который подходит по размеру
                block b = it->second;
                // Удаляем его из освобождённых блоков
                size_block.erase(it->first);
                // Удаляем его также из блоков, отсортированных по началу
                start_block.erase(b.start);
                // Разбиваем блок на две части, если блок больше запрашиваемого размера
                if (b.end - b.start + 1 > block_size) {
                    // Добавляем оставшуюся часть блока в освобождённые блоки
                    size_block.insert({ b.end - b.start + 1 - block_size, { b.start + block_size, b.end } });
                    // Добавляем оставшуюся часть блока в блоки, отсортированные по началу
                    start_block[b.start + block_size] = { b.start + block_size, b.end };
                }
                // Обновляем информацию о выделенном блоке
                number_block[i] = { b.start, b.start + block_size - 1 }; 
                // Выводим номер первой ячейки памяти в выделенном блоке
                cout << b.start << endl;
            } else {
                // Не удалось найти подходящий блок
                cout << -1 << endl;
            }
        }
        // Если запрос на освобождение памяти
        else if (query < 0) {
            int32_t number = -query;
            block b = number_block[number];
            // Убираем блок из занятых
            number_block.erase(number);

            // Находим левый прилегающий блок
            auto it = start_block.lower_bound(b.start);
            if (it != start_block.begin()) {
                it--;
                block left_b = it->second;
                if (left_b.end + 1 == b.start) {
                    // Сливаем блоки
                    b = { left_b.start, b.end };
                    // Удаляем левый блок
                    start_block.erase(left_b.start);
                    size_block.erase(left_b.end - left_b.start + 1);
                }
            }

            // Находим правый прилегающий блок
            it = start_block.upper_bound(b.start);
            if (it != start_block.end()) {
                block right_b = it->second;
                if (b.end + 1 == right_b.start) {
                    // Сливаем блоки
                    b = { b.start, right_b.end };
                    // Удаляем правый блок
                    start_block.erase(right_b.start);
                    size_block.erase(right_b.end - right_b.start + 1);
                }
            }

            // Добавляем в освобождённые, отсортрированные по размеру
            size_block.insert({ b.end - b.start + 1, b });
            // Добавляем в освобождённые, отсортрированные по началу
            start_block[b.start] = b;
        }
    }
    return 0;
}