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

	Polygon operator-(const Polygon & poly2) {
		// Calculating x coordinate
		int poly1X1 = this->getP1().getX();
		int poly1X2 = this->getP2().getX();

		int poly2X1 = poly2.getP1().getX();
		int poly2X2 = poly2.getP2().getX();

		int resX1 = poly1X1 > poly2X1 ? poly1X1 : poly2X1;
		int resX2 = poly1X2 < poly2X2 ? poly1X2 : poly2X2;

		if(resX2<resX1) {
			return Polygon(Point(0,0), 0, 0);
		}

		// Calculating y coordinate
		int poly1Y1 = this->getP1().getY();
		int poly1Y2 = this->getP2().getY();

		int poly2Y1 = poly2.getP1().getY();
		int poly2Y2 = poly2.getP2().getY();

		int resY1 = poly1X1 > poly2Y1 ? poly1Y1 : poly2Y1;
		int resY2 = poly1X2 < poly2Y2 ? poly1Y2 : poly2Y2;

		if(resY2<resY1) {
			return Polygon(Point(0,0), 0, 0);
		}

		return Polygon(Point(resX1, resY1), resX2 - resX1, resY2-resY1);
	}
};

std::ostream& operator<<(std::ostream& out, const Polygon poly) {
    out<<"("<<poly.getP1()<<", "<<poly.getP2()<<", "<<poly.getP3()<<", "<<poly.getP4()<<")";
    return out;
}

int main(void) {
	Point p(1,1);
	Polygon poly1(p, 4, 4);
	Polygon poly2(Point(2,3), 6, 6);

	cout<<"Point: "<<p.getX()<<","<<p.getY()<<endl;
	cout<<"Point: "<<p<<endl;
	cout<<"Polygon1:"<<poly1<<endl;
	cout<<"Polygon2:"<<poly2<<endl;

	Polygon poly3 = poly1-poly2;

	cout<<"Polygon3:"<<poly3<<endl;	

	return 0;
}



