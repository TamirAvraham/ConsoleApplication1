#pragma once
#include "Shape.h"

class Arrow : public Shape
{
public:

	// Constructor
	Arrow(Point a, Point b, std::string type, std::string name);

	// Destructor
	~Arrow();

	// Getters
	Point getSource()const;
	Point getDestination()const;

	// Methods
	void printDetails() const override;
	double getArea()override;
	double getPerimeter()override;
	void move(Point other)override;
	void draw(const Canvas& canvas) override;
	void clearDraw(const Canvas& canvas) override;

	// override functions if need (virtual + pure virtual)

private:
	Point _source;
	Point _destination;
};