#include "Rectangle.h"
#include <iostream>


myShapes::Rectangle::Rectangle(Point a, double length, double width, std::string type, std::string name):Polygon(type,name)
{
	//putting points in vec
	Point TopLeftCorner(a.getX() + length, a.getY()+width);
	Point BottomLeftCorner(a.getX() + length, a.getY());
	Point BottomRightCorner(a.getX(), a.getY()+width);
	_points.push_back(a);
	_points.push_back(BottomLeftCorner);
	_points.push_back(TopLeftCorner);
	_points.push_back(BottomRightCorner);
	
}

myShapes::Rectangle::~Rectangle()
{
	//
}

void myShapes::Rectangle::printDetails() const
{
	std::cout << "rectangle name: " << getName() << " rectangle type: " << getType();
	std::cout << " top right corner: " << _points[0].ToString();
	std::cout << " top left corner: " << _points[3].ToString();
	std::cout << " bottom left corner: " << _points[1].ToString();
	std::cout << " bottom right corner: " << _points[2].ToString() << "\n";
}

double myShapes::Rectangle::getArea() const
{
	double width = _points[0].getX()-_points[2].getX();
	double length = _points[0].getY() - _points[3].getY();
	return width*length;
}

double myShapes::Rectangle::getPerimeter() const
{
	double width = _points[2].getX()-_points[0].getX();
	double length = _points[3].getY()-_points[0].getY();
	return (width+length)*2;
}

void myShapes::Rectangle::move(Point other)
{
	for (Point& point:_points)
	{
		point += other;
	}
}

void myShapes::Rectangle::draw(const Canvas& canvas)
{
	canvas.draw_rectangle(_points[0], _points[2]);
}

void myShapes::Rectangle::clearDraw(const Canvas& canvas)
{
	canvas.clear_rectangle(_points[0], _points[2]);
}


