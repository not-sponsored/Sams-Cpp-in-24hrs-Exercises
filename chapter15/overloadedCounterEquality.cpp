/*********************************************************
*
* Answer to exercise 1 in chapter 15 
*
* Modified 15.6 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::endl;

class Counter
{
public:
	Counter();
	Counter(int newValue);
	~Counter() {}
	int getValue() const { return value; }
	void setValue(int newValue) { value = newValue; }
	bool operator==(const Counter&);
private:
	int value; 
};

Counter::Counter():
value(0)
{}

Counter::Counter(int newValue):
value(newValue)
{}

bool Counter::operator==(const Counter &rhs)
{
	if (value == rhs.getValue())
	{
		return true;
	}
	return false;
} 

int main()
{
	int beta = 5;
	Counter alpha = beta;
	Counter zeta(5), gamma(6);

	cout << "alpha: " << alpha.getValue() << endl;
	cout << "zeta: " << zeta.getValue() << endl;
	cout << "gamma: " << gamma.getValue() << endl;

	cout << "testing alpha == zeta: " << (alpha == zeta) << endl;
	cout << "testing alpha == gamma: " << (alpha == gamma) << endl;

	return 0;
}
