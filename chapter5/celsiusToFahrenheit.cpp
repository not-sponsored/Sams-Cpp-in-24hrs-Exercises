/*********************************************************
*
* Answer to exercise 1 in chapter 5 
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

float celsiusToFahrenheit(float celsius);

int main()
{
	float celsius;
	cout << "Enter temperature in Celsius: ";
	cin >> celsius;

	cout << "\nTemperature in Fahrenheit: "
		<< celsiusToFahrenheit(celsius) << "\n";
	return 0;
}

float celsiusToFahrenheit(float celsius)
{
	return ((celsius * 9) / 5.0) + 32;
}
