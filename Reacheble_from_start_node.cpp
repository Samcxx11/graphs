#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(int start, vector<vector<int>> &adj) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Nodes reachable from node " << start + 1 << ": ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node + 1 << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 5);

    int start = 0;
    bfs(start, adj);

    return 0;
}
