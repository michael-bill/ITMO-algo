#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2147483647

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

char get_dur(vector<vector<char>>& field, int32_t n, int32_t m, int32_t x, int32_t y) {
    return in_field(x, y, n, m) ? (field[x][y] == FIELD ? FIELD_DUR : FOREST_DUR) : -1;
}

void calc_dest(vector<vector<char>>& field, vector<vector<int32_t>>& dist, int32_t n, int32_t m, int32_t prev_x, int32_t prev_y, int32_t x, int32_t y, int32_t time, vector<vector<vector<char>>>& dirs, char dir) {
    if (!in_field(x, y, n, m)) return;
    if (field[x][y] != WATER && dist[x][y] > time) {
        dist[x][y] = time;
        dirs[x][y] = dirs[prev_x][prev_y];
        if (dir != '\0') dirs[x][y].push_back(dir);
        calc_dest(field, dist, n, m, x, y, x + 1, y, time + get_dur(field, n, m, x, y), dirs, DOWN);
        calc_dest(field, dist, n, m, x, y, x, y + 1, time + get_dur(field, n, m, x, y), dirs, RIGHT);
        calc_dest(field, dist, n, m, x, y, x, y - 1, time + get_dur(field, n, m, x, y), dirs, LEFT);
        calc_dest(field, dist, n, m, x, y, x - 1, y, time + get_dur(field, n, m, x, y), dirs, UP);
    }
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
    vector<vector<int32_t>> dist(n, vector<int32_t>(m));

    for (int32_t i = 0; i < n; i++) {
        for (int32_t j = 0; j < m; j++) {
            cin >> field[i][j];
            dist[i][j] = INF;
        }
    }

    vector<vector<vector<char>>> directions(n, vector<vector<char>>(m));
    calc_dest(field, dist, n, m, start_x, start_y, start_x, start_y, 0, directions, '\0');
    
    int32_t time = dist[dest_x][dest_y];
    vector<char> path = directions[dest_x][dest_y];
    cout << (time != INF ? time : -1) << endl;
    cout << string(path.begin(), path.end()) << endl;
    return 0;
}
