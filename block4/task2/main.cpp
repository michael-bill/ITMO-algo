#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define WHITE 0
#define BLACK 1

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
    vector<unordered_set<int32_t>> graph(n);
    vector<int32_t> colors(n, WHITE);
    for (int32_t i = 0; i < n; i++) {
        int32_t key;
        cin >> key;
        key--;
        graph[i].insert(key);
        graph[key].insert(i);
    }
    int result = 0;
    for (int32_t i = 0; i < n; i++) {
        if (colors[i] == WHITE) {
            result++;
            colorize(graph, colors, i);
        }
    }
    cout << result << endl;
    return 0;
}
