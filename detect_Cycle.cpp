#include <iostream>
#include <vector>
using namespace std;

bool dfsCycleDetection(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfsCycleDetection(neighbor, node, adj, visited))
                return true;
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

bool containsCycle(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCycleDetection(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);

    if (containsCycle(V, adj)) {
        cout << "Cycle detected: true" << endl;
    } else {
        cout << "Cycle detected: false" << endl;
    }

    return 0;
}
