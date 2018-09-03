//二次元グリッド表示
rep(y,h){
  rep(x,w)printf("%lld ", a[y][x]);
  printf("\n");
}

//公約数
int gcd(int a, int b){
  if(a == 0 || b == 0)return max(a, b);
  if(a == b)return a;
  if(a > b)a = a%b;
	else b = b%a;
  return gcd(a, b);
}
//公倍数
int lcm(int a, int b){
  if(a == 0)return 0;
  return a/gcd(a, b)*b;
}

//高速累乗
int Pow(int x, int n){
  int ans = 1;
  while(n > 0){
    if(n & 1)ans *= x;
    x *= x;
    n >>= 1;
  }
  return ans;
}

//時計回り90度回転
void rotate(){
  rep(i,h)rep(j,w){tmp[i][j] = a[h-1-j][i];}
  rep(i,h)rep(j,w){a[i][j] = tmp[i][j];}
}

//Struct_Sort
//オーバーロードver
struct st{
	int a, b, c;
	bool operator<(const st& another) const {
		if (b != another.b)return b > another.b;
		if (c != another.c)return c > another.c;
		return a < another.a;
	}
};
sort(vec.begin(), vec.end())
//比較関数ver
struct st{int a, b, c;};
bool comp(const st& a, const st& b) {
	if (a.b != b.b)return a.b > b.b;
	if (a.c != b.c)return a.c > b.c;
	return a.a < b.a;
}
sort(vec.begin(), vec.end(), comp);


//Date and Integer
int length_of_year(int y){ // 1-indexed
  if(y%400 == 0 || ((y%100 != 0) && (y%4 == 0)))return 366;
  return 365;
}

int length_of_month(int y, int m){ // 1-indexed
  int monthes[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(m != 2)return monthes[m-1];
    if(length_of_year(y) == 366)return 29;
    return 28;
}

int date_to_int(string date){ //ex) 2018/08/05
    int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8, 2));
    int ans = 0;
    repi(i,1,y)ans += length_of_year(i);
    repi(i,1,m)ans += length_of_month(y, i);
    return ans + d;
}

string int_to_date(int date){
    int y = 1, m = 1;
    for(int i = 1;length_of_year(i) < date;i++){date -= length_of_year(i);y++;}
    for(int i = 1;length_of_month(y, i) < date;i++){date -= length_of_month(y, i);m++;}
    string ans;
    ans += string(4-to_string(y).size(), '0') + to_string(y) + "/";
    ans += string(2-to_string(m).size(), '0') + to_string(m) + "/";
    ans += string(2-to_string(date).size(), '0') + to_string(date);
    return ans;
}

int struct_to_int(int y, int m, int d){
	int ans = 0;
	repi(i,1,y)ans += length_of_year(i);
	repi(i,1,m)ans += length_of_month(y, i);
	return ans+d;
}

string struct_to_date(int y, int m, int d){
	return int_to_date(struct_to_int(y, m, d));
}


#include <bits/stdc++.h>
using namespace std;
#define int long long
#define UNIQUE(v) v.erase(unique(all(v)), v.end());
#define ZIP(v) sort(all(v)),UNIQUE(v)
#define ADD(a, b) a = (a + b) % mod
#define SUB(a, b) a = (a+mod-b)%mod
#define MUL(a, b) a = (a * b) % mod
#define repi(i,m,n) for(int i = m;i < n;i++)
#define drep(i,n,m) for(int i = n;i >= m;i--)
#define rep(i,n) repi(i,0,n)
#define rrep(i,n) repi(i,1,n+1)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define dmp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define fi first
#define se second
typedef pair<int,int> P;
typedef pair<int, P> PP;
typedef vector<int> vi;
const int inf = 1e9+7;
const int INF = 1e18+7;
/*chrono::system_clock::time_point  start;
void timerstart(){start = chrono::system_clock::now();}
void timerstop(){
	auto end = chrono::system_clock::now();
	int elapsed = chrono::duration_cast<chrono::milliseconds>(end-start).count();
	printf("%d[ms]\n", elapsed);
}*/

signed main(){
	
	return 0;
}

