/* ZeroOneBFS.cpp */
#include <bits/stdc++.h>
using namespace std;

template<class T> class ZeroOneBFS {
public:
    const T DINF;
    vector<vector<pair<int,T>>> G;
    vector<T> d;

    ZeroOneBFS(int n, T INF_=numeric_limits<T>::max()/4): DINF(INF_), G(n), d(n) {}
    void add_edge(int u, int v, T cost) { G[u].push_back({v, cost}); }  // cost は 0 or 1 を想定
    void run(int s) {
        deque<int> q;
        fill(d.begin(), d.end(), DINF);
        d[s] = 0;
        q.push_back(s);
        while (!q.empty()) {
            int v = q.front(); q.pop_front();
            T dist = d[v];
            for (auto [to, cost]: G[v]) {
                if (d[to] <= dist + cost) continue;
                d[to] = dist + cost;
                if (cost == 0) q.push_front(to);
                else q.push_back(to);
            }
        }
    }
};

// ZeroOneBFS<int> bf(3);
// bf.add_edge(0, 1, 0);
// bf.add_edge(1, 2, 1);
// bf.run(0);
