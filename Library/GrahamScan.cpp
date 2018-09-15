/*GrahamScan.cpp*/
// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
typedef complex<double> Point;


//凸包
double dot(Point a, Point b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
double cross(Point a, Point b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
bool cmp_x(const Point &p1, const Point &p2){
  if(p1.real() == p2.real())return p1.imag() < p2.imag();
  return p1.real() < p2.real();
}
class GrahamScan{
public:
  vector<Point> ps;
  int n;
  void init(int N){
    ps.clear();
    n = N;
  }
  void add_point(int x, int y){
    ps.push_back(Point(x, y));
  }
  vector<Point> graham_scan(){  //作った凸のvectorを返す
    sort(ps.begin(), ps.end(), cmp_x);
    int k = 0;
    vector<Point> qs(2*n);
    for(int i = 0;i < n;i++){   //下側凸の作成
      while(k > 1 && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <= 0)k--;
      qs[k++] = ps[i];
    }
    for(int i = n-2, t = k;i >= 0;i--){   //上側凸の作成
      while(k > t && cross(qs[k-1]-qs[k-2], ps[i]-qs[k-1]) <= 0)k--;
      qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
  }
};