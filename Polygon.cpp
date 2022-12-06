#include "Polygon.h"

Polygon::Polygon(std::string type, std::string name):Shape(name,type)
{
}

Polygon::~Polygon()
{
    // UwU UwU UwU UwU UwU UwU? UwU... UwU
}

std::vector<Point> Polygon::getPoints() const
{
    return _points;
}
