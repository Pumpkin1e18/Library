/*FermatCombination.cpp*/
#define int long long
const int mod = 1e9+7;

// nPr: n個からr個取る順列(順列)
// nCr: 異なるn個のものからr個を選ぶ組み合わせの総数(組み合わせ)
// nHr = n+r-1Cr: 異なるn個のものから重複を許してr個を選ぶ組み合わせの総数(重複組み合わせ)

//O(NlogN)遅い
class FermatCombination{
private:
	vector<int> fac, inv;
	int Pow(int x, int n){
		if(n < 0)n += mod-1;
		int ans = 1;
		while(n > 0){
			if(n & 1)ans = (ans*x)%mod;
			x = (x*x)%mod;
			n >>= 1;
		}
		return ans;
	}
	void Factrial(int n){
		fac[0] = inv[0] = 1;
		for(int i = 1;i <= n;i++){
			fac[i] = (fac[i-1]*i)%mod;
			inv[i] = Pow(fac[i], mod-2);
		}
	}
	
public:
	void init(int n){	//nCk
		fac.resize(n+1);
		inv.resize(n+1);
		Factrial(n);
	}
	int comb(int n, int k){
		if(n < k)return 0;
		if(k == 0)return 1;
		int tmp = (fac[n]*inv[k])%mod;
		return (tmp*inv[n-k])%mod;
	}
};

//けんちょんさんの記事を参考
//こっちの方が高速O(N)
//http://drken1215.hatenablog.com/entry/2018/06/08/210000
const int mod = 1e9+7, MAX = 1e6;
// fac[n]: n!, inv[n]:1/n, finv[n]:1/n!
int fac[MAX], inv[MAX], finv[MAX];

// テーブルを作る前処理
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i-1]*i%mod;
        inv[i] = mod-inv[mod%i]*(mod/i)%mod;
        finv[i] = finv[i-1]*inv[i]%mod;
    }
}

int nPk(int n, int k){
  if(n < k)return 0;
  if(n < 0 or k < 0)return 0;
  return fac[n] * finv[n-k] % mod;
}

// 二項係数計算
int nCk(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}


// 分割数
// http://d.hatena.ne.jp/incognita/20110305/1299344781
// Q(n,r): 整数nを順序を区別せずにr個の自然数の和に分ける場合の数（分割数）
//         = (1):n個の区別できないボールをr個の区別できない筒に入れる場合の数
//         = (2):n個の区別できないボールをいくつかのグループに分ける場合の数（1グループの最大ボール数をrとする）
// P(n): nを順序を区別せずに自然数の和に分ける場合の数

// 以下ははQ(7,3)の例（縦横を入れ替えると等しい）
// 7を3つに分ける = 最大の数が3になるように7を分ける
// (1):[5+1+1] = (2):[3+1+1+1+1]
// (1):[4+2+1] = (2):[3+2+1+1]
// (1):[3+3+1] = (2):[3+2+2]
// (1):[3+2+2] = (2):[3+3+1]

// 仕様
// P(0) = 1
// Q(n,1) = 1 (n≧1)
// Q(n,n) = 1 (n≧1)
// Q(n,r) = Q(n-1,r-1) + Q(n-r,r) (n≧r≧2)		(n-r<0)の場合 0
// P(n) = Q(n,1) + Q(n,2) + ... + Q(n,n)


// Q(n,r): 整数nを順序を区別せずにr個の自然数の和に分ける場合の数
// P(n): nを順序を区別せずに自然数の和に分ける場合の数
const int mod = 1e9+7, MAX = 1e3;
int q[MAX][MAX], p[MAX];

// 前処理
void init(){
	repi(i,1,MAX) q[i][1] = 1;
	p[0] = p[1] = 1;
	repi(i,2,MAX) {
		p[i] = 1;
		repi(j,2,MAX) {
			if(i < j) break;
			q[i][j] = ADD(q[i-1][j-1], q[i-j][j]);
			p[i] = ADD(p[i], q[i][j]);
		}	
	}
}
