/*********************************************************
*
* Answer to exercise 1 in chapter 13 
*
* Modified 13.5 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::endl;

class Cat
{
public:
	Cat(int age, int weight);
	~Cat() {}
	int getAge() { return itsAge; }
	int getWeight() { return itsWeight; }
private:
	int itsAge;
	int itsWeight;
};

Cat::Cat(int age, int weight)
{
	itsAge = age;
	itsWeight = weight;
}

Cat *theFunction();  // return a pointer so main can delete

int main()
{
	Cat *pCat = theFunction();
	cout << "pCAt is " << pCat->getAge() << " years old." << endl;
	cout << "pCat: " << pCat << endl;
	delete pCat;
	pCat = nullptr;
	return 0;
}

Cat * theFunction()
{
	Cat *pFrisky = new Cat(5, 9);
	cout << "pFrisky: " << pFrisky << endl;
	return pFrisky;
}
