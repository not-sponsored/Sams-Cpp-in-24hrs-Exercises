/*********************************************************
*
* Notes for my own use with an analogy for a pointer 
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

int main()
{
	// pointer analogy (arrow stuck in box picture []<-):
	// the arrow points to an address and the box holds a value
	// declaration always sets the arrow so you need an address 
	// regular access without dereference always refers to the arrow
	// dereference with (*) allows access to the value or the pointed box
	// -> operator basically dereferences and accesses a member function
	// Example: 
	// [70]<-101 diagram of short *pointer = 70;
	// so *pointer = 70 (value) and pointer = 101 (address)

	short chosenNumber = 0;

	cout << "Enter a number to point at: ";
	cin >> chosenNumber;

	short *pNumber = &chosenNumber; // arrow set to address of chosenNumber 
	cout << "Regular access yields arrow (address) " << pNumber << "\n";
	cout << "Dereference yields box (value) " << *pNumber << "\n";

	pNumber = nullptr;
	delete pNumber;
	return 0;	
}
