typedef pair<int,int> P;
const int INF = 1e18+7;


//四則演算
//init()とsolve()呼ぶだけ
//空白や=はあってはいけない
class Arithmetic{
public:
	string str;
	int n, flag = 1;
	void init(string s){str = s;n = str.size();}
	int add(int a, int b){return a+b;}
	int mul(int a, int b){return a*b;}
	int div(int a, int b){return a/b;}
  int sur(int a, int b){return a%b;}
	
	P get_num(int p){
		int ans = 0, q = -1, f = 0;
		if(str[p] == '(')return calc(p+1, 0);
		if(str[p] == '-'){f = 1;p++;}
		if(str[p] == '('){P pi = calc(p+1, 0);return P(-pi.fi, pi.se);}
		repi(i,p,n){
			if(!isdigit(str[i]))break;
			ans = ans*10+(str[i]-'0');q = i;
		}
		if(f)return P(-ans, q);
		return P(ans, q);
	}
	
	P calc(int pp = 0, int f = 0){
		P pi = get_num(pp);
		int ans = pi.fi, p = pi.se+1;
		repi(i,p,n){
			if(f and str[i] == ')')return P(ans, i-1);
			if(str[i] == ')')return P(ans, i);
			if(str[i] == '*' or str[i] == '/' or str[i] == '%'){
				pi = get_num(i+1);
				if(str[i] == '*')ans = mul(ans, pi.fi);
				if(str[i] == '/')ans = div(ans, pi.fi);
        if(str[i] == '%')ans = sur(ans, pi.fi);
			}
			if(str[i] == '+' or str[i] == '-'){
				if(f)return P(ans, i-1);
				if(str[i] == '+')pi = calc(i+1, 1);
				if(str[i] == '-')pi = calc(i, 1);
				ans = add(ans, pi.fi);
			}
			i = pi.se;
		}
		return P(ans, n-1);
	}
	int solve(int ret = -INF){	//0除算のとき返す値
		flag = 1;
		P ans = calc();
		if(!flag)return ret;
		return ans.fi;
	}
};
