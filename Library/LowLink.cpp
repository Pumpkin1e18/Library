/*LowLink.cpp*/
#define repi(i,m,n) for(int i = m;i < n;i++)
#define rep(i,n) repi(i,0,n)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)

//橋検出
class LowLink{
public:
	int n, cnt1;
	vector<vector<int> > G, G2;	//G2は作ったグラフ(木)
	vector<int> pre, low, id, used;	//idは作成後のindex
	void init(int N){
		n = N;cnt1 = 0;
		pre.resize(n);low.resize(n);used.resize(n);
		G.resize(n);G2.resize(n);id.resize(n);
		fill(all(pre), -1);
	}
	void add_edge(int u, int v){
		G[u].pb(v);G[v].pb(u);
	}
	int dfs(int v = 0, int par = -1){	//橋の検出
		if(pre[v] >= 0)return pre[v];
		pre[v] = low[v] = cnt1++;
		rep(i,G[v].size())if(par != G[v][i]){
			int res = dfs(G[v][i], v);
			low[v] = min(low[v], res);
		}
		return low[v];
	}
	int build(int v = 0, int x = 0){	//橋のみを残した木の構築
		int mx = x;id[v] = x;
		used[v] = 1;
		rep(i,G[v].size())if(!used[G[v][i]]){
			if(pre[G[v][i]] == low[G[v][i]]){			//橋
				G2[id[v]].pb(x+1);G2[x+1].pb(id[v]);
				chmax(mx, build(G[v][i], x+1));x++;
			}else chmax(mx, build(G[v][i], id[v]));
		}
		return mx;
	}
	int lowlink(){
		rep(i,n)if(!used[i])dfs(i);
		fill(all(used), 0);
		int k = 0;
		rep(i,n)if(!used[i])k += (build(i, k)-k)+1;
		return k;
	}
};