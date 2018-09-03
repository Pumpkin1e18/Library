const int INF = 1e18+7;
#define all(v) v.begin(),v.end()
#define repi(i,m,n) for(int i = m;i < n;i++)
#define rep(i,n) repi(i,0,n)
typedef pair<int,int> P;
#define pb(x) push_back(x)
#define fi first
#define se second

//RMQもセット
class RMQ{
public:
	int n = 1;vector<P> seg;
	void init(int N){		//N要素のセグメントツリー作成
		while(n < N)n *= 2;seg.resize(2*n);
		fill(all(seg), P(INF, -1));
	}
	void update(int k, int x){
		k += n-1;seg[k] = P(x, k-(n-1));
		while(k > 0){k = (k-1)/2;seg[k] = min(seg[k*2+1], seg[k*2+2]);}
	}
	P calc(int a, int b, int k, int l, int r){
		if(b <= l || r <= a)return P(INF, -1);
		if(a <= l && r <= b)return seg[k];
		P vl = calc(a, b, k*2+1, l, (l+r)/2);
		P vr = calc(a, b, k*2+2, (l+r)/2, r);
		return min(vl, vr);
	}
	int get(int a, int b){return calc(a, b, 0, 0, n).se;}
};

class EulerTour{
public:
	vector<vector<int> > G;
	vector<int> vs, dep, idx;
	RMQ rmq;
	int n;
	void init(int N){
		n = N;
		G.resize(N);dep.resize(N);
		idx.resize(N);rmq.init(2*n-1);
	}
	void add_edge(int u, int v){
		G[u].pb(v);G[v].pb(u);
	}
	void dfs(int v, int par){
		idx[v] = vs.size();vs.pb(v);
		if(par != -1)dep[v] = dep[par]+1;
		rep(i,G[v].size())if(G[v][i] != par){
			dfs(G[v][i], v);vs.pb(v);
		}
	}
	void euler_tour(int root=0){
		dfs(root, -1);
		rep(i,2*n-1)rmq.update(i, dep[vs[i]]);
	}
	int lca(int u, int v){
		return vs[rmq.get(min(idx[u], idx[v]), max(idx[u], idx[v])+1)];
	}
	int distance(int u, int v){
		return dep[u]+dep[v]-2*dep[lca(u, v)];
	}
};


/*SparseTable
struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};
*/

