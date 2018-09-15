/*Point.cpp*/
//外積|a||b|sinΘ > 0のとき線分bは線分aより左にある

// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )
double dot(Point a, Point b){
  return (a.real()*b.real() + a.imag()*b.imag());
}
double cross(Point a, Point b){
  return (a.real()*b.imag() - a.imag()*b.real());
}
double to_rad(double deg){return (deg/180*M_PI);}
double to_deg(double rad){return (rad/M_PI*180);}



//ICPC参考
//http://www.deqnotes.net/acmicpc/2d_geometry/
/*-------------------------------------------------------------------------------*/
typedef complex<double> Point;

// 許容する誤差ε
#define EPS (1e-10)
// 2つのスカラーが等しいかどうか
#define EQ(a,b) (abs((a)-(b)) < EPS)
// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()) )

// ベクトルaのxとyを取り出す
double x = a.real();
double y = a.imag();
// 複素数の偏角を得る
double r = arg(a);
// 極座標(絶対値:1.0, 偏角:45°)から複素数を作る
Point p = polar(1.0, to_rad(45));

// ベクトルaの絶対値を求める
double length = abs(a);

// 2点a,b間の距離を求める
double distance = abs(a-b);

// 内積 (dot product) : a・b = |a||b|cosΘ
double dot(Point a, Point b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}

// 外積 (cross product) : a×b = |a||b|sinΘ
double cross(Point a, Point b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}

// ベクトルaの単位ベクトルを求める
Point b = a / abs(a);

// ベクトルaの法線ベクトルn1,n2を求める
Point n1 = a * Point(0, 1);
Point n2 = a * Point(0, -1);

// ベクトルaの単位法線ベクトルun1,un2を求める
Point un1 = (a * Point(0, +1)) / abs(a);
Point un2 = (a * Point(0, -1)) / abs(a);

// 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
int is_orthogonal(Point a1, Point a2, Point b1, Point b2) {
  return EQ( dot(a1-a2, b1-b2), 0.0 );
}

// 2直線の平行判定 : a//b <=> cross(a, b) = 0
int is_parallel(Point a1, Point a2, Point b1, Point b2) {
  return EQ( cross(a1-a2, b1-b2), 0.0 );
}

// 点cが直線a,b上にあるかないか
int is_point_on_line(Point a, Point b, Point c) {
  return EQ( cross(b-a, c-a), 0.0 );
}

// 点cが線分a,b上にあるかないか(1)
int is_point_on_line(Point a, Point b, Point c) {
  return EQ( cross(b-a, c-a), 0.0 ) &&
            (dot(b-a, c-a) > -EPS) &&
            (dot(a-b, c-b) > -EPS);
}

// 点cが線分a,b上にあるかないか(2)
int is_point_on_line(Point a, Point b, Point c) {
  // |a-c| + |c-b| <= |a-b| なら線分上
  return (abs(a-c) + abs(c-b) < abs(a-b) + EPS);
}

// 点a,bを通る直線と点cとの距離|(b-a)×(c-a)|/|(b-a)|
double distance_l_p(Point a, Point b, Point c) {
  return abs(cross(b-a, c-a)) / abs(b-a);
}

// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(Point a, Point b, Point c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(Point a1, Point a2, Point b1, Point b2) {
  return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
         ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交点計算（前提：2線分は交差している）
Point intersection_ls(Point a1, Point a2, Point b1, Point b2) {
  Point b = b2-b1;
  double d1 = abs(cross(b, a1-b1));
  double d2 = abs(cross(b, a2-b1));
  double t = d1 / (d1 + d2);

  return a1 + (a2-a1) * t;
}

// a1,a2を通る直線とb1,b2を通る直線の交差判定
int is_intersected_l(Point a1, Point a2, Point b1, Point b2) {
  return !EQ( cross(a1-a2, b1-b2), 0.0 );
}

// a1,a2を通る直線とb1,b2を通る直線の交点計算（前提：2直線は平行でない）
Point intersection_l(Point a1, Point a2, Point b1, Point b2) {
  Point a = a2 - a1; Point b = b2 - b1;
  return a1 + a * cross(b, b1-a1) / cross(b, a);
}
/*-------------------------------------------------------------------------------*/





//蟻本参考(p.226)
/*-------------------------------------------------------------------------------*/
double add(double a, double b){
  if(abs(a+b) < EPS*(abs(a)+abs(b)))return 0;
  return a+b;
}
class Point{
public:
  double x, y;
  Point(){}
  Point(double x, double y) : x(x), y(y){}
  Point operator +(Point p){
    return Point(add(x, p.x), add(y, p.y));
  }
  Point operator -(Point p){
    return Point(add(x, -p.x), add(y, -p.y));
  }
  Point operator *(double d){
    return Point(x*d, y*d);
  }
};
double dot(Point p1, Point p2){
  return add(p1.x*p2.x, p1.y*p2.y);
}
double cross(Point p1, Point p2){
  return add(p1.x*p2.y, -p1.y*p2.x);
}
/*-------------------------------------------------------------------------------*/




//PCK参考
//http://web-ext.u-aizu.ac.jp/pc-concours/2018/download/pastexam/pck2009pre_commentary.pdf
/*-------------------------------------------------------------------------------*/
#define EPS (1e-8)
#define equals(a, b) (fabs((a) - (b)) < EPS )
#define dle(a, b) (equals(a, b) || a < b )
static const double PI = acos(-1);
class Point{
public:
  double x, y;
  Point ( double x = 0, double y = 0): x(x), y(y){}
  
  friend ostream &operator<<(ostream &os, const Point &p);
  Point operator + ( Point p ){ return Point(x + p.x, y + p.y); }
  Point operator - ( Point p ){ return Point(x - p.x, y - p.y); }
  Point operator * ( double a ){ return Point(x*a, y*a); }
  double abs() { return sqrt(norm());}
  double norm() { return x*x + y*y; }
  bool operator < ( const Point &p ) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  bool operator == ( const Point &p ) const {
    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;
  }
};
ostream &operator<<(ostream &os, const Point &p){os << pt.x << " " << pt.y;return os;}

typedef Point Vector;
class Segment{public: Point p1, p2; Segment(Point s = Point(), Point t = Point()): p1(s), p2(t){}};
typedef Segment Line;
class Circle{public: Point c; double r; Circle(Point c = Point(), double r = 0.0): c(c), r(r){}};
typedef vector<Point> Polygon;
double norm( Vector a ){ return a.x*a.x + a.y*a.y; }
double abs( Vector a ){ return sqrt(norm(a)); }
Point polar( double a, double r ){ return Point(cos(r)*a, sin(r)*a);}
double getDistance( Vector a, Vector b ){ return abs(a - b); }
double dot( Vector a, Vector b ){ return a.x*b.x + a.y*b.y; }
double cross( Vector a, Vector b ){ return a.x*b.y - a.y*b.x; }
/*-------------------------------------------------------------------------------*/



