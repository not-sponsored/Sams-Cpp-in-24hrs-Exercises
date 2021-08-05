/*********************************************************
*
* Answer to exercise 2 in chapter 6 
*
* Modified from 6.7 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
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
	char grade;
	cout << "What grade did you get including (E, G, H)? ";
	cin >> grade;

	switch (grade)
	{
	case 'A':
		cout << "Finally\n";
		break;
	case 'B':
		cout << "You can do better!\n";
		break;
	case 'C':
		cout << "I'm disappointed in you!\n";
		break;
	case 'D':
		cout << "You're not smart!\n";
		break;
	case 'F':
		cout << "Get out of my sight!\n";
		break;
	case 'E':
		cout << "An E? That's not a real grade.\n";
		break;
	case 'G':
		cout << "You should repeat a year.\n";
		break;
	case 'H':
		cout << "Go back to kindergarten.\n";
		break;
	default:
		cout << "Not a choice out of the selections.\n";
		break;
	}
	return 0;
}	
