/* Dijkstra.cpp */
#include <bits/stdc++.h>
using namespace std;

template<class T> class Dijkstra {
public:
    const T DINF;
	vector<vector<pair<int,T>>> G;
	vector<T> d;

    Dijkstra(int n, T INF_=numeric_limits<T>::max()/4): DINF(INF_), G(n), d(n) {}
	void add_edge(int u, int v, T cost) { G[u].push_back({v, cost}); }
	void run(int s) {
		priority_queue<pair<T,int>, vector<pair<T,int>>, greater<pair<T,int>>> q;
		fill(d.begin(), d.end(), DINF);
		d[s] = 0;
		q.push({0, s});
		while (!q.empty()) {
			auto [dist, v] = q.top(); q.pop();
			if (d[v] < dist) continue;
			for (auto [to, cost]: G[v]) {
                if (d[to] <= dist+cost) continue;
                d[to] = dist+cost;
                q.push({d[to], to});
			}
		}
	}
};

// Dijkstra<int> dj(3);
// dj.add_edge(0, 1, 5);
// dj.add_edge(1, 2, 10);
// dj.run(0);
