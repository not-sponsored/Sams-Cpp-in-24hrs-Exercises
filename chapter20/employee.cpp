/*********************************************************
*
* Answer to exercise 1 in chapter 20 
*
* Modified 20.4 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* String constructor called 5 times
* twice on line 70, once on 72, once on 73, and once on 74
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

#include "uncommentedString.hpp"

class Employee
{
public:
	Employee();
	Employee(const char*, const char*, const char*, long);
	~Employee();
	Employee(const Employee&);
	Employee& operator=(const Employee&);

	const String& getFirstName() const { return firstName; }
	const String& getLastName() const { return lastName; }
	const String& getAddress() const { return address; }
	long getSalary() const { return salary; }

	void setFirstName(const String& fName) { firstName = fName; }
	void setLastName(const String& lName) { lastName = lName; }
	void setAddress(const String& newAddress) { address = newAddress; } 
	void setSalary(long newSalary) { salary = newSalary; }

private:
	String firstName;
	String lastName;
	String address;
	long salary;
};

Employee::Employee():
	firstName(""),
	lastName(""),
	address(""),
	salary(0)
{ }

Employee::Employee(const char* newFirstName, const char* newLastName,
	const char* newAddress, long newSalary):
	firstName(newFirstName),
	lastName(newLastName),
	address(newAddress),
	salary(newSalary)
{ }

Employee::Employee(const Employee& rhs):
	firstName(rhs.getFirstName()),
	lastName(rhs.getLastName()),
	address(rhs.getAddress()),
	salary(rhs.getSalary())
{ }

Employee::~Employee() { }

Employee& Employee::operator=(const Employee& rhs)
{
	if (this == &rhs)
		return *this;

	firstName = rhs.getFirstName();
	lastName = rhs.getLastName();
	address = rhs.getAddress();
	salary = rhs.getSalary();
	
	return *this;
}

int main()
{
	Employee snett("Silver", "Burdett", "800 East 96th St.", 20000);
	snett.setSalary(50000);
	String lastName("Snett");
	snett.setLastName(lastName);
	snett.setFirstName("Sam");

	cout << "Name: ";
	cout << snett.getFirstName().getString();
	cout << " " << snett.getLastName().getString();
	cout << ".\nAddress: ";
	cout << snett.getAddress().getString();
	cout << ".\nSalary: ";
	cout << snett.getSalary() << "\n";
	return 0;
}
