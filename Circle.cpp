#include "Circle.h"
#include <iostream>

Circle::Circle(Point center, double radius, std::string type, std::string name):Shape(name,type),_radius(radius),_center(center)
{
}

Circle::~Circle()
{
	//UWU No code hereee sry UwU
}

Point Circle::getCenter() const
{
	return _center;
}

double Circle::getRadius() const
{
	return _radius;
}

void Circle::printDetails() const
{
	std::cout << "name of the circle: " << getName() << " type of circle: " << getType() << " center: " << _center.ToString() << " circle rad : " << _radius << " \n";
}

double Circle::getArea() const
{
	return PI*std::pow(_radius,2);
}

double Circle::getPerimeter() const
{
	return 2*PI*_radius;
}

void Circle::move(Point other)
{
	_center += other;
}

void Circle::draw(const Canvas& canvas)
{
	canvas.draw_circle(getCenter(), getRadius());
}

void Circle::clearDraw(const Canvas& canvas)
{
	canvas.clear_circle(getCenter(), getRadius());
}


