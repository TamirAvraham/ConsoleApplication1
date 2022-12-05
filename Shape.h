#pragma once
#include "Point.h"
#include "Canvas.h"
#include <string>
using std::string;
class Shape 
{
public:

	// Constructor
	Shape(string name, string type);

	// Destructor
	~Shape();

	// Getters
	string getType()const;
	string getName()const;

	// Methods
	 
	virtual void printDetails() const;

	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual void move(Point other) = 0;
	virtual void draw(const Canvas& canvas) = 0;
	virtual void clearDraw(const Canvas& canvas) = 0;

private:
	string _name;
	string _type;
};