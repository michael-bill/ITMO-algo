#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define WHITE 0
#define BLACK 1

// Покрас графа, если прошли, то красим в чёрный
void colorize(vector<unordered_set<int32_t>>& graph, vector<int32_t>& colors, int32_t start) {
    colors[start] = BLACK;
    for (int32_t neighbor : graph[start]) {
        if (colors[neighbor] == WHITE) {
            colorize(graph, colors, neighbor);
        }
    }
}

int main(int argc, char** argv) {
    int32_t n;
    cin >> n;
    // Граф с копилками
    vector<unordered_set<int32_t>> graph(n);
    // Цвета вершин графа с копилками
    vector<int32_t> colors(n, WHITE);
    // Ввод данных
    for (int32_t i = 0; i < n; i++) {
        int32_t key;
        cin >> key;
        key--;
        // Фишка решения: ребро двунаправленное
        graph[i].insert(key);
        graph[key].insert(i);
    }
    int result = 0;
    for (int32_t i = 0; i < n; i++) {
        if (colors[i] == WHITE) {
            // Как только появляется непокрашенная вершина, то result++
            // так как это говорит о новом независимом компоненте связности
            // как минимум одну копилку, чтобы доставть ключ и открыть остальыне
            result++;
            colorize(graph, colors, i);
        }
    }
    cout << result << endl;
    return 0;
}
