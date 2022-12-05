#include "Arrow.h"
#include <iostream>
Arrow::Arrow(Point a, Point b, std::string type, std::string name):Shape(name,type),_source(a),_destination(b)
{
	if (a.getX()==b.getY()&&b.getY())
	{

	}
}

Arrow::~Arrow()
{
	//nothing else
}

Point Arrow::getSource() const
{
	return _source;
}

Point Arrow::getDestination() const
{
	return _destination;
}

void Arrow::printDetails() const 
{
	using std::string;
	using std::cout;

	cout << "name of arraow: " << getName() << " type of arrow is: " << getType() << " source of arrow: (" << _source.getX() << "," << _source.getY() << ") destination of arrow is: (" << _destination.getX() << "," << _destination.getY() << ") \n";
	
}

double Arrow::getArea()
{
	return 0;
}

double Arrow::getPerimeter()
{
	return _source.distance(_destination);
}

void Arrow::move(Point other)
{
	_source += other;
	_destination += other;
}

void Arrow::draw(const Canvas& canvas)
{
	canvas.draw_arrow(_source, _destination);
}
void Arrow::clearDraw(const Canvas& canvas)
{
	canvas.clear_arrow(_source, _destination);
}


