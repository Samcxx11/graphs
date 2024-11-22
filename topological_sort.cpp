#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &topoStack) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, topoStack);
        }
    }
    topoStack.push(node);
}

void topologicalSort(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    stack<int> topoStack;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, topoStack);
        }
    }

    cout << "Topological order: ";
    while (!topoStack.empty()) {
        cout << topoStack.top() + 1 << " ";
        topoStack.pop();
    }
    cout << endl;
}

void addEdge(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

int main() {
    int V = 3;
    vector<vector<int>> adj(V);

    addEdge(adj, 0, 1); 
    addEdge(adj, 1, 2); 
    addEdge(adj, 0, 2); 

    topologicalSort(V, adj);

    return 0;
}
