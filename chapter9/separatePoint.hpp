/*********************************************************
*
* Part of the answer to exercise 1 and 2 in chapter 9 
*
* Modified 9.3 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>

class Point
{
public:
	// no constructor, use default
	void setX(int newX) { x = newX; }
	void setY(int newY) { y = newY; }
	int getX() const { return x; }
	int getY() const { return y; }
private:
	int x;
	int y;
};

