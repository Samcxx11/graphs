#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>> &adj, int V) {
    vector<int> color(V, -1);

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int neighbor : adj[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 0, 2); 

    if (isBipartite(adj, V)) {
        cout << "Bipartite: true" << endl;
    } else {
        cout << "Bipartite: false" << endl;
    }

    return 0;
}
