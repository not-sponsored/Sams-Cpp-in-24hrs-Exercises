/*********************************************************
*
* Answer to exercise 2 in chapter 9 
*
* Exercise from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include "separatePoint.hpp"
#include <cmath>
using std::cout;

class Line
{
public:
	Line() {}
	Line(Point left, Point right) { leftPoint = left; rightPoint = right; }
	Line(int leftX, int leftY, int rightX, int rightY);
	~Line() {}
	
	// setter functions overloaded
	void setLeft(Point left) { leftPoint = left; }
	void setLeft(int newX, int newY);

	void setRight(Point right) { rightPoint = right; }
	void setRight(int newX, int newY);

	// accessor functions
	Point getLeft() const { return leftPoint; }
	Point getRight() const { return rightPoint; }
	double getDistance() const; 

private:
	Point leftPoint;
	Point rightPoint;	
};

Line::Line(int leftX, int leftY, int rightX, int rightY)
{
	setLeft(leftX, leftY);
	setRight(rightX, rightY);
}

void Line::setLeft(int newX, int newY)
{
	leftPoint.setX(newX);
	leftPoint.setY(newY);
}

void Line::setRight(int newX, int newY)
{
	rightPoint.setX(newX);
	rightPoint.setY(newY);
}

double Line::getDistance() const
{
	int differenceInX = rightPoint.getX() - leftPoint.getX();
	int differenceInY = rightPoint.getY() - leftPoint.getY();
	return std::sqrt(differenceInX * differenceInX +
			 differenceInY * differenceInY);
}

int main()
{
	Line testLine(0, 0, 2, 2);
	Point leftPoint;
	leftPoint.setX(-1);
	leftPoint.setY(-1);
	testLine.setLeft(leftPoint);
	testLine.setRight(3, 3);

	cout << "Left Point (" << testLine.getLeft().getX() << ", "
		<< testLine.getLeft().getY() << ")\n";
	cout << "Right Point (" << testLine.getRight().getX() << ", "
		<< testLine.getRight().getY() << ")\n";

	cout << "Distance between the two points: " << testLine.getDistance()
		<< "\n";
	return 0;
}
