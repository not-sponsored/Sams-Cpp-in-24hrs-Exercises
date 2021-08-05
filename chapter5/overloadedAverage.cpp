/*********************************************************
*
* Answer to exercise 2 in chapter 5 
*
* Exercise from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int average(int numberOne, int numberTwo);
long average(long numberOne, long numberTwo);
float average(float numberOne, float numberTwo);

int main()
{
	int intOne = 10, intTwo = 20;
	cout << "Average of two ints " << intOne << " and " << intTwo << " is "
		<< average(intOne, intTwo) << endl;

	long longOne = 100, longTwo = 200;
	cout << "Average of two longs " << longOne << " and " << longTwo
		<< " is " << average(longOne, longTwo) << endl;

	float floatOne = 3.0, floatTwo = 2.0;
	cout << "Average two floats " << floatOne << " and " << floatTwo
		<< " is " << average(floatOne, floatTwo) << endl; 
	return 0;
}

int average(int numberOne, int numberTwo)
{
	return (numberOne + numberTwo) / 2;
}

long average(long numberOne, long numberTwo)
{
	return (numberOne + numberTwo) / 2;
}

float average(float numberOne, float numberTwo)
{
	return (numberOne + numberTwo) / 2;
}

