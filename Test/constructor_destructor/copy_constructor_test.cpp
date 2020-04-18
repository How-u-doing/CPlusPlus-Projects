#include <iostream>

using namespace std;

class Point {
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {
		//note that only in VS 2019, when we want print address, it won't print Ox, while Unix-like does print
		cout << "Constructor called --> P(" << x << ',' << y << ")" << "\t with address --> 0x" << this << "\n\n";
	}
	Point(const Point& A) : x(A.x), y(A.y) {
		cout << "Copy constructor called --> P(" << x << ',' << y << ")" << "\t with address --> 0x" << this << "\n\n";
	}
	// try to umcomment move constructor/assignment
	/*Point(Point&& A) noexcept :x{ 0 }, y{ 0 } {
		swap(x, A.x); swap(y, A.y);
		cout << "Move constructor called --> P(" << x << ',' << y << ")" << "\t with address --> 0x" << this << "\n\n";
	}
	Point& operator=(Point&& A)noexcept {
		if (this == &A) return *this;
		swap(x, A.x); swap(y, A.y);
		cout << "Move assignment called --> P(" << x << ',' << y << ")" << "\t with address --> 0x" << this << "\n\n";
		return *this;
	}*/

	Point& operator=(const Point& A) {
		x = A.x; y = A.y;
		cout << "Copy assignment called --> P(" << x << ',' << y << ")" << "\t with address --> 0x" << this << "\n\n";
		return *this;
	}

	~Point() { cout << "Destructor called --> P(" << x << ',' << y << ")" << "\t with address --> 0x" << this << "\n\n"; }

	friend Point operator+(const Point& A, const Point& B) {
		// try them respectively and see what's going on
		//return Point(A.x + B.x, A.y + B.y);
		Point C(A.x + B.x, A.y + B.y);
		return C;
	}

	friend ostream& operator<<(ostream& os, const Point& A) {
		os << "(" << A.x << ',' << A.y << ")";
		return os;
	}

private:
	int x, y;
};



int main()
{
	Point A(1, 2);
	Point B(8, 9);
	// try them respectively and see what's going on
	Point C;
	C = A + B;
	//Point C = A + B;
	cout << C << "\n\n";
	return 0;
}

