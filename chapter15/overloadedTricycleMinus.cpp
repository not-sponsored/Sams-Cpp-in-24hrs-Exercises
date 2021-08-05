/*********************************************************
*
* Answer to exercise 2 in chapter 15 
*
* Modified 15.5 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::endl;

class Tricycle
{
public:
	Tricycle();
	Tricycle(int newSpeed); 
	
	// added destructor and copy constructor
	~Tricycle();
	Tricycle(const Tricycle&);

	int getSpeed() const { return *speed; }
	void setSpeed(int newSpeed) { *speed = newSpeed; }
	Tricycle operator=(const Tricycle&);
	
	// added overloaded minus
	Tricycle operator-(const Tricycle&);

private:
	int *speed;
};

Tricycle::Tricycle()
{
	speed = new int;
	*speed = 5;
}

Tricycle::Tricycle(int newSpeed)
{
	speed = new int;
	*speed = newSpeed;
}

Tricycle::~Tricycle()
{
	delete speed;
}

Tricycle::Tricycle(const Tricycle& rhs)
{
	speed = new int;
	*speed = rhs.getSpeed();
}

Tricycle Tricycle::operator=(const Tricycle& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}
	delete speed;
	speed = new int;
	*speed = rhs.getSpeed();
	return *this;
}

Tricycle Tricycle::operator-(const Tricycle& rhs)
{
	if (*speed - rhs.getSpeed() > 0)  // prevent negative speeds
	{
		return Tricycle(*speed - rhs.getSpeed());
	}
	return Tricycle(0);
}

int main()
{
	int beta = 5;
	Tricycle alpha = beta;
	Tricycle zeta(6);

	// test minus operator
	Tricycle gamma = alpha - zeta;
	Tricycle epsilon = alpha - alpha;
	Tricycle eta = zeta - alpha;

	cout << "alpha speed: " << alpha.getSpeed() << endl;
	cout << "zeta speed: " << zeta.getSpeed() << endl << endl;
	cout << "gamma = alpha - zeta" << endl;
	cout << "gamma speed: " << gamma.getSpeed() << endl << endl;
	cout << "epsilon = alpha - alpha" << endl;
	cout << "epsilon speed: " << epsilon.getSpeed() << endl << endl;
	cout << "eta = zeta - alpha" << endl;
	cout << "eta speed: " << eta.getSpeed() << endl;

	return 0;
}
