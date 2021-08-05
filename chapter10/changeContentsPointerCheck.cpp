/*********************************************************
*
* Answer to exercise 2 in chapter 10 
*
* Modified from 10.3 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
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

	// change the contents of yourAge with dereferenced pAge
	*pAge = 70;
	cout << "Dereferenced pAge and changed yourAge to 70\n";
	cout << "*pAge:   " << *pAge << "\n"; 
	cout << "yourAge: " << yourAge << "\n";

	return 0;
}

