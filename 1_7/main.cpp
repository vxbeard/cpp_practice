#include<iostream>
#include<cstdlib>
using namespace std;

class Point {
private:
	int _x,_y;
public:
	Point(int x, int y) :_x(x), _y(y) {}
	int getX() const {return _x;}
	int getY() const {return _y;}
};

std::ostream& operator<<(std::ostream& out, const Point p) {
    out<<"("<<p.getX()<<","<<p.getY()<<")";
    return out;
}

class Polygon {
private:
	Point base;
	int len;
	int hgt;
public:
	Polygon(Point p, int length, int height) : base(p), len(length), hgt(height) {}
	Polygon(Point p1, Point p2) : base(p1) {
		len = abs(p2.getX() - p1.getX());
		hgt = abs(p2.getY() - p1.getY());
	}

	Point getP1() const {return base;}
	Point getP2() const {return Point(base.getX() + len, base.getY());}
	Point getP3() const {return Point(base.getX(), base.getY() + hgt);}
	Point getP4() const {return Point(base.getX() + len, base.getY() + hgt);}
};

std::ostream& operator<<(std::ostream& out, const Polygon poly) {
    out<<"("<<poly.getP1()<<", "<<poly.getP2()<<", "<<poly.getP3()<<", "<<poly.getP4()<<")";
    return out;
}

int main(void) {
	Point p(1,2);
	Polygon poly(p, 2, 3);

	cout<<"Point: "<<p.getX()<<","<<p.getY()<<endl;
	cout<<"Point: "<<p<<endl;
	cout<<"Polygon:"<<poly<<endl;

	return 0;
}
