/*********************************************************
*
* Answer to exercise 1 in chapter 10 
*
* Modified from 10.3 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
* 
* The compiler can tell the difference because the dereferencing operation has
* a higher order of operation thus *pAge is already an int value before the
* the multiplication ever takes place. Also, the compiler will throw an error
* if yourAge * pAge because the types don't match.
* 
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

int main()
{
	unsigned short int myAge = 5, yourAge = 10;
	unsigned short int *pAge = &myAge;           // pointer

	cout << "myAge:\t" << myAge;
	cout << "\t\tyourAge:\t" << yourAge << "\n";
	cout << "&myAge:\t" << &myAge;
	cout << "\t&yourAge:\t" << &yourAge << "\n";

	cout << "pAge:\t" << pAge << "\n";
	cout << "*pAge:\t" << *pAge << "\n\n";

	pAge = &yourAge;                             // reassign the pointer

	cout << "myAge:\t" << myAge;
	cout << "\t\tyourAge:\t" << yourAge << "\n";
	cout << "&myAge:\t" << &myAge;
	cout << "\t&yourAge:\t" << &yourAge << "\n";

	cout << "pAge:\t" << pAge << "\n";
	cout << "*pAge:\t" << *pAge << "\n";
	cout << "&pAge:\t" << &pAge << "\n\n";

	// multiply yourAge and *pAge
	int multiplication = yourAge * *pAge;
	// int testMultiplication = yourAge * pAge;  // doesn't work
	cout << "yourAge * *pAge: " << multiplication << "\n";

	return 0;
}

