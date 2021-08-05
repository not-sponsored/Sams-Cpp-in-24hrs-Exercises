/*********************************************************
*
* Answer to exercise 2 in chapter 2 
*
* Modified 7.1 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
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
	float goal[] = { 0.9, 0.75, 0.5, 0.25, 0.1 };
	float weight, target;

	cout << "Enter current weight: ";
	cin >> weight;
	cout << "\nEnter goal weight: ";
	cin >> target;
	cout << std::endl;

	for (float milestone : goal)
	{
		float weightLossAmount = (weight - target) * milestone; 
		cout << "goal" << ": ";
		cout << target + weightLossAmount << std::endl;
	}
	return 0;
}


