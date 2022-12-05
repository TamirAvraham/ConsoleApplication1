#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:

	// Constructor
	Circle(Point center, double radius, std::string type, std::string name);

	// Destructor
	virtual ~Circle();

	// Getters
	Point getCenter()const;
	double getRadius()const;

	// Methods
	void printDetails() const override;
	double getArea()override;
	double getPerimeter()override;
	
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	// add fields
	// override functions if need (virtual + pure virtual)
private:
	double _radius;
	Point _center;
};