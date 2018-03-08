//const int N = ;
//typedef ll num;
//const num eps = ;

// Solves minimum perfect matching in an n by n bipartite graph with edge costs in c
// y and z will be such that
// y[i] + z[j] <= c[i][j]
// and sum of y and z is maximum
struct hungarian {
	int n, MA[N], MB[N], PB[N], mn[N];
	num c[N][N], d[N];

	bool S[N], T[N];
	int st[N], sn;
	num y[N], z[N];

	void reset_all() {
		for(int i = 0; i < n; i++) {
			y[i] = *min_element(c[i], c[i] + n);
			z[i] = 0;
		}
		int i;
		for(i = 0; i < n; i++)
			MA[i] = MB[i] = -1;
	}

	bool increase(int b) {
		int a = PB[b];
		while(true) {
			int n_b = MA[a];
			MB[b] = a;
			MA[a] = b;
			if(n_b == -1) break;
			b = n_b;
			a = PB[b];
		}
		return true;
	}

	bool visit(int a) {
		S[a] = true;
		for(int b = 0; b < n; b++) {
			if(T[b]) continue;
			if(c[a][b] - y[a] - z[b] < d[b] - eps) {
				d[b] = c[a][b] - y[a] - z[b];
				mn[b] = a;
			}
			if(c[a][b] - eps <= y[a] + z[b]) {
				T[b] = true;
				PB[b] = a;
				st[sn++] = b;
				if(MB[b] == -1)
					return increase(b);
			}
		}
		return false;
	}

	bool update_dual() {
		int mb = -1, b;
		for(b = 0; b < n; b++)
			if(!T[b] && (mb == -1 || d[b] < d[mb]))
				mb = b;
		num e = d[mb];
		for(b = 0; b < n; b++)
			if(T[b]) z[b] -= e;
			else d[b] -= e;
		for(int a = 0; a < n; a++)
			if(S[a]) y[a] += e;
		PB[mb] = mn[mb];
		if(MB[mb] == -1) return increase(mb);
		st[sn++] = mb;
		T[mb] = true;
		return false;
	}

	void find_path() {
		int a;
		for(a = 0; MA[a] != -1; a++);
		memset(S, 0, sizeof S);
		memset(T, 0, sizeof T);
		for(int i = 0; i < N; i++) d[i] = numeric_limits<num>::max();
		sn = 0;
		if(visit(a)) return;
		while(true) {
			if(sn) { if(visit(MB[st[--sn]])) break; }
			else if(update_dual()) break;
		}
	}

	// Just call this function after setting up n and c
	num min_match() {
		reset_all();
		for(int i = 0; i < n; i++)
			find_path();
		num all = 0;
		for(int a = 0; a < n; a++)
			all += c[a][MA[a]];
		return all;
	}
};
