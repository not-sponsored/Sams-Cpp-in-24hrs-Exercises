/*********************************************************
*
* Part of the answer to exercise 2 in chapter 13
*
* Modified 13.3 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::endl;

class SimpleCat
{
public:
	SimpleCat();
	SimpleCat(SimpleCat&);
	~SimpleCat();

	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};

SimpleCat::SimpleCat()
{
	cout << "constructor ..." << endl;
	itsAge = 1;
}

SimpleCat::SimpleCat(SimpleCat&)
{
	cout << "copy constructor ..." << endl;
}

SimpleCat::~SimpleCat()
{
	cout << "destructor ..." << endl;
}

const SimpleCat & FunctionTwo(const SimpleCat & theCat);

int main()
{
	cout << "Making a cat ..." << endl;
	SimpleCat Frisky;
	cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
	int age = 5;
	Frisky.SetAge(age);
	cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
	cout << "Frisky before: " << &Frisky << endl;
	cout << "calling FunctionTwo ..." << endl;
	FunctionTwo(Frisky);
	cout << "Frisky after: " << &Frisky << endl;
	cout << "Frisky is " << Frisky.GetAge() << " years old" << endl;
	return 0;
}

// functionTwo passes ref to constant object
const SimpleCat & FunctionTwo (const SimpleCat & theCat)
{
	cout << "Inside FunctionTwo\n";
	cout << "Frisky is " << theCat.GetAge() << " years old" << endl;
	cout << "&theCat: " << &theCat << endl;
	cout << "Function two. returning..." << endl;
        // theCat.SetAge(8);  cannot because const
	return theCat;
}
