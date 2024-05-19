#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define WHITE -1
#define BLACK 0

// Функция для определения, является ли граф двудольным, начиная с заданной вершины
bool is_bipartite(vector<vector<int32_t>>& graph, int32_t start) {
    int32_t n = graph.size();
    vector<int32_t> colors(n, WHITE);
    queue<int32_t> q;

    q.push(start);
    // Помечаем стартовую вершину чёрной
    colors[start] = BLACK;

    while (!q.empty()) {
        int32_t curr = q.front();
        q.pop();

        for (int32_t neighbor : graph[curr]) {
            if (colors[neighbor] == WHITE) { // Если сосед не посещён
                // Красим его в противоположный цвет текущей вершины
                colors[neighbor] = 1 - colors[curr];
                q.push(neighbor);
            } else if (colors[neighbor] == colors[curr]) { // Если сосед имеет тот же цвет, что и текущая вершина
                // Граф не является двудольным
                return false;
            }
        }
    }

    // Если цветовка прошла успешно, граф двудолен
    return true;
}

int main(int argc, char** argv) {
    int32_t n, m;
    cin >> n >> m;

    vector<vector<int32_t>> graph(n);

    // Считываем пары вершин, между которыми есть связи
    for (int32_t i = 0; i < m; i++) {
        int32_t u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Флаг, определяющий, можно ли разделить граф на две группы
    bool can_be_devided = true;
    for (int32_t i = 0; i < n; i++) {
        // Если вершина не изолированная и граф не двудолен
        if (graph[i].size() > 0 && !is_bipartite(graph, i)) {
            can_be_devided = false;
            break;
        }
    }

    // Выводим результат
    cout << (can_be_devided ? "YES" : "NO") << endl;

    return 0;
}
