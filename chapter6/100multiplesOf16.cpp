/*********************************************************
*
* Answer to exercise 1 in chapter 6 
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

int main()
{
	int i = 1;            // from 1 for first multiple 
	const int base = 16; 
	for (i; i < 101; i++) // go up to 101 for 100 multiples
		cout << "Multiple " << i << " is " << i * base << "\n";
	return 0;
} 
