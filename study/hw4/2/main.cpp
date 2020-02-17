#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	Point operator+(const Point& p)
	{
		return Point(x + p.x, y + p.y);
	}

	Point operator-(const Point& p)
	{
		return Point(x - p.x, y - p.y);
	}

	float operator[](const Point& p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}

	Point& operator++()
	{
		x++; y++;
		return *this;
	}

	Point& Print()
	{
		cout << '(' << x << ", " << y << ')' << endl;
		return *this;
	}
};

int main(void)
{
	Point p1(0, 1);
	Point p2(5, 5);

	(p1 + p2).Print();

	(p2 - p1).Print();

	++p1.Print();

	cout << "p1과 p2 사이의 거리 : " << p1[p2] << endl;
}
