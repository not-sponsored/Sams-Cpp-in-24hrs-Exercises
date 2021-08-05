/*********************************************************
*
* Part of the answer to exercise 1 in chapter 20 
*
* Modified 20.3 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
#include <string.h>
using std::cout;
using std::cin;

class String
{
public:
	// constructors
	String();
	String(const char *const);
	String(const String&);
	~String();

	// overloaded operators
	char& operator[](int offset);
	char operator[](int offset) const;
	String operator+(const String&);
	void operator+=(const String&);
	String& operator=(const String &);

	// general accessors
	int getLen() const { return len; }
	const char* getString() const { return value; }
	static int constructorCount;

private:
	String(int); // private constructor
	char* value;
	int len;
};

// default constructor creates 0 byte string
String::String()
{
	value = new char[1];
	value[0] = '\0';
	len = 0;
	cout << "\tDefault string constructor\n";
	constructorCount++;
}

// private helper constructor only for class functions
// creates a string of required size, null filled
String::String(int len)
{
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = '\0';
	len = len;
	cout << "\tString(int) constructor\n";
	constructorCount++;
}

String::String(const char* const cString)
{
	len = strlen(cString);
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = cString[i];
	value[len] = '\0';
	cout << "\tString(char*) constructor\n";
	constructorCount++;
}

String::String(const String& rhs)
{
	len = rhs.getLen();
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = rhs[i];
	value[len] = '\0';
	cout << "\tString(String&) constructor\n";
	constructorCount++;
}

String::~String()
{
	delete [] value;
	len = 0;
	cout << "\tString destructor\n";
}

// operator equals, frees existing memory and copies string and size
String& String::operator=(const String &rhs)
{
	if (this == &rhs)
		return *this;
	delete [] value;
	len = rhs.getLen();
	value = new char[len + 1];
	int i;
	for (i = 0; i < len; i++)
		value[i] = rhs[i];
	value[len] = '\0';
	return *this;
	cout << "\tString operator=\n";
}

// non-constant offset operator returns reference to character to be changed
char& String::operator[](int offset)
{
	if (offset > len)
		return value[len - 1];
	else if (offset < 0 && abs(offset) <= len)
		return value[len + offset];
	else if (offset < 0)
		return value[0];
	else
		return value[offset];
}

// constant offset operator for use on const objects (see copy constructor)
char String::operator[](int offset) const
{
	if (offset > len)
		return value[len - 1];
	else if (offset < 0 && abs(offset) <= len)
		return value[len + offset];
	else if (offset < 0)
		return value[0];
	else
		return value[offset];
}

// new string by adding current string to rhs
String String::operator+(const String& rhs)
{
	int totalLen = len + rhs.getLen();
	int i, j;
	String temp(totalLen);
	for (i = 0; i < len; i++)
		temp[i] = value[i];
	for (j = 0; j < rhs.getLen(); j++)
		temp[i] = rhs[j];
	temp[totalLen] = '\0';
	return temp;
}

// changes current string, returns nothing
void String::operator+=(const String& rhs)
{
	int rhsLen = rhs.getLen();
	int totalLen = len + rhsLen;
	int i, j;
	String temp(totalLen);
	for (i = 0; i < len; i++)
		temp[i] = value[i];
	for (j = 0; j < rhs.getLen(); j++)
		temp[i] = rhs[i - len];
	temp[totalLen] = '\0';
	*this = temp;
}

int String::constructorCount = 0;
