#define pb(x) push_back(x)
#define all(v) v.begin(),v.end()

//入次数: 入次数が0の頂点からBFS
class TopologicalSort{
public:
	int n;
	vector<int> ans, deg;
	vector<vector<int> > G;
	void init(int N){
		n = N;
		deg.resize(n);G.resize(n);
	}
	void add_edge(int from, int to){	//DAG
		G[from].pb(to);deg[to]++;
	}
	void sort(){
		stack<int> st;
		rep(i,n)if(deg[i] == 0)st.push(i);
		while(!st.empty()){
			int v = st.top();st.pop();ans.pb(v);
			rep(i,G[v].size())if(--deg[G[v][i]] == 0)st.push(G[v][i]);
		}
	}
};


//DFS: 全ての点から深さ優先探索して、その帰りがけ順
class TopologicalSort{
public:
	int n;
	vector<int> ans, used;
	vector<vector<int> > G;
	void init(int N){
		n = N;
		used.resize(n);G.resize(n);
	}
	void add_edge(int from, int to){	//DAG
		G[from].pb(to);
	}
	void dfs(int v){
		if(used[v])return;
		used[v] = 1;
		for(int u: G[v])dfs(u);
		ans.pb(v);
	}
	bool sort(){
		rep(i,n)dfs(i);
		reverse(all(ans));
		return ans.size() == n;		//できなかった場合falseが返る
	}
};

