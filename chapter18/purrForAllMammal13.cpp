/*********************************************************
*
* Answer to exercise 1 in chapter 18
*
* Modified 18.5 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Somehow, the dynamic cast appears to work and purr() is called regardless
* if the Mammal is actually a Cat. So it fails for Dog because Dogs are not
* supposed to purr.
* 
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

class Mammal
{
public:
	Mammal():age(1) { cout << "Mammal constructor ...\n"; }
	virtual ~Mammal() { cout << "Mammal destructor ...\n"; }
	virtual void speak() const { cout << "Mammal speak ...\n"; } 
protected:
	int age;
};

class Cat: public Mammal 
{
public:
	Cat() { cout << "Cat constructor ...\n"; }
	~Cat() { cout << "Cat destructor ...\n"; }
	void speak() const { cout << "Meow!\n"; }
	void purr() const { cout << "Rrrrrrrrrrr!\n"; }
};

class Dog : public Mammal
{
public:
	Dog() { cout << "Dog contructor ...\n"; }
	~Dog() { cout << "dog destructor ...\n"; }
	void speak() const { cout << "Whoof!\n"; }
};

int main()
{
	const int numberMammals = 3;
	Mammal* zoo[numberMammals];
	Mammal *pMammal = 0;
	int choice, i;
	
	for (i = 0; i < numberMammals; i++)
	{
	    	cout << "(1) Dog (2) Cat: "; 
		cin >> choice;
		if (choice == 1)
			pMammal = new Dog;
		else	
			pMammal = new Cat;	

		zoo[i] = pMammal;
	}

	cout << "\n";

	for (i = 0; i < numberMammals; i++)
	{
		zoo[i]->speak();

		Cat *pRealCat = dynamic_cast<Cat *> (zoo[i]);

		pRealCat->purr(); // Dog will purr 
			
		delete zoo[i];
		cout << "\n";	
	}

	return 0;
}


