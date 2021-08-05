/*********************************************************
*
* Answer to exercise 1 in chapter 11 
*
* Modified 11.1 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

class SimpleCat
{
public:
	SimpleCat();
	~SimpleCat();
private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	cout << "constructor called\n";
	itsAge = 1;
}

SimpleCat::~SimpleCat()
{
	cout << "Destructor called\n";
}

int main()
{
	cout << "SimpleCat Frisky ...\n";
	SimpleCat Frisky;
	
	cout << "Created Spooky ...\n"; 
	SimpleCat Spooky;                                 // added Spooky
	
	cout << "SimpleCat *pRags = new SimpleCat ...\n";
	SimpleCat *pRags = new SimpleCat;

	cout << "delete pRags ...\n";
	delete pRags;
	pRags = nullptr;

	cout << "Exiting, watch Frisky and Spooky go ...\n";
	return 0;
}
