#include "std_lib_facilities.h"
#define pi 3.14
class Shape {
protected:
	string name;
public:
	Shape(string newname) {
		name = newname;
	}
	virtual double getArea() = 0;
	virtual string getName() = 0;
	virtual double getValue() = 0;
	virtual string getKind() = 0;
};

class TwoDimensionalShape:public Shape{
public:
	TwoDimensionalShape(string newname) :Shape(newname) {}
	virtual double getArea() = 0;
	virtual string getName() = 0;
	virtual double getValue() = 0;
	virtual string getKind() = 0;
};

class Circle :public TwoDimensionalShape {
	double r;
public:
	Circle(string newname,double newr) :TwoDimensionalShape(newname){
		r = newr;
	}
	virtual double getArea() {
		return pi*(r*r);
	}
	virtual string getName() {
		return name;
	}
	virtual double getValue() {
		return r;
	}
	virtual string getKind() {
		return "Circle";
	}
};

class Square :public TwoDimensionalShape {
	double a;
public:
	Square(string newname,double newa):TwoDimensionalShape(newname) {
		a = newa;
		
	}
	virtual double getArea() {
		return a*a;
	}
	virtual string getName() {
		return name;
	}
	double getValue() {
		return a;
	}
	virtual string getKind() {
		return "Square";
	}
};


int main() {
	vector<Shape*> shapes;
	Shape* p0 = new Circle("Circle1", 1.8);
	Shape* p1 = new Square("Square1", 3.6);
	Shape* p2 = new Circle("Circle2", 2.2);
	Shape* p3 = new Square("Square2", 6.7);
	Shape* p4 = new Circle("Circle3", 3.5);
	Shape* p5 = new Square("Square3", 9.2);
	Shape* p6 = new Circle("Circle4", 4.6);
	Shape* p7 = new Square("Square4", 10.2);
	Shape* p8 = new Circle("Circle5", 5.0);
	Shape* p9 = new Square("Square5", 12.1);
	shapes.push_back(p0);
	shapes.push_back(p1);
	shapes.push_back(p2);
	shapes.push_back(p3);
	shapes.push_back(p4);
	shapes.push_back(p5);
	shapes.push_back(p6);
	shapes.push_back(p7);
	shapes.push_back(p8);
	shapes.push_back(p9);
	cout <<"Kind of Shape:" << "\t\t" << "Name of Shape:" << "\t\t" << "Radius/side:"<< "\t" <<"Area is:" << endl;
	for (int i = 0; i < shapes.size(); i++) {
		cout <<shapes[i]->getKind()<< "\t\t\t" <<shapes[i]->getName() << "\t\t\t" << shapes[i]->getValue() << "\t\t" << shapes[i]->getArea() << endl;
	}
	keep_window_open();
}