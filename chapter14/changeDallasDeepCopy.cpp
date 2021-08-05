/*********************************************************
*
* Answer to exercise 2 in chapter 14 
*
* Modified from 14.3 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* A change in dallas does not affect wichita.
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

class Tricycle
{
public:
	Tricycle();
	Tricycle(const Tricycle&); // copy
	~Tricycle();
	int getSpeed() const { return *speed; }
	void setSpeed(int newSpeed) { *speed = newSpeed; }
	void pedal();
	void brake();
private:
	int *speed; 
};

Tricycle::Tricycle()
{
	speed = new int;
	*speed = 5;
}

Tricycle::Tricycle(const Tricycle &rhs)
{
	speed = new int;
	*speed = rhs.getSpeed();
}

Tricycle::~Tricycle()
{
	delete speed;
	speed = nullptr;
}

void Tricycle::pedal()
{
	setSpeed(*speed + 1);
	cout << "\nPedaling " << getSpeed() << std::endl;
}

void Tricycle::brake()
{
	setSpeed(*speed - 1);
	cout << "\nBraking" << getSpeed() << std::endl;
}

int main()
{
	cout << "Creating wichita ...";
	Tricycle wichita;
	wichita.pedal();
	cout << "\n";

	cout << "Creating dallas...\n";
	Tricycle dallas(wichita);
	cout << "wichita's speed: " << wichita.getSpeed() << "\n";
	cout << "dallas's speed: " << dallas.getSpeed() << "\n\n";

	cout << "Set wichita to 10\n";
	wichita.setSpeed(10);
	cout << "wichita's speed: " << wichita.getSpeed() << "\n";
	cout << "dallas's speed: " << dallas.getSpeed() << "\n\n";

	cout << "Set dallas to 8\n";
	dallas.setSpeed(8);             // does not affect wichita
	cout << "wichita's speed: " << wichita.getSpeed() << "\n";
	cout << "dallas's speed: " << dallas.getSpeed() << "\n";

	return 0;
}
