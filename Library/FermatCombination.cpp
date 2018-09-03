#define int long long
const int mod = 1e9+7;

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
