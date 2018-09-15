/*LazySegmentTree.cpp*/
const int INF = 1e18+7;
#define repi(i,m,n) for(int i = m;i < n;i++)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)

/*遅延セグ木*/

//RMQ and RAQ
//RSQ and RAQ
class RAQ{
public:
	int n = 1;
	vector<int> node[3], lazy;
	void init(int N){
		while(n < N)n *= 2;
		rep(i,3)node[i].resize(2*n-1);
		lazy.resize(2*n-1);
	}
	void lazy_evaluate(int k, int l, int r){
		rep(i,3)node[i][k] += i==2 ? lazy[k]*(r-l) : lazy[k];
		if(k < n-1)rrep(i,2){lazy[2*k+i] += lazy[k];}
		lazy[k] = 0;
	}
	void update(int a, int b, int x, int k, int l, int r){
		lazy_evaluate(k, l, r);
		if(r <= a || b <= l)return;
		if(a <= l && r <= b){
			lazy[k] += x;
			lazy_evaluate(k, l, r);
			return;
		}
		update(a, b, x, k*2+1, l, (l+r)/2);
		update(a, b, x, k*2+2, (l+r)/2, r);
		node[0][k] = max(node[0][k*2+1], node[0][k*2+2]);
		node[1][k] = min(node[1][k*2+1], node[1][k*2+2]);
		node[2][k] = node[2][k*2+1]+node[2][k*2+2];
	}
	int calc(int a, int b, int k, int l, int r, int f){
		lazy_evaluate(k, l, r);
		if(r <= a || b <= l)return !f ? -INF : f==1 ? INF : 0;
		if(a <= l && r <= b)return node[f][k];
		int vl = calc(a, b, k*2+1, l, (l+r)/2, f);
		int vr = calc(a, b, k*2+2, (l+r)/2, r, f);
		return !f ? max(vl, vr) : f==1 ? min(vl, vr) : vl+vr;
	}
	void add(int a, int b, int x){update(a, b, x, 0, 0, n);}
	int get_max(int a, int b){return calc(a, b, 0, 0, n, 0);}
	int get_min(int a, int b){return calc(a, b, 0, 0, n, 1);}
	int get_sum(int a, int b){return calc(a, b, 0, 0, n, 2);}
};


//RSQ and RUQ
//RMQ and RUQ
class RUQ{
public:
	int n = 1;
	vector<int> node[3], lazy;
	vector<bool> lazyF;
	void init(int N){
		while(n < N)n *= 2;
		rep(i,3)node[i].resize(2*n-1);
		lazy.resize(2*n-1);lazyF.resize(2*n-1, false);
	}
	void lazy_evaluate(int k, int l, int r){
		if(lazyF[k] == false)return;
		rep(i,3)node[i][k] = i==2 ? lazy[k]*(r-l) : lazy[k];
		if(k < n-1){
			rrep(i,2){lazy[2*k+i] = lazy[k];}
			rrep(i,2){lazyF[2*k+i] = true;}
		}
		lazyF[k] = false;
	}
	void update(int a, int b, int x, int k, int l, int r){
		lazy_evaluate(k, l, r);
		if(r <= a || b <= l)return;
		if(a <= l && r <= b){
			lazy[k] = x;lazyF[k] = true;
			lazy_evaluate(k, l, r);
			return;
		}
		update(a, b, x, k*2+1, l, (l+r)/2);
		update(a, b, x, k*2+2, (l+r)/2, r);
		node[0][k] = max(node[0][k*2+1], node[0][k*2+2]);
		node[1][k] = min(node[1][k*2+1], node[1][k*2+2]);
		node[2][k] = node[2][k*2+1]+node[2][k*2+2];
	}
	int calc(int a, int b, int k, int l, int r, int f){
		lazy_evaluate(k, l, r);
		if(r <= a || b <= l)return !f ? -INF : f==1 ? INF : 0;
		if(a <= l && r <= b)return node[f][k];
		int vl = calc(a, b, k*2+1, l, (l+r)/2, f);
		int vr = calc(a, b, k*2+2, (l+r)/2, r, f);
		return !f ? max(vl, vr) : f==1 ? min(vl, vr) : vl+vr;
	}
	void replace(int a, int b, int x){update(a, b, x, 0, 0, n);}
	int get_max(int a, int b){return calc(a, b, 0, 0, n, 0);}
	int get_min(int a, int b){return calc(a, b, 0, 0, n, 1);}
	int get_sum(int a, int b){return calc(a, b, 0, 0, n, 2);}
};