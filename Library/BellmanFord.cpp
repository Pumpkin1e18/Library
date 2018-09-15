/*BellmanFord.cpp*/
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define all(v) v.begin(),v.end()
const int INF = 1e18+7;

class BellmanFord{
public:
  struct edge{int from, to, cost;};
  vector<edge> es;
  vector<int> d;
  int n, m;
  void init(int N){
    d.resize(N);es.clear();n = N;
  }
  void add_edge(int u, int v, int cost){
    es.push_back(edge{u, v, cost});
  }
  bool find_negative_loop(){  //すべての負閉路を検出
    fill(all(d), 0);
    m = es.size();
    rep(i,n)rep(j,m){
      edge e = es[j];
      if(d[e.to] > d[e.from]+e.cost){
        d[e.to] = d[e.from]+e.cost;
        if(i == n-1)return true;
      }
    }
    return false;
  }
  bool bellman_ford(int s){ //負閉路があればtrueを返す
    fill(all(d), INF);
    m = es.size();
    d[s] = 0;
    rep(i,n){
      bool update = false;
      rep(j,m){
        edge e = es[j];
        if(d[e.from] != INF && d[e.to] > d[e.from]+e.cost){
          d[e.to] = d[e.from]+e.cost;
          update = true;
        }
      }
      if(!update)return false;
      if(i == n-1)return true;
    }
  }
};