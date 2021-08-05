/*********************************************************
*
* Answer to exercise 2 in chapter 11 
*
* Modified 11.2 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
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
	SimpleCat() { itsAge = 2; }
	~SimpleCat() {}
	int GetAge() const { return itsAge; }
	void SetAge(int age) { itsAge = age; }
private:
	int itsAge;
};

int main()
{
	SimpleCat *Frisky = new SimpleCat;

	// modified to use dereference and dot operator
	cout << "Frisky is " << (*Frisky).GetAge() << " years old" << "\n";
	(*Frisky).SetAge(5);
	cout << "Frisky is " << (*Frisky).GetAge() << " years old" << "\n";

	delete Frisky;
	Frisky = nullptr;

	return 0;
}
