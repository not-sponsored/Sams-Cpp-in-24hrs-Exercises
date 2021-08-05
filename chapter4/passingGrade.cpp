/*********************************************************
*
* Answer to exercise 2 in chapter 4 
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
	int grade, passingGrade;
	cout << "What did you score out of 100? ";
	cin >> grade;

	cout << "What is a passing grade? ";
	cin >> passingGrade;	

	bool passing = (grade >= passingGrade) ? true : false;
	if (passing)
	{
		cout << "You passed" << std::endl;
	}
	else
	{
		cout << "You failed" << std::endl;
	}
	return 0;
}
