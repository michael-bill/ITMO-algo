#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define WHITE -1
#define BLACK 0

bool is_bipartite(vector<vector<int32_t>>& graph, int32_t start) {
    int32_t n = graph.size();
    vector<int32_t> colors(n, WHITE);
    queue<int32_t> q;

    q.push(start);
    colors[start] = BLACK;

    while (!q.empty()) {
        int32_t curr = q.front();
        q.pop();

        for (int32_t neighbor : graph[curr]) {
            if (colors[neighbor] == WHITE) {
                colors[neighbor] = 1 - colors[curr];
                q.push(neighbor);
            } else if (colors[neighbor] == colors[curr]) {
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char** argv) {
    int32_t n, m;
    cin >> n >> m;

    vector<vector<int32_t>> graph(n);

    for (int32_t i = 0; i < m; i++) {
        int32_t u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bool can_be_devided = true;
    for (int32_t i = 0; i < n; i++) {
        if (graph[i].size() > 0 && !is_bipartite(graph, i)) {
            can_be_devided = false;
            break;
        }
    }

    cout << (can_be_devided ? "YES" : "NO") << endl;

    return 0;
}
