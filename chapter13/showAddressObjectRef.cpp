/*********************************************************
*
* Part of the answer to exercise 2 in chapter 13 
*
* Modified 13.1 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
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
	SimpleCat(SimpleCat&);
	~SimpleCat();
};

SimpleCat::SimpleCat()
{
	cout << "Simple Cat Constructor ..." << std::endl;
}

SimpleCat::SimpleCat(SimpleCat&)
{
	cout << "Simple Cat Copy Constructor ..." << std::endl;
}

SimpleCat::~SimpleCat()
{
	cout << "Simple Cat Destructor ..." << std::endl;
}

SimpleCat FunctionOne(SimpleCat theCat);
SimpleCat* FunctionTwo(SimpleCat *theCat);

int main()
{
	cout << "making cat ..." << std::endl;
	SimpleCat Frisky;
	cout << "Frisky before: " << &Frisky << std::endl;
	cout << "Calling FunctionOne ..." << std::endl;
	FunctionOne(Frisky);
	cout << "Frisky after FunctionOne: " << &Frisky << std::endl;
	cout << "Calling FunctionTwo ..." << std::endl;
	FunctionTwo(&Frisky);
	cout << "Frisky after FunctionTwo: " << &Frisky << std::endl;
	return 0;
}

// pass by value
SimpleCat FunctionOne(SimpleCat theCat)
{
	cout << "&theCat: " << &theCat << std::endl;
	cout << "Function One. Returning ..." << std::endl;
	return theCat;
}

// pass by reference
SimpleCat *FunctionTwo(SimpleCat *pTheCat)
{
	cout << "pTheCat: " << pTheCat << std::endl;
	cout << "Function two. returning ..." << std::endl;
	return pTheCat;
}
