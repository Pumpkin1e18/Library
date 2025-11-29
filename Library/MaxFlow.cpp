/*MaxFlow.cpp*/

// Ford-Fulkerson
// 計算量：O(F|E|)　（F：最大流）（実際にはもっと高速に動作するがDinic法の方が高速）

class FordFulkerson {
public:
	struct edge { int to, cap, rev; };
	vector<vector<edge>> G;
	vector<bool> used;

	void init(int n) {
		G.resize(n);
		used.resize(n);
	}
	void add_edge(int from, int to, int cap) {		//有向グラフ
		G[from].push_back((edge){to, cap, (int)G[to].size()});
		G[to].push_back((edge){from, 0, (int)G[from].size()-1});
	}

    // privateメソッド：増加パスをDFSで探す
	int dfs(int v, int t, int f) {
		if(v == t) return f;
		used[v] = true;
        for (edge &e : G[v]) {
			if(!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		for(;;) {
			fill(used.begin(), used.end(), 0);
			int f = dfs(s, t, INF);
			if(f == 0) return flow;
			flow += f;
		}
	}
};


// Dinic法
// 計算量：O(|E||V|^2)　（実際にはもっと高速に動作する）
class Dinic {
public:
	struct edge { int to, cap, rev; };
	vector<vector<edge>> G;
	vector<int> level;
    vector<int> iter;

	void init(int n) {
		G.resize(n);
		level.resize(n);
        iter.resize(n);
	}
	void add_edge(int from, int to, int cap) {		//有向グラフ
		G[from].push_back((edge){to, cap, (int)G[to].size()});
		G[to].push_back((edge){from, 0, (int)G[from].size()-1});
	}

    // privateメソッド：sからの最短距離（level）をBFSで計算する
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            rep(i,G[v].size()) {
                edge &e = G[v][i];
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    // privateメソッド：増加パスをDFSで探す
	int dfs(int v, int t, int f) {
		if(v == t) return f;
		for(int &i = iter[v]; i < G[v].size(); i++) {
			edge &e = G[v][i];
			if(e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		for(;;){
            bfs(s);
            if (level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
			int f;
            while ((f = dfs(s, t, INF)) > 0) {
                flow += f;
            }
		}
	}
};
