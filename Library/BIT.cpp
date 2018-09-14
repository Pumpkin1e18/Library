#define all(v) v.begin(),v.end()

// 0に対応できるよう内部でindexを1ずらしてる
class BIT{
public:
	int n = 1;
	vector<int> bit;
	void init(int N){	//[0, N)のBIT作成
		while(n < N+1)n *= 2;
		bit.resize(n+1);
		fill(all(bit), 0);
	}
	void add(int i, int x){
		i++;while(i <= n){bit[i] += x;i += i&-i;}
	}
	int get(int i){
		int s = 0;i++;
		while(i > 0){s += bit[i];i -= i&-i;}
		return s;
	}
	int lower_bound(int k){
		int lb = -1, ub = n;
		while(ub-lb > 1){
			if(get((lb+ub)/2) >= k)ub = (lb+ub)/2;
			else lb = (lb+ub)/2;
		}
		return ub;
	}
};

