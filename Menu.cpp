#include "Menu.h"
#include "Arrow.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <iostream>
#include <tuple>
using myShapes::Rectangle;
using std::cout;
using std::cin;
Menu::Menu() 
{
	_canvas = Canvas();
	_shapes = std::vector<Shape*>();
}

Menu::~Menu()
{
}

Point Menu::getPoint()
{
	double x = 0.0, y = 0.0;
	cout << "enter the x value of point: ";
	cin >> x;
	getchar();
	cout << "enter the y value of point: ";
	cin >> y;
	getchar();
	return Point(x, y);
}

void Menu::GetShape(std::string& type,std::string& name)
{
	std::string _name(""), _type("");
	cout << "enter shape's name: ";
	std::getline(cin, name);
	cout << "enter shape's type: ";
	std::getline(cin, type);
	name = _name;
	type = _type;
}

void Menu::addShape()
{
	int input = 0;
	Point a, b, c;
	double d1 = 0.0, d2 = 0.0;
	std::string name(""), type("");
	
	cout << "pick an option:\n" <<
		"1.arrow\n"<<
		"2.circle\n"<<
		"3.rectangle\n"<<
		"4.triangle\n: ";
	cin >> input;
	getchar();
	switch (input)
	{
	case 1:
		cout << "enter sourece of arrow:\n";
		a = getPoint();
		cout << "enter dest of arrow: \n";
		b = getPoint();
		GetShape(name,type);
		
		_shapes.push_back(new Arrow(a, b, type, name));
		break;
	case 2:
		cout << "enter center of circle:\n";
		a = getPoint();
		cout << "enter rad of circle:";
		cin >> d1;
		getchar();
		GetShape(name, type);
		_shapes.push_back(new Circle(a, d1, type, name));
		break;
	case 3:
		cout << "enter top left point of rectangle: \n";
		a = getPoint();
		cout << "enter length of rectangle: ";
		cin >> d1;
		getchar();
		cout << "enter witdh of rectangle: ";
		cin >> d2;
		getchar();
		GetShape(name, type);
		_shapes.push_back(new myShapes::Rectangle(a, d1, d2, type, name));
		break;
	case 4:
		cout << "enter first point of rectangle: \n";
		a = getPoint();
		cout << "enter second point of rectangle: \n";
		b = getPoint();
		cout << "enter third point of rectangle: \n";
		c = getPoint();
		GetShape(name, type);
		_shapes.push_back(new Triangle(a,b,c,type,name));
		break;
	default:
		throw("ERROR!!! option not found\n");
		break;
	}
	_shapes[_shapes.size() - 1]->draw(_canvas);//render new objects
}

void Menu::ShapePicker()
{
	int input = 0;
	for (size_t i = 0; i < _shapes.size(); i++)
	{
		
		cout << i + 1 << ". name: " << _shapes[i]->getName() << " type: " << _shapes[i]->getType()<<"\n";
	}
	cout << "enter shapes index: ";
	cin >> input;
	input--;//it is displayied as i+1 so user will enter i+1 so we need to get it down to i
	getchar();

	if (input<_shapes.size()&&input>=0)
	{
		if (changeShape(*_shapes[input]))
			_shapes.erase(_shapes.begin() + input);
	}
	else
	{
		throw("ERROR!!! index not found\n");
	}
}

bool Menu::changeShape(Shape& shape)
{
	int input = 0;
	Point movePoint;
	cout << "pick an option:\n" <<
		"1.move shape\n" <<
		"2.print shapes details \n" <<
		"3.delete shape \n";
	cin >> input;
	getchar();
	switch (input) 
	{
	case 1:
		cout << "enter point to move by:\n";
		movePoint = getPoint();
		shape.clearDraw(_canvas);
		shape.move(movePoint);
		shape.draw(_canvas);
		break;
	case 2:
		shape.printDetails();
		break;
	case 3:
		shape.clearDraw(_canvas);
		return true;
		break;
	default:
		throw("ERROR!!! option not found");
		break;
	}
	return false;
}

void Menu::RunMenu()
{
	int input = 0;
	do
	{
		cout << "pick an option:\n" <<
			"1.add shape\n" <<
			"2. edit shape\n" <<
			"3. clean canvas\n" <<
			"4. exit\n: ";
		try
		{
			cin >> input;
			getchar();
			switch (input)
			{
			case 1:
				addShape();
				break;
			case 2:
				ShapePicker();
				break;
			case 3:
				for (Shape* shape : _shapes)
				{
					shape->clearDraw(_canvas);
				}
				_shapes.clear();
				break;
			case 4:
				cout << "bye bye";
				break;
			default:
				throw("ERROR!!! option not found");
				break;
			}
		}
		catch (std::string err) {
			std::cerr << err << '\n';
		}
		catch (...)
		{
			std::cerr << "ERROR!!! is suck at coding";
			exit(1);
		}
	} while (input!=4);
}

