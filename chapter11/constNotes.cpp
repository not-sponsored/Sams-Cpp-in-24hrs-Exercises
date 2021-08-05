/*********************************************************
*
* Notes about const pointers 
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

int main()
{
	int testInt = 3;
	int secondTestInt = 7;

	// initial values
	cout << "Address of testInt " << &testInt << "\n";
	cout << "Value of testInt " << testInt << "\n";
	cout << "Address of secondTestInt " << &secondTestInt << "\n";
	cout << "Value of secondTestInt " << secondTestInt << "\n\n";

	const int *pLeftConst = &testInt;
	cout << "*pLeftConst is " << *pLeftConst
		<< " and cannot change in value\n";
	cout << "pLeftConst is " << pLeftConst
		<< " and can change in address\n"; 
	/* *pLeftConst = 9; */                     // fails value is const
	pLeftConst = &secondTestInt;               // address is not const
	cout << "*pLeftConst is " << *pLeftConst
		<< " and has changed because of address change\n"; 
	cout << "pLeftConst is " << pLeftConst
		<< " and is now the location of testInt\n\n";
	
	// check initial values
	cout << "Address of testInt " << &testInt << "\n";
	cout << "Value of testInt " << testInt << "\n";
	cout << "Address of secondTestInt " << &secondTestInt << "\n";
	cout << "Value of secondTestInt " << secondTestInt << "\n\n";

	int * const pRightConst = &testInt;
	cout << "*pRightConst is " << *pRightConst
		<< " and can change in value\n"; 
	cout << "pRightConst is " << pRightConst
		<< " and cannot change in address\n"; 
	*pRightConst = 9;                            // value is not const
	/* pRightConst = &secondTestInt; */          // fails address is const
	cout << "*pRightConst is " << *pRightConst
		<< " and has changed in value\n"; 
	cout << "pRightConst is still " << pRightConst
		<< " and cannot change in address\n\n"; 
	
	// check initial values
	cout << "Address of testInt " << &testInt << "\n";
	cout << "Value of testInt " << testInt << "\n";
	cout << "Address of secondTestInt " << &secondTestInt << "\n";
	cout << "Value of secondTestInt " << secondTestInt << "\n\n";

	const int * const pBothConst = &testInt;
	cout << "*pBothConst is " << *pBothConst
		<< " and cannot change in value\n"; 
	cout << "pBothConst is " << pBothConst
		<< " and cannot change in address\n"; 
	/* *pBothConst = 9; */                        // fails value is const
	/* pBothConst = &secondTestInt; */            // fails address is const
	cout << "*pBothConst is " << *pBothConst
		<< " and has not changed in value\n"; 
	cout << "pBothConst is still " << pBothConst
		<< " and has not changed in address\n\n"; 
	
	// check initial values
	cout << "Address of testInt " << &testInt << "\n";
	cout << "Value of testInt " << testInt << "\n";
	cout << "Address of secondTestInt " << &secondTestInt << "\n";
	cout << "Value of secondTestInt " << secondTestInt << "\n\n";

	return 0;
}
