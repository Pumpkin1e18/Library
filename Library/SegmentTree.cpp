/*SegmentTree.cpp*/
const int INF = 1e18+7;
#define all(v) v.begin(),v.end()
#define repi(i,m,n) for(int i = m;i < n;i++)
#define rep(i,n) repi(i,0,n)
typedef pair<int,int> P;
#define fi first
#define se second

//Range Minimum(Maximum) Query (RMQ)
//Big Range Query
//セグメント木 P(x, y) = P(値, 要素番号)
//インデックス取得したい場合: seg.update(k, k)
class SegmentTree{
public:
	int n = 1;
	vector<P> seg[2];		//0:最大	1:最小
	void init(int N){		//N要素のセグメントツリー作成
		while(n < N)n *= 2;
		rep(i,2)seg[i].resize(2*n);
		fill(all(seg[0]), P(-INF, -1));
		fill(all(seg[1]), P(INF, -1));
	}
	P cmp_min(P x, P y){		//比較関数
		if(x.fi == y.fi)return x.se < y.se ? x : y;
		return min(x, y);
	}
	P cmp_max(P x, P y){		//比較関数
		if(x.fi == y.fi)return x.se < y.se ? x : y;
		return max(x, y);
	}
	void update(int k, int x, bool flag=false){		//kの値をxに変更, flag==trueの時は値を消す
		k += n-1;
		seg[0][k] = seg[1][k] = P(x, k-(n-1));
		if(flag){seg[0][k] = P(-INF, -1);seg[1][k] = P(INF, -1);}
		while(k > 0){
			k = (k-1)/2;
			seg[0][k] = cmp_max(seg[0][k*2+1], seg[0][k*2+2]);
			seg[1][k] = cmp_min(seg[1][k*2+1], seg[1][k*2+2]);
		}
	}
	P calc(int a, int b, int k, int l, int r, int f){
		if(b <= l || r <= a)return f ? P(INF, -1) : P(-INF, -1);
		if(a <= l && r <= b)return seg[f][k];
		P vl = calc(a, b, k*2+1, l, (l+r)/2, f);
		P vr = calc(a, b, k*2+2, (l+r)/2, r, f);
		return f ? cmp_min(vl, vr) : cmp_max(vl, vr);
	}
	void erase(int k){update(k, -1, true);}    // 値を消す
	int get_max(int a, int b){return calc(a, b, 0, 0, n, 0).fi;}   // [a, b)
	int get_min(int a, int b){return calc(a, b, 0, 0, n, 1).fi;}   // [a, b)
};