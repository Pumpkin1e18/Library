#define all(v) v.begin(),v.end()

class BIT{
public:
	int n = 1;
	vector<int> bit;
	void init(int N){	//[1, N]のBIT作成
		while(n < N+1)n *= 2;
		bit.resize(n+1);
		fill(all(bit), 0);
	}
	void add(int i, int x){
		while(i <= n){bit[i] += x;i += i&-i;}
	}
	int get(int i){
		int s = 0;
		while(i > 0){s += bit[i];i -= i&-i;}
		return s;
	}
	int lower_bound(int k, int ret = -1){	//ret=見つからなかったときに返すidx
		int lb = 0, ub = n+1;
		while(ub-lb > 1){
			if(get((lb+ub)/2) >= k)ub = (lb+ub)/2;
			else lb = (lb+ub)/2;
		}
		return ub == n+1 ? ret : ub;
	}
};

