#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INT32_MAX 2147483647

#define FIELD '.'
#define FOREST 'W'
#define WATER '#'

#define FIELD_DUR 1
#define FOREST_DUR 2

#define UP 'N'
#define DOWN 'S'
#define LEFT 'W'
#define RIGHT 'E'

bool in_field(int32_t x, int32_t y, int32_t n, int32_t m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int get_dur(char cell) {
    return cell == FIELD ? FIELD_DUR : FOREST_DUR;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int32_t n, m, start_x, start_y, dest_x, dest_y;
    cin >> n >> m >> start_x >> start_y >> dest_x >> dest_y;
    start_x--;
    start_y--;
    dest_x--;
    dest_y--;

    vector<vector<char>> field(n, vector<char>(m));
    vector<vector<int32_t>> dist(n, vector<int32_t>(m, INT32_MAX));
    vector<vector<string>> directions(n, vector<string>(m, ""));

    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            cin >> field[i][j];
        }
    }

    queue<pair<int32_t, int32_t>> q;
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    char dir[] = {UP, DOWN, LEFT, RIGHT};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (in_field(nx, ny, n, m) && field[nx][ny] != WATER) {
                int new_dist = dist[x][y] + get_dur(field[nx][ny]);
                if (new_dist < dist[nx][ny]) {
                    dist[nx][ny] = new_dist;
                    directions[nx][ny] = directions[x][y] + dir[i];
                    q.push({nx, ny});
                }
            }
        }
    }

    int32_t time = dist[dest_x][dest_y];
    string path = directions[dest_x][dest_y];
    cout << (time != INT32_MAX ? time : -1) << endl;
    cout << path << endl;

    return 0;
}
