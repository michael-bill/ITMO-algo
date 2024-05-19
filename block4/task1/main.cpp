#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Максимальное расстояниеы
#define INT32_MAX 2147483647

// Клетки
#define FIELD '.'
#define FOREST 'W'
#define WATER '#'

// Длинна пути
#define FIELD_DUR 1
#define FOREST_DUR 2

// Направления
#define UP 'N'
#define DOWN 'S'
#define LEFT 'W'
#define RIGHT 'E'

// Есть ли x, y на полеы
bool in_field(int32_t x, int32_t y, int32_t n, int32_t m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// Возвращает длинну пути у клетки
int get_dur(char cell) {
    return cell == FIELD ? FIELD_DUR : FOREST_DUR;
}

// Переводит направление в обратное
char reverse_direction(char dir) {
    if (dir == UP) return DOWN;
    if (dir == DOWN) return UP;
    if (dir == LEFT) return RIGHT;
    if (dir == RIGHT) return LEFT;
    return '\0';
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t n, m, start_x, start_y, dest_x, dest_y;
    cin >> n >> m >> start_x >> start_y >> dest_x >> dest_y;

    // Приводим к 0 индексации
    start_x--;
    start_y--;
    dest_x--;
    dest_y--;

    // Игровое поле
    vector<vector<char>> field(n, vector<char>(m));
    // Матрица расстояний
    vector<vector<int32_t>> dist(n, vector<int32_t>(m, INT32_MAX));
    // Матрица направлений
    vector<vector<char>> prev_dir(n, vector<char>(m, '\0'));

    // Ввод поля
    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    // Очередь клеток для обработки
    queue<pair<int32_t, int32_t>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;

    // Измненения направлений
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {UP, DOWN, LEFT, RIGHT};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            // Координатый новой клетки
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Если клетка в пределах поля и это не вода
            if (in_field(nx, ny, n, m) && field[nx][ny] != WATER) {
                // Рассчёт расстояния
                int new_dist = dist[x][y] + get_dur(field[nx][ny]);
                // Если меньше, то запоминаем
                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    prev_dir[nx][ny] = dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    // Время, выводится в результат
    int32_t time = dist[dest_x][dest_y];
    if (time != INT32_MAX) {
        // Реверс пути
        string path = "";
        int x = dest_x;
        int y = dest_y;
        while (x != start_x || y != start_y) {
            char direction = prev_dir[x][y];
            path = direction + path;
            int dx, dy;
            if (direction == UP) { dx = 1; dy = 0; }
            else if (direction == DOWN) { dx = -1; dy = 0; }
            else if (direction == LEFT) { dx = 0; dy = 1; }
            else if (direction == RIGHT) { dx = 0; dy = -1; }
            x += dx;
            y += dy;
        }
        cout << time << endl;
        cout << path << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}
