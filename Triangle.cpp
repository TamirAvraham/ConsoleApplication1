#include "Triangle.h"
#include <iostream>
Triangle::Triangle(Point a, Point b, Point c, std::string type, std::string name):Polygon(type,name)
{
	if ((a.getX()==b.getX()&& b.getX() == c.getX()) || (a.getY() == b.getY()&&b.getY() == c.getY()))
	{
		std::cerr << "all points are on the same plane\n";
		exit(1);
	}
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
}

Triangle::~Triangle()
{
}

void Triangle::printDetails() const
{

}

double Triangle::getArea() const
{
	double a = _points[0].distance(_points[1]);
	double b = _points[0].distance(_points[2]);
	double c = _points[1].distance(_points[2]);
	double topHalf = (a + b + c)*(a + b - c)*(b + c - a)*(c + a - b);//haron formula
	return sqrt(topHalf)/4;
}

double Triangle::getPerimeter() const
{
	double a = _points[0].distance(_points[1]);
	double b = _points[0].distance(_points[2]);
	double c = _points[1].distance(_points[2]);
	return a+b+c;
}

void Triangle::move(Point other)
{
	for (Point& point : _points)
	{
		point += other;
	}
}


	

void Triangle::draw(const Canvas& canvas)
{
	canvas.draw_triangle(_points[0], _points[1], _points[2]);
}

void Triangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_triangle(_points[0], _points[1], _points[2]);
}
