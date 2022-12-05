#include "Shape.h"
#include <iostream>
Shape::Shape(string name, string type):_name(name),_type(type)
{
}

Shape::~Shape()
{
	//nothing
}

string Shape::getType() const
{
	return _type;
}

string Shape::getName() const
{
	return _name;
}

void Shape::printDetails() const
{
	using std::cout;
	cout << "name of shape: " << _name << " type of shape: " << _type << " \n";
}
