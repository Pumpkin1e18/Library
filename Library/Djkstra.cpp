/*Dijkstra.cpp*/
const int INF = 1e18+7;
typedef pair<int,int> P;
#define fi first
#define se second

class Dijkstra{
public:
	vector<vector<P> > G;
	vector<int> d;
	
	void init(int n){
		d.resize(n);
		G.resize(n);
	}
	void add_edge(int u, int v, int cost){	//無向or有向グラフ
		G[u].push_back(P(v, cost));
	}
	
	void dijkstra(int s){
		priority_queue<P, vector<P>, greater<P> > q;
		fill(d.begin(), d.end(), INF);
		d[s] = 0;
		q.push(P(0, s));
		while(!q.empty()){
			P p = q.top();q.pop();
			int v = p.se;
			if(d[p.se] < p.fi)continue;
			rep(i,G[v].size()){
				int to = G[v][i].fi, cost = G[v][i].se;
				if(d[to] > d[v]+cost){
					d[to] = d[v]+cost;
					q.push(P(d[to], to));
				}
			}
		}
	}
};