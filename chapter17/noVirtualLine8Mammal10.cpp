/*********************************************************
*
* Answer to exercise 2 in chapter 17
*
* Modified 17.3 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* We cannot call the override functions because Mammal does not have a virtual
* speak function, so it cannot call the speak function of a derived class. 
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;

class Mammal
{
public:
	Mammal():age(1) { }
	~Mammal() { } 
	// removed line 8 virtual speak method 

protected:
	int age;
};

class Dog : public Mammal
{
public:
	void speak() const { cout << "Woof!\n"; }
};

class Cat : public Mammal
{
public:
	void speak() const { cout << "Meow!\n"; }
};

void valueFunction(Mammal);
void ptrFunction(Mammal*);
void refFunction(Mammal&);

int main()
{
	Mammal *ptr = nullptr;
	int choice;

	while(1)
	{
		bool fQuit = false;
		cout << "(1) dog (2) cat (0) quit: ";
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			fQuit = true;
			break;
		case 1:
			ptr = new Dog;
			cout << "Set ptr to Dog\n";
			break;
		case 2:
			ptr = new Cat;
			cout << "Set ptr to Cat\n";
			break;
		default:
			ptr = new Mammal;
			break;
		}
		if (fQuit)
		{
			break;
		}
		/* ptrFunction(ptr);
		refFunction(*ptr);
		valueFunction(*ptr); */ // need to comment out to compile
	}

	delete ptr;
	return 0;
}

/*
void valueFunction(Mammal mammalValue)  // called last
{
	mammalValue.speak();
}

void ptrFunction(Mammal *pMammal)
{
	pMammal->speak();
}

void refFunction(Mammal &rMammal)
{
	rMammal.speak();
}
*/ // commented out in order to compile
