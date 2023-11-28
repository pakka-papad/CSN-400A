#ifndef POINT_CPP
#define POINT_CPP

#include <assert.h>

class Point {
	public:
	int x, y;
	Point(int x, int y): x(x), y(y) {

	}

	bool operator==(const Point &other) const {
		return (this->x == other.x && this->y == other.y);
	}

	bool operator<(const Point &other) const {
		return (this->x < other.x || (this->x == other.x && this->y < other.y));
	}

};


Point reflectR(int n, int m, const Point &p){
    return Point(n - 1 - p.x, p.y);
}

Point reflectC(int n, int m, const Point &p){
    return Point(p.x, m - 1 - p.y);
}

Point reflectD1(int n, int m, const Point &p){
    assert(n == m);
    return Point(p.y, p.x);
}

Point reflectD2(int n, int m, const Point &p){
    assert(n == m);
    return Point(n - 1 - p.y, m - 1 - p.x);
}

#endif