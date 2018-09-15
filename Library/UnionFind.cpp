/*UnionFind.cpp*/

class UnionFind{
public:
	vector<int> ran, par;
	void init(int n){
		for(int i = 0;i < n;i++){
			par.push_back(i);
			ran.push_back(0);
		}
	}
	
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	
	void unite(int x, int y){
		x = find(par[x]);
		y = find(par[y]);
		if(x == y)return;
		if(ran[x] < ran[y]){
			par[x] = y;
		}else{
			par[y] = x;
			if(par[x] == par[y])ran[x]++;
		}
	}
	
	bool same(int x, int y){
		return find(par[x]) == find(par[y]);
	}
};