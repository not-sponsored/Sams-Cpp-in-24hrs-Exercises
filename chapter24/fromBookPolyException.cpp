/*********************************************************
*
* Answer to exercise 1 in chapter 24 
*
* Reproduced from 24.2 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
* 
* Trying out 24.2 from the book as suggested by the author.
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

const int defaultSize = 10;

// define exception class
class XBoundary {};

class XSize
{
public:
	XSize(int newSize): size(newSize) {}
	~XSize() {}
	virtual int getSize() { return size; }
	virtual void printError()
		{ cout << "Size error. Received: " << size << "\n"; }
protected:
	int size;
};

class XTooBig: public XSize
{
public:
	XTooBig(int size): XSize(size) {}
	virtual void printError()
	{
		cout << "Too big! Received: ";
		cout << XSize::size << "\n";
	}
};

class XTooSmall: public XSize
{
public:
	XTooSmall(int size): XSize(size) {}
	virtual void printError()
	{
		cout << "Too small! REceived: ";
		cout << XSize::size << "\n";
	}
};

class XZero: public XTooSmall
{
public:
	XZero(int newSize): XTooSmall(newSize) {}
	virtual void printError()
	{
		cout << "Zero Received: ";
		cout << XSize::size << "\n";
	}
};

class XNegative: public XSize
{
public:
	XNegative(int size): XSize(size) {}
	virtual void printError()
	{
		cout << "Negative! Received: ";
		cout << XSize::size << "\n";
	}
};

class Array
{
public:
	// constructors
	Array(int size = defaultSize);
	Array(const Array &rhs);
	~Array() { delete [] pType; }

	// operators
	Array& operator=(const Array&); // does not appear to be implemented
	int& operator[](int offSet);
	const int& operator[](int offSet) const;

	// accessors
	int getSize() const { return size; }

	// friend function
	friend std::ostream& operator<< (std::ostream&, const Array&);

private:
	int *pType;
	int size;
};

Array::Array(int newSize):
size(newSize)
{
	if (newSize == 0)
		throw XZero(size);
	if (newSize < 0)
		throw XNegative(size);
	if (newSize < 10)
		throw XTooSmall(size);
	if (newSize > 30000)
		throw XTooBig(size);

	pType = new int[newSize];
	for (int i = 0; i < newSize; i++)
		pType[i] = 0;
}

int& Array::operator[] (int offSet)
{
	int size = getSize();
	if (offSet >= 0 && offSet < size)
		return pType[offSet];
	throw XBoundary();
	return pType[offSet];
}

const int& Array::operator[] (int offSet) const
{
	int size = getSize();
	if (offSet >= 0 && offSet < size)
		return pType[offSet];
	throw XBoundary();
	return pType[offSet];
}

int main()
{
	try
	{
		int choice;
		cout << "Enter the array size: ";
		cin >> choice;
		Array intArray(choice);
		for (int j = 0; j < 100; j++)
		{
			intArray[j] = j;
			cout << "intArray[" << j << "] OK ...\n";
		}
	}
	catch (XBoundary)
	{
		cout << "Unable to process your input\n";
	}
	catch (XSize& exception)
	{
		exception.printError();
	}
	catch (...)
	{
		cout << "Something went wrong, " 
			<< "but I've no idea what!\n";
	}
	cout << "Done\n";
	return 0;
}
