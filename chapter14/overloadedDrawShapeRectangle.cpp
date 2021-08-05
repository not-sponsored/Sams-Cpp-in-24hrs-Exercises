/*********************************************************
*
* Answer to exercise 1 in chapter 14 
*
* Modified from 14.1 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

class Rectangle
{
public:
	Rectangle(int width, int height);
	~Rectangle() {}
	void drawShape() const;
	// no default values allowed to avoid ambiguous calls
	void drawShape(int width, int height) const; 
private:
	int width;
	int height;
};

Rectangle::Rectangle(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;
}

void Rectangle::drawShape() const
{
	drawShape(width, height);
}

void Rectangle::drawShape(int width, int height) const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			cout << "*";
		cout << "\n";
	}
}

int main()
{
	cout << "Created box with 30 width and 5 height\n";
	Rectangle box(30, 5);

	cout << "drawShape():" << "\n";
	box.drawShape();
	cout << "\n";

	cout << "calling drawShape(40, 2); still 30 width and 5 height\n";
	box.drawShape(40, 2);
	cout << "\n";
	
	cout << "drawShape() shows original measurements unchanged\n";
	box.drawShape();

	return 0;
} 
