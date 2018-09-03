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

