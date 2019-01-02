#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Shape
{
public:
	virtual ~Shape() { }
	virtual double getArea() = 0;
	virtual double getPerimeter() = 0;
	virtual string getType() = 0;
};

class RightTriangle : public Shape
{
public:
	RightTriangle(double b, double h) : _b(b), _h(h) { }
	~RightTriangle() { }
	double getArea() { return 0.5*_b*_h; }
	double getPerimeter() { return sqrt(_b*_b + _h * _h) + _h + _b; }
	string getType() { return "Right Triangle"; }
private:
	double _b, _h;
};

class rectangle : public Shape
{
private:
	double length, width;
public:
	rectangle(double l, double b)
	{
		length = l;
		width = b;
    }
	~rectangle(){ }
	double getArea() { return length * width; }
	double getPerimeter() { return 2 * (length + width); }
	string getType() { return "Rectangle"; }
};

class square : public Shape
{
private:
	double length;
public:
	square(double l)
	{
		length = l;
	}
	~square() { }
	double getArea() { return length * length; }
	double getPerimeter() { return 2 * (length + length); }
	string getType() { return "Square"; }
};

class circle : public Shape
{
private:
	double radius;
public:
	circle(double r)
	{
		radius=r;
	}
	~circle() { }
	double getArea() { return (22/7)*(radius*radius); }
	double getPerimeter() { return 2 * (22/7)*radius; }
	string getType() { return "Circle"; }
};

int main()
{
	vector<Shape *> shapeList;

	int selection = -1;
	while (selection != 0) {
		cout << "Choose an option:" << endl;
		cout << "=================" << endl;
		cout << "Enter '0' to quit" << endl;
		cout << "Enter '1 base height' for a right triangle with given base and height" << endl;
		cout << "Enter '2 base height' for a rectangle with given base and height" << endl;
		cout << "Enter '3 side' for a square with given side length" << endl;
		cout << "Enter '4 radius' for a circle with given radius" << endl;
		cout << "> ";
		cin >> selection;
		// Right Triangle case
		if (selection == 1) {
			double b, h;
			cin >> b >> h;
			shapeList.push_back(new RightTriangle(b, h));
		}
		// Rectangle case
		else if (selection == 2) {
			double b, h;
			cin >> b >> h;
			shapeList.push_back(new rectangle(b, h));
			// Add the rest of the code to allocate a new rectangle
			//  and add it to the shapeList

		}
		// Square case
		else if (selection == 3) {
			double s;
			cin >> s;
			shapeList.push_back(new square(s));
			// Add the rest of the code to allocate a new square
			//  and add it to the shapeList

		}
		else if (selection == 4) {
			double r;
			cin >> r;
			shapeList.push_back(new circle(r));
			
		}

	}

	for (vector<Shape *>::iterator it = shapeList.begin();
		it != shapeList.end();
		++it)
	{
		Shape *s = *it;
		cout << s->getType() << ": Area=" << s->getArea() << " Perim=" << s->getPerimeter() << endl;
		delete s;
	}
	system("pause");
	return 0;
}