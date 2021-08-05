/*********************************************************
*
* Answer to exercise 2 in chapter 8 
*
* Modified 8.2 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

class Tricycle
{
public:
	Tricycle(int initialSpeed, int wheelSize);
	Tricycle();
	~Tricycle();
	int getSpeed();
	int getWheelSize();
	void setSpeed(int newSpeed);
	void setWheelSize(int newWheel);
	void pedal();
	void brake();
private:
	int speed;
	int wheelSize; // size in inches
};   // need a semicolon

// constructor
Tricycle::Tricycle(int initialSpeed, int wheelSize)
{
	setSpeed(initialSpeed);
	setWheelSize(wheelSize);
}

// default
Tricycle::Tricycle()
{
	setSpeed(0);
	setWheelSize(4);
}

// destructor
Tricycle::~Tricycle()
{
	// do nothing
}

int Tricycle::getSpeed()
{
	return speed;
}

int Tricycle::getWheelSize()
{
	return wheelSize;
}

void Tricycle::setSpeed(int newSpeed)
{
	if (newSpeed >= 0)
	{
		speed = newSpeed;
	}
}

void Tricycle::setWheelSize(int newWheel)
{
	if (newWheel >= 4)
	{
		wheelSize = newWheel;
	}
	else                               // defaults to 4 inches
	{
		wheelSize = 4;
	}
}

void Tricycle::pedal()
{
	setSpeed(speed + 1);
	cout << "\nPedaling at " << speed << " mph";
}

void Tricycle::brake()
{
	setSpeed(speed - 1);
	cout << "\nBrake at " << speed << " mph";
}

int main()
{
	Tricycle trikeOne(3, 2); // test 2 wheelSize defaults to 4

	cout << "Tricycle One:\n";
	cout << "Wheel size of " << trikeOne.getWheelSize() << " inches";
	trikeOne.pedal();
	trikeOne.brake();
	cout << "\n";

	return 0;
} 

