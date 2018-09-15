/*HLDecomposition.cpp*/
#define all(v) v.begin(),v.end()
#define pb(x) push_back(x)

//HL分解
class HLDecomposition{
public:
	#define rs(n) resize(n)
	//chain[i]: i番目の頂点の所属するグループ番号
	//heavy[i]: i番目の頂点のグループ内での次の番号
	//head[i]: chain[i]の根
	//id[i]: chain[i]の中のでの番号
	//chains.size()グループの数を取得
	int n;
	vector<int> dep, par, heavy, head, chain, id, size, q;
	vector<vector<int> > G, chains, childs;
	void init(int N){		//要素数ピッタリで代入
		n = N;G.rs(n);
		dep.rs(n);dep.rs(n);par.rs(n);heavy.rs(n);
		head.rs(n);chain.rs(n);id.rs(n);size.rs(n);q.rs(n);
	}
	void add_edge(int u, int v){	//木
		G[u].push_back(v);G[v].push_back(u);
	}
	void find_par(int root){	//親を記憶
		fill(all(par), -1);
		par[root] = 0;
		int l = 0, r = 0;
		q[r++] = root;
		while(l < r){
			int v = q[l++];
			for(int w: G[v])if(par[w] == -1){q[r++] = w;par[w] = v;}
		}
		par[root] = -1;
	}
	void calc_heavy(int root){	//部分木の重さ計算
		childs.assign(n, vector<int>());
		rep(i,n){		//子供記憶
			size[i] = 0;heavy[i] = -1;
			if(par[i] != -1)childs[par[i]].pb(i);
		}
		int l = 0, r = 0;
		q[r++] = root;
		while(l < r){		//深さ計算
			int v = q[l++];
			for(int w: childs[v]){
				if(w == par[v])continue;
				dep[w] = dep[v]+1;
				q[r++] = w;
			}
		}
		reverse(all(q));
		rep(i,n){		//heavy更新
			if(i == root)continue;
			int v = i, u = par[v];
			size[u] += ++size[v];
			if(heavy[u] == -1 or size[v] > size[heavy[u]])heavy[u] = v;
		}
	}
	void calc_chain(){		//chain, id番号付け
		chains.clear();
		int idx = 0;
		rep(v,n){
			if(par[v] == -1 or heavy[par[v]] != v){
				chains.push_back(vector<int>());
				for(int w = v;w != -1;w = heavy[w]){
					chain[w] = idx;
					head[w] = v;
					id[w] = chains.back().size();
					chains.back().push_back(w);
				}
				idx++;
			}
		}
	}
	void build(int root = 0){
		find_par(root);
		calc_heavy(root);
		calc_chain();
	}
	int lca(int u, int v){
		while(chain[u] != chain[v]){
			if(dep[head[u]] > dep[head[v]])swap(u, v);
			v = par[head[v]];
		}
		return dep[u] < dep[v] ? u : v;
	}
	int distance(int u, int v){
		return dep[u]+dep[v]-2*dep[lca(u, v)];
	}
};