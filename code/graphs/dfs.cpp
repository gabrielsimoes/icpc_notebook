// const int N = ;
vector<int> adj[N]; // adj[i] is the adjacency list of vertex i
bool visited[N]; // visited[i] is true iff vertex i was visited

void add_edge(int u, int v) {
	adj[u].push_back(v);
	// if graph is undirected:
	// adj[v].push_back(u);
}

void dfs_util(int u) {
    visited[u] = true; 
	for (int v : adj[u])
		if (!visited[v])
			dfs_util(v);
}

void dfs(int n) {
    for (int i = 0; i < n; i++) 
        visited[i] = false; 
	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs_util(i);
}
