void deleteEdge(vector<vector<pair<int, int>>> &adj, int u, int v) {
    adj[u].erase(remove_if(adj[u].begin(), adj[u].end(),
                           [v](const pair<int, int> &edge) { return edge.first == v; }),
                 adj[u].end());

    adj[v].erase(remove_if(adj[v].begin(), adj[v].end(),
                           [u](const pair<int, int> &edge) { return edge.first == u; }),
                 adj[v].end());
}