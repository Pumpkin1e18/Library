#define repi(i,m,n) for(int i = m;i < n;i++)
#define rep(i,n) repi(i,0,n)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)

//二部マッチング
class Bipartite_Matching{
public:
	vector<vector<int> > G;
	vector<int> match;
	vector<bool> used;
	int n;
	void init(int N){
		n = N;
		G.resize(n);
		match.resize(n);
		used.resize(n);
	}
	void add_edge(int u, int v){
		G[u].pb(v);G[v].pb(u);
	}
	bool dfs(int v){
		used[v] = true;
		rep(i,G[v].size()){
			int u = G[v][i], w = match[u];
			if(w < 0 || (!used[w] && dfs(w))){
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
		return false;
	}
	int bipartite_matching(){
		int res = 0;
		fill(all(match), -1);
		rep(i,n)if(match[i] < 0){
			fill(all(used), 0);
			if(dfs(i))res++;
		}
		return res;
	}
};


