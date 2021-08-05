/*********************************************************
*
* Answer to exercise 2 in chapter 12 
*
* Modified 12.6 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void swap(int &, int &, int &);

int main()
{
	int valueOne = 1, valueTwo = 2, valueThree = 3;

	cout << "Main. Before swap, valueOne: " << valueOne
		<< " valueTwo: " << valueTwo
		<< " valueThree: " << valueThree << endl;
	swap(valueOne, valueTwo, valueThree);	
	cout << "Main. After swap, valueOne: " << valueOne
		<< " valueTwo: " << valueTwo
		<< " valueThree: " << valueThree << endl;

	return 0;
}

void swap(int &rValueOne, int &rValueTwo, int &rValueThree)
{
	int temp = rValueThree;

	cout << "Swap. before with rValueOne: " << rValueOne
		<< " rValueTwo: " << rValueTwo
		<< " rValueThree: " << rValueThree << endl;

	rValueThree = rValueOne;
	rValueOne = rValueTwo;
	rValueTwo = temp;

	cout << "Swap. after with rValueOne: " << rValueOne
		<< " rValueTwo: " << rValueTwo
		<< " rValueThree: " << rValueThree << endl;
}

