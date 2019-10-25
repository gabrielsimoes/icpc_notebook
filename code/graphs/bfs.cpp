// const int N = ;

vector<int> adj[N]; // adj[i] is the adjacency list of vertex i
bool visited[N]; // visited[i] is true iff vertex i was visited
int dist[N]; // dist[i] is distance from start to vertex i

void add_edge(int u, int v) {
	adj[u].push_back(v);
	// if graph is undirected:
	// adj[v].push_back(u);
}

void bfs(int start) {
    queue<int> q; 
    q.push(start); 
    visited[start] = true; 
	dist[start] = 0;

    while (!q.empty()) { 
        int u = q.front(); q.pop(); 

		for (int v : adj[u]) {
			if (!visited[v]) {
				q.push(v);
				visited[v] = true;
				dist[v] = dist[u] + 1;
			}
		}
    } 
}

