/*********************************************************
*
* Answer to exercise 1 in chapter 17
*
* Modified 17.1 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* It might make sense to maintain a base class virtual function when the 
* derived class has no need to change the function.
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

class Mammal
{
public:
	Mammal():age(1) { cout << "Mammal Constructor...\n"; }
	~Mammal() { cout << "Mammal destructor ...\n"; }
	void move() const { cout << "Mammal, move one step\n"; }
	virtual void speak() const { cout << "Mammal speak!\n"; }

protected:
	int age;
};

class Dog : public Mammal
{
public:
	Dog() { cout << "Dog constructor ...\n"; }
	~Dog() { cout << "Dog destructor ...\n"; }
	void wagTail() { cout << "Wagging tail ...\n"; }
	/* void speak() const { cout << "Woof!\n"; } */ // commented out
	void move() const { std::cout << "Dog moves 5 steps ...\n"; }
};

int main()
{
	Mammal *pDog = new Dog;
	pDog->move();
	pDog->speak();          // calls mammal speak from v-table 
	return 0;
}
