#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinKeyVertex(vector<int> &key, vector<bool> &inMST, int V) {
    int minKey = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>> &graph, int V) {
    vector<int> parent(V, -1), key(V, INT_MAX);
    vector<bool> inMST(V, false);
    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKeyVertex(key, inMST, V);
        inMST[u] = true;
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;
    cout << "MST edges:\n";
    for (int i = 1; i < V; i++) {
        cout << "(" << parent[i] + 1 << ", " << i + 1 << ")\n";
        totalCost += graph[i][parent[i]];
    }
    cout << "Total cost: " << totalCost << endl;
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0, 5, 6, 0},
        {5, 0, 2, 0},
        {6, 2, 0, 7},
        {0, 0, 7, 0}};
    primMST(graph, V);
    return 0;
}
