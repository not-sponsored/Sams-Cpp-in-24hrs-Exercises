/*********************************************************
*
* Answer to exercise 1 in chapter 7 
*
* Exercise from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
#include <string>     // technically included in <iostream> but good practice
using std::cout;
using std::cin;
using std::string;

int main()
{
	string firstName, lastName;

	cout << "Enter your first name: ";
	std::getline(cin, firstName);
	cout << "Enter your last name: ";
	std::getline(cin, lastName);
	
	cout << "\nHello " << firstName << " " << lastName << std::endl;
	return 0;
} 
