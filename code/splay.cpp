//const int N = ;
//typedef int num;

int en = 1;
int p[N], sz[N];
int C[N][2]; // {left, right} children
num X[N];

// update values associated to the nodes that can be calculated from child
void calc(int u) {
	sz[u] = sz[C[u][0]] + 1 + sz[C[u][1]];
}

// pull child dir of u to its position and return
int rotate(int u, int dir) {
	int v = C[u][dir];
	C[u][dir] = C[v][!dir];
	if(C[u][dir]) p[C[u][dir]] = u;
	C[v][!dir] = u;
	p[v] = p[u];
	if(p[v]) C[p[v]][C[p[v]][1] == u] = v;
	p[u] = v;
	calc(u);
	calc(v);
	return v;
}

// bring node u to root
void splay(int u) {
	while(p[u]) {
		int v = p[u], w = p[p[u]];
		int du = C[v][1] == u;
		if(!w)
			rotate(v, du);
		else {
			int dv = (C[w][1] == v);
			if(du == dv) {
				rotate(w, dv);
				rotate(v, du);
			} else {
				rotate(v, du);
				rotate(w, dv);
			}
		}
	}
}

// return node with value x or other if node was not found
int find_val(int u, num x) {
	int v = u;
	while(u && X[u] != x) {
		v = u;
		if(x < X[u]) u = C[u][0];
		else u = C[u][1];
	}
	if(!u) u = v;
	splay(u);
	return u;
}

// return nth node
int find_sz(int u, int s) {
	while(sz[C[u][0]] != s) {
		if(sz[C[u][0]] < s) {
			s -= sz[C[u][0]] + 1;
			u = C[u][1];
		} else u = C[u][0];
	}
	splay(u);
	return u;
}

// concatenate two trees assuming #elements l <= #elements r
int merge(int l, int r) {
	if(!l || !r) return l + r;
	while(C[l][1]) l = C[l][1];
	splay(l);
	assert(!C[l][1]);
	C[l][1] = r;
	p[r] = l;
	calc(l);
	return l;
}

// add node x to splay u and return x
int add(int u, int x) {
	int v = 0;
	while(u) v = u, u = C[u][X[x] >= X[u]];
	if(v) { C[v][X[x] >= X[v]] = x; p[x] = v; }
	splay(x);
	return x;
}

// call 1 time at the top
void init() {
	en = 1;
}

// create a new node
int new_node(num val) {
	int i = en++;
	assert(i < N);
	C[i][0] = C[i][1] = p[i] = 0;
	sz[i] = 1;
	X[i] = val;
	return i;
}
