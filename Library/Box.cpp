

//宣言Box<型> box;
//表示 cout << box;
template <typename T>class Box;
template <typename T>ostream& operator<<(ostream &, const Box<T> &);
template<typename T>class Box{
public:
	T top;
  T back, left, right, head;
  T bottom;
	T a[6];
	void init(T TOP, T BACK, T LEFT, T RIGHT, T HEAD, T BOTTOM){
		top = TOP;back = BACK;left = LEFT;
		right = RIGHT;head = HEAD;bottom = BOTTOM;
		a[0] = top;a[1] = back;a[2] = left;
		a[3] = right;a[4] = head;a[5] = bottom;
	}
	friend ostream &operator<<<T>(ostream &os, const Box &B);
	bool operator==(const Box& b) const {
		return(top    == b.top   &&
					 back   == b.back  &&
					 left   == b.left  &&
					 right  == b.right &&
					 head   == b.head  &&
					 bottom == b.bottom);
	}
	void rotate(T &d1, T &d2, T &d3, T &d4){
		T tmp = d1;
		d1 = d2;d2 = d3;d3 = d4;
		d4 = tmp;
	}
	void rotate_forward(){rotate(top, head, bottom, back);}
	void rotate_right(){rotate(top, left, bottom, right);}
	void rotate_spin(){rotate(head, right, back, left);}
	friend ostream & operator<< <>(ostream &, const Box<T> & B);
};
template <typename T>
ostream & operator<<(ostream & os, const Box<T> & B){
	os <<  "  " 				<< B.back   << endl;
	os << B.left << " " << B.bottom << " " << B.right << " " << B.top << endl;
	os <<  "  " 				<< B.head   << endl;
	return os;
}


