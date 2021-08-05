/*********************************************************
*
* Answer to exercise 1 in chapter 4 
*
* Modified 4.4 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* The bug happens because the other if statements evaluate to true.
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

int main()
{
	int grade;
	cout << "Enter a grade (1-100): ";
	cin >> grade;
	
	if (grade >= 70)
	{
		if (grade >= 90)
		{
			cout << "\nYou got an A. Great job!\n";
			// return 0;
		}
		if (grade >= 80)
		{
			cout << "\nYou got a B. Good work!\n";
			// return 0;
		}
		cout << "\nYou got a C. Perfectly adequate!\n";
	}
	else
		cout << "\nYou got an F. I failed as a parent!\n";
	return 0;
}
