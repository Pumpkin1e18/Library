/*UnionFind.cpp*/

class UnionFind{
public:
	vector<int> parent, depth, cnt;
	void init(int n){
		for(int i = 0; i < n; i++){
			parent.push_back(i);
			depth.push_back(0);
			cnt.push_back(1);
		}
	}
	
	int find(int x){
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(depth[x] < depth[y]){
			parent[x] = y;
			cnt[y] += cnt[x];
		} else {
			parent[y] = x;
			cnt[x] += cnt[y];
			if(depth[x] == depth[y]) depth[x]++;
		}
	}
	
	bool same(int x, int y){
		return find(x) == find(y);
	}
	
	int size(int x){
		return cnt[find(x)];
	}
};