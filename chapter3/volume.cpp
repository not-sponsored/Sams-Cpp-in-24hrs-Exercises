/*********************************************************
*
* Answer to exercise 2 in chapter 3 
*
* Modified 3.2 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>

int main()
{
	int width = 5;
	int length = 5;
	float height = 0.5;

	std::cout << "Width: " << width << std::endl;
	std::cout << "Length: " << length << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Volume: " << width * length * height << std::endl; 

	return 0;
}
