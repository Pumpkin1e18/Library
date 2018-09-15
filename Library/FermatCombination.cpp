/*FermatCombination.cpp*/
#define int long long
const int mod = 1e9+7;

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
int fac[MAX], finv[MAX], inv[MAX];

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

// 二項係数計算
int COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n]*(finv[k]*finv[n-k]%mod)%mod;
}