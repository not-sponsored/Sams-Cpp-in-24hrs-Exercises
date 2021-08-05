/*********************************************************
*
* Answer to exercise 2 in chapter 2 
*
* Modified 2.2 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>

int add(int x, int y, int z)
{
	// add numbers x, y, and z together and return the sum
	std::cout << "Running calculator ..\n";
	return (x+y+z);
}

int main()
{
	/* calls an add() function to add two different
	   sets of numbers together and display the results. The add()
	   function doesn't do anything unless it is called by a line in
	   the main() function. */
	std::cout << "What is 867 + 5309 + 234\n";
	std::cout << "The sum is " << add(867, 5309, 234) << "\n\n";
	std::cout << "What is 777 + 9311 + 494?\n";
	std::cout << "The sum is " << add(777, 9311, 494) << "\n";
	return 0;
}

