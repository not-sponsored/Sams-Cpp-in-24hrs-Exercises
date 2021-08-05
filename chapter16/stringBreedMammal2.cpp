/*********************************************************
*
* Answer to exercise 2 in chapter 16 
*
* Modified 16.2 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
#include <string>
using std::string;

class Mammal
{
public:
	// constructors
	Mammal(): age(2), weight(5) {}
	~Mammal() {}

	// accessors
	int getAge() const { return age; }
	void setAge(int newAge) { age = newAge; }
	int getWeight() const { return weight; }
	void setWeight(int newWeight) { weight = newWeight; }

	// other member functions
	void speak() const { std::cout << "Mammal sound!\n"; }
	void sleep() const { std::cout << "Shhh. I'm sleeping.\n"; }
protected:
	int age;
	int weight;
};

class Dog : public Mammal
{
public:
	// constructors
	Dog(): breed("Yorkie") {}
	Dog(string newBreed) { setBreed(newBreed); }
	~Dog() {}

	// accessors
	string getBreed() const { return breed; }
	void setBreed(string newBreed) { breed = newBreed; }

	// other member functions
	void wagTail() const { std::cout << "Tail wagging ...\n"; }
	void begForFood() const { std::cout << "Begging for food ...\n"; }
private:
	string breed;
};

int main()
{
	Dog fido;
	Dog test("Lab");

	fido.speak();
	fido.wagTail();
	std::cout << "Fido is " << fido.getAge() << " years old\n\n";

	std::cout << "Test is " << test.getAge() << " years old\n";
	std::cout << "Test is a " << test.getBreed() << "\n";

	return 0;
}
