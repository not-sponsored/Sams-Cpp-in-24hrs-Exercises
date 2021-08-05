/*********************************************************
*
* Answer to exercise 1 in chapter 16 
*
* Modified 16.6 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>

class Mammal
{
public:
	void move() const { std::cout << "Mammal moves one step\n"; }
	void move(int distance) const
		{ std::cout << "Mammal moves " << distance << " steps\n"; }
protected:
	int age;
	int weight;
};

class Dog : public Mammal
{
public:
	void move() const { std::cout << "Dog moves 5 steps\n"; }
};

int main()
{
	Mammal bigAnimal;
	Dog fido;

	bigAnimal.move();
	bigAnimal.move(2);

	fido.move();
	fido.Mammal::move(10);  // called base member function

	return 0;
}
