#include<iostream>
#include<cstdlib.h>
using namespace std;

class Point {
private:
	int _x,_y;
public:
	Point(int x, int y) :_x(x), _y(y) {}
	int getX() {return _x;}
	int getY() {return _y;}
};

class Polygon {
private:
	Point base;
	int len;
	int hgt;
public:
	Polygon(Point p, int lenght, int height) : base(p), len(length), hgt(height) {}
	Polygon(Point p1, Point p2) {
		base = p1;
		len = abs(p2.getX() - p1.getX());
		hgt = abs(p2.getY() - p1.getY());
	}
}

int main(void) {
	Point p(1,2);
	Polygon(p, 2, 3);

	cout<<"Point: "<<p.getX()<<","<<p.getY()<<endl;

	return 0;
}
