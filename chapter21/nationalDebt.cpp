/*********************************************************
*
* Answer to exercise 1 in chapter 21 of Sams Teach Yourself C++ in 24 Hours 
* by Rogers Cadenhead and Jesse Liberty 
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

int main()
{
	double nationalDebt = 19.24168; // in trillions from the book
	const short days = 10;

	const double debtIncrease = 0.00235; // increase per day (trillions)
	auto addDebt = [debtIncrease](double debt)
				{ return debt + debtIncrease; };
	
	cout << "Original debt " << "is $" << nationalDebt << " trillions\n";

	for (short i = 0; i < days; i++)
	{
		nationalDebt = addDebt(nationalDebt);
		cout << "Adding $" << debtIncrease << " in billions\n";
	}
	
	cout << "Final debt after " << days << " days is $" << nationalDebt 
		<< " trillions\n";
	return 0;
}
