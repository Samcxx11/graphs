#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight}); 
}

void dijkstra(const vector<vector<pair<int, int>>> &adj, int start) {
    int V = adj.size();
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &[v, weight] : adj[u]) {
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest distances from node " << start << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << "\n";
    }
}

int main() {
    int V = 6; 
    vector<vector<pair<int, int>>> adj(V);

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 2, 1, 2);
    addEdge(adj, 1, 3, 1);
    addEdge(adj, 2, 3, 5);
    addEdge(adj, 3, 4, 3);
    addEdge(adj, 4, 5, 2);

    int start = 0;
    dijkstra(adj, start);

    return 0;
}
