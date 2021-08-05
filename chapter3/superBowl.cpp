/*********************************************************
*
* Answer to exercise 1 in chapter 3 
*
* Exercise from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*
* I didn't look up any teams, so I just named the two teams team 1 and 2.  
* 
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>

int main()
{
	const int TOUCH_DOWN = 6;
	const int FIELD_GOAL = 3;
	const int EXTRA_POINT = 1;
	const int TWO_POINT = 2;
	const int SAFETY = 2;

	std::cout << "---Team 1 scored---"
		<< "\nTouch down points: " << TOUCH_DOWN 
		<< "\nField Goal points: " << FIELD_GOAL  
		<< "\nExtra points: " << EXTRA_POINT
		<< std::endl;
	std::cout << "Team 1 total: " << TOUCH_DOWN + FIELD_GOAL + EXTRA_POINT
		<< std::endl << std::endl;

	std::cout << "---Team 2 scored---"
		<< "\nTouch down points: " << TOUCH_DOWN 
		<< "\nTwo points: " << TWO_POINT 
		<< "\nSafety points: " << SAFETY
		<< std::endl;
	std::cout << "Team 2 total: " << TOUCH_DOWN + TWO_POINT + SAFETY
		<< std::endl;

	return 0;
}


