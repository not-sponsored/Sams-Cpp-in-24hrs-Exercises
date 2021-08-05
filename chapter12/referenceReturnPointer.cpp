/*********************************************************
*
* Answer to exercise 1 in chapter 12 
*
* Modified 12.7 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

int factor(int, int&, int&);

int main()
{
	int number, squared, cubed;
	int error;
	
	cout << "Enter a number (0 - 20): ";
	std::cin >> number;

	error = factor(number, squared, cubed);

	if (!error)
	{
		cout << "number: " << number << "\n";
		cout << "squared: " << squared << "\n";
		cout << "cubed: " << cubed << "\n";
	}
	else
		cout << "Error!" << "\n";
	return 0;
}

int factor(int number, int &rSquared, int &rCubed)
{
	int value = 0;
	if (number > 20)
	{
		value = 1;
	}
	else
	{
		rSquared = number * number;
		rCubed = number * number * number;
		value = 0;
	}
	return value;
}
