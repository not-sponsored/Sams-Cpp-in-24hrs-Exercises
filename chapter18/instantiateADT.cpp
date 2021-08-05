/*********************************************************
*
* Answer to exercise 1 in chapter 18
*
* Modified 18.5 Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* We cannot instantiate an Animal or Mammal object because the compiler throws
* an abstract class error. This is because both Animal and Mammal have pure 
* virtual functions either directly in Animal or inherited from Mammal.
*
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

enum COLOR { Red, Green, Blue, Yellow, White, Black, Brown };

class Animal // base to horse and bird
{
public:
	Animal(int);
	virtual ~Animal() { cout << "Animal destructor ...\n"; }
	virtual void setAge(int newAge) { age = newAge; }
	virtual void sleep() const = 0;
	virtual void eat() const = 0;
	virtual void reproduce() const = 0;
	virtual void move() const = 0;
	virtual void speak() const = 0;
private:
	int age;
};

Animal::Animal(int newAge):
age(newAge)
{
	cout << "Animal constructor ...\n";
}

class Mammal : public Animal
{
public:
	Mammal(int newAge) : Animal(newAge)
	{ cout << "Mammal constructor ...\n"; }
	virtual ~Mammal() { cout << "Mammal destructor ...\n"; }
	virtual void reproduce() const
	{ cout << "Mammal reproduction depicted ...\n"; }
};

class Fish : public Animal
{
public:
	Fish(int newAge) : Animal(newAge) { cout << "Fish constructor ...\n"; }
	virtual ~Fish() { cout << "Fish destructor ...\n"; }
	virtual void sleep() const { cout << "Fish snoring ...\n"; }
	virtual void eat() const { cout << "Fish feeding ...\n"; }
	virtual void reproduce() const { cout << "Fish laying eggs ...\n"; }
	virtual void move() const { cout << "Fish swimming ...\n"; }
	virtual void speak() const { }
};

class Horse : public Mammal
{
public:
	Horse(int newAge, COLOR newColor): Mammal(newAge), color(newColor)
	{ cout << "Horse constructor ...\n"; }
	virtual ~Horse() { cout << "Hourse destructor ...\n"; }
	virtual void speak() const { cout << "Whinny!\n"; }
	virtual COLOR getcolor() const { return color; }
	virtual void sleep() const { cout << "Horse snoring ...\n"; }
	virtual void eat() const { cout << "Horse snoring ...\n"; }
	virtual void move() const { cout << "Horse running ...\n"; }

protected:
	COLOR color;
};

class Dog : public Mammal
{
public:
	Dog(int newAge, COLOR newColor): Mammal(newAge), color(newColor)
	{ cout << "Dog contructor ...\n"; }
	virtual ~Dog() { cout << "dog destructor ...\n"; }
	virtual void speak() const { cout << "Whoof!\n"; }
	virtual void sleep() const { cout << "Dog snoring ...\n"; }
	virtual void eat() const { cout << "Dog eating ...\n"; }
	virtual void move() const { cout << "Dog running ...\n"; }
	virtual void reproduce() const
	{ cout << "Dogs reproducing ...\n"; } 

protected:
	COLOR color;
};

int main()
{
	Animal *pAnimal = 0;
	int choice;
	bool fQuit = false;
	
	while (1)
	{
	    	cout << "(1) Dog (2) Horse (3) Fish " 
		<< "(4) Animal (5) Mammal (0) Quit: ";  // Animal and Mammal
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			pAnimal = new Dog(5, Brown);
			break;
		case 2:
			pAnimal = new Horse(4, Black);
			break;
		case 3:
			pAnimal = new Fish(5);
			break;
		case 4:  // Animal case throws an error on compilation
			/* pAnimal = new Animal(6); */  // instantiate Animal
			// break;
		case 5:  // Mammal case
			/* pAnimal = new Mammal(7); */  // instantiate Mammal
			// break;
		default:  // catches case 5 and case 6
			fQuit = true;
			break;
		}
		if (fQuit)
			break;

		pAnimal->speak();
		pAnimal->eat();
		pAnimal->reproduce();
		pAnimal->move();
		pAnimal->sleep();
		delete pAnimal;
		cout << "\n";
	}
	return 0;
}


