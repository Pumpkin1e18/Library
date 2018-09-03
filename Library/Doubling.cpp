#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define pb(x) push_back(x)

//ダブリング
class Doubling{
public:
	vector<vector<int> > table, G;
	vector<int> dep;
	int n, logn = 1;
	void init(int N){
		n = N;
		while((1<<logn) <= N)logn++;
		G.resize(N);dep.resize(N);
		table.resize(logn);
		rep(i,logn)table[i].resize(N);
	}
	void add_edge(int u, int v){	//木
		G[u].pb(v);G[v].pb(u);
	}
	void dfs(int v, int par){
		table[0][v] = par;
		if(par != -1)dep[v] = dep[par]+1;
		rep(i,G[v].size())if(G[v][i] != par)dfs(G[v][i], v);
	}
	void build(int root=0){
		dfs(root, -1);
		rrep(i,logn-1)rep(j,n){
			if(table[i-1][j] == -1)table[i][j] = -1;
			else table[i][j] = table[i-1][table[i-1][j]];
		}
	}
	int lca(int u, int v){
		if(dep[u] > dep[v])swap(u, v);
		rep(i,logn)if((dep[v]-dep[u]) & (1<<i))v = table[i][v];
		if(v == u)return v;
		drep(i,logn-1,0){
			if(table[i][u] == -1)continue;
			if(table[i][u] != table[i][v]){u = table[i][u];v = table[i][v];}
		}
		return table[0][v];
	}
	int distance(int u, int v){
		return dep[u]+dep[v]-2*dep[lca(u, v)];
	}
};


