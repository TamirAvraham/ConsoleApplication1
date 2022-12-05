#include "Point.h"
#include <iostream>
Point::Point():_x(0),_y(0)
{
}

Point::Point(double x, double y):_x(x),_y(y)
{
}

Point::~Point()
{
    //nothing here yet
}

Point Point::operator+(const Point& other) const
{
    double x = _x + other._x;
    double y = _y + other._y;
    return Point(x,y);
}

Point& Point::operator+=(const Point& other)
{
    _x += other._x;
    _y += other._y;
    return *this;
}

double Point::getX() const
{
    return _x;
}

double Point::getY() const
{
    return _y;
}

double Point::distance(Point& other) const
{
    return std::sqrt(std::pow(_x - other._x,2)+std::pow((_y-other._y),2));
}
