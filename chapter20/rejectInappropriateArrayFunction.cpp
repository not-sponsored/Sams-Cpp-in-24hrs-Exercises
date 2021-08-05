/*********************************************************
*
* Answer to exercise 2 in chapter 20 
*
* Modified 20.6 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

void square(int&, int&);
void cube(int&, int&);
void swap(int&, int&);
void getVals(int&, int&);
void printVals(int, int);
void invalidInput(int&, int&);

int main()
{
	int valOne=1, valTwo=2;
	int choice, i;
	const int maxArray = 5;
	void (*pFuncArray[maxArray])(int&, int&);

	for (i = 0; i < maxArray; i++)
	{
		cout << "(1) Change Values " 
			<< "(2) Square (3) Cube (4) Swap "
			<< "\nany other number defaults to invalidInput: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pFuncArray[i] = getVals;
			break;
		case 2:
			pFuncArray[i] = square;
			break;
		case 3:
			pFuncArray[i] = cube;
			break;
		case 4:
			pFuncArray[i] = swap;
			break;
		default:
			pFuncArray[i] = invalidInput;
			break;
		}
	}
	
	for (i = 0; i < maxArray; i++)
	{
		pFuncArray[i](valOne, valTwo);
		printVals(valOne, valTwo);
	}
	return 0;
}

void printVals(int x, int y)
{
	cout << "x: " << x << " y: " << y << "\n";
}

void invalidInput(int &rX, int &rY)
{
	cout << "Invalid choice currently x: " << rX << " and y: " << rY
		<< "\n"; 
}

void square(int &rX, int &rY)
{
	rX *= rX;
	rY *= rY;
}

void cube(int &rX, int &rY)
{
	int temp;
	
	temp = rX;
	rX *= rX;
	rX = rX * temp;

	temp = rY;
	rY *= rY;
	rY = rY * temp;
}

void swap(int &rX, int &rY)
{
	int temp;
	temp = rX;
	rX = rY;
	rY = temp;
}

void getVals(int &rValOne, int &rValTwo)
{
	cout << "New value for valOne: ";
	cin >> rValOne;
	cout << "New value for valTwo: ";
	cin >> rValTwo;
}
