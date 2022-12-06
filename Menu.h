#pragma once
#include "Shape.h"
#include "Canvas.h"
#include <vector>

class Menu
{
public:

	Menu();
	~Menu();

	// more functions..
	Point getPoint();
	void GetShape(std::string& type, std::string& name);
	void addShape();
	void ShapePicker();
	bool changeShape(Shape& shape);
	void RunMenu();

private: 
	Canvas _canvas;
	std::vector<Shape> _shapes;
};

