/*********************************************************
*
* Answer to exercise 2 in chapter 21 of Sams Teach Yourself C++ in 24 Hours 
* by Rogers Cadenhead and Jesse Liberty 
*  
* Only using one auto typed parameter because square lambda only needs one.
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

int main()
{
	auto square = [](auto x){ return x * x; };

	const int intTest = 5;
	const long longTest = -10;
	const float floatTest = -3.1f;
	const double doubleTest = 6.5;

	auto intResult = square(intTest);
	auto longResult = square(longTest);
	auto floatResult = square(floatTest);
	auto doubleResult = square(doubleTest);

	cout << "With int original: " << intTest << " squared result: "
		<< intResult << "\n";
	cout << "With long original: " << longTest << " squared result: "
		<< longResult << "\n";
	cout << "With float original: " << floatTest << " squared result: "
		<< floatResult << "\n";
	cout << "With double original: " << doubleTest << " squared result: "
		<< doubleResult << "\n";

	return 0;
}
