/*SCC.cpp*/
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define repi(i,m,n) for(int i = m;i < n;i++)
#define rep(i,n) repi(i,0,n)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)
typedef vector<int> vi;

//強連結成分分解
class SCC{
public:
	int n;
	vector<vector<int> > G, rG, G2;
	vector<int> vs, id, used;
	void init(int N){
		n = N;
		G.resize(n);rG.resize(n);G2.resize(n);
		vs.resize(n);id.resize(n);used.resize(n);
	}
	void add_edge(int from, int to){	//有向グラフ
		G[from].pb(to);
		rG[to].pb(from);	//逆辺
	}
	void dfs(int v){
		used[v] = 1;
		rep(i,G[v].size())if(!used[G[v][i]])dfs(G[v][i]);
		vs.pb(v);
	}
	void rdfs(int v, int k){
		used[v] = 1;
		id[v] = k;
		rep(i,rG[v].size()){
			int to = rG[v][i];
			if(!used[to])rdfs(to, k);
			else if(id[to] != id[v])G2[id[to]].pb(id[v]);
		}
	}
	int scc(){
		fill(all(used), 0);
		vs.clear();
		rep(i,n)if(!used[i])dfs(i);
		fill(all(used), 0);
		int k = 0, size = vs.size();
		drep(i,size-1,0)if(!used[vs[i]])rdfs(vs[i], k++);
		rep(i,k)ZIP(G2[i]);
		return k;
	}
};