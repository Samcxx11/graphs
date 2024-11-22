#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function
void dfsR(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true; // Mark the current node as visited
    cout << s << " ";  // Print the node (DFS traversal order)

    for (int i : adj[s]) {
        if (!visited[i]) { // Check if the neighbor is not visited
            dfsR(adj, visited, i);
        }
    }
}

// DFS function to initialize the visited array and start the recursive DFS
void dfs(vector<vector<int>> &adj, int s) {
    vector<bool> visited(adj.size(), false); // Initialize visited array
    dfsR(adj, visited, s);                   // Start DFS from node `s`
}

// Add an edge to the graph (undirected graph)
void addEdge(vector<vector<int>> &adj, int i, int j) {
    adj[i].push_back(j);
    adj[j].push_back(i);
}

// Main function
int main() {
    int v = 4; // Number of vertices
    vector<vector<int>> adj(v);

    // Add edges to the graph
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);

    int startNode = 1; // Start DFS from node 1
    cout << "DFS Traversal starting from node " << startNode << ": ";
    dfs(adj, startNode);
    cout << endl;

    return 0;
}
