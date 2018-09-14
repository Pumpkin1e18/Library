template <typename T>
using V = vector<T>;
template <typename T, typename U>
using P = pair<T, U>;
template <typename T>
using PQ = priority_queue<T>;
template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

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

//リストの使い方
list<int> lst(n, value);   //要素数n全ての要素の値valueで初期化
for(auto it = lst.begin(); it != lst.end();++it) {  //全要素アクセス
  cout << *it << endl;
}
for(auto x: lst)cout << x << endl;
lst.push_front(value);
lst.push_back(value);
lst.pop_front();
lst.pop_back();
lst.front();
lst.last();
lst.clear();
it = lst.insert(it, value);  //itの前にvalueを挿入し挿入したitを返す
it = lst.erase(it);   //要素を削除しitは次の要素を指す
lst.sort();
lst.empty()




