/*********************************************************
*
* Answer to exercise 1 in chapter 23 
*
* Modified 23.2 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

enum { kIsSmaller, kIsLarger, kIsSame };

class Data
{
public:
	Data(int newVal): value(newVal) {}
	~Data()
	{
		cout << "Deleting Data object with value: ";
		cout << value << "\n";
	}
	int compare(const Data&);
	void show() { cout << value << "\n"; }
private:
	int value;
};

int Data::compare(const Data& otherObject)
{
	if (value < otherObject.value)
		return kIsSmaller;
	if (value > otherObject.value)
		return kIsLarger;
	else
		return kIsSame;
}

class Robot
{
public:
	Robot(int newAge): age(newAge) {}
	~Robot()
	{
		cout << "Deleting " << age
			<< "-year-old robot.\n";
	}
	int compare(const Robot&);
	void show()
	{
		cout << "This robot is " << age
			<< " years old\n";
	}
private:
	int age;
};

int Robot::compare(const Robot& otherRobot)
{
	if (age < otherRobot.age)
		return kIsSmaller;
	if (age > otherRobot.age)
		return kIsLarger;
	else
		return kIsSame;
}

class Cyborg
{
public:
	Cyborg(int newAge): age(newAge) {}
	~Cyborg()
	{
		cout << "Deleting " << age
			<< "-year-old cyborg.\n";
	}
	int compare(const Cyborg&);
	void show()
	{
		cout << "This cyborg is " << age
			<< " years old\n";
	}
private:
	int age;	
};

int Cyborg::compare(const Cyborg& otherCyborg)
{
	if (age < otherCyborg.age)
		return kIsSmaller;
	else if (age > otherCyborg.age)
		return kIsLarger;
	else
		return kIsSame;
}

template <class T>
class Node
{
public:
	Node() {}
	virtual ~Node() {}
	virtual Node* insert(T* object) = 0;
	virtual void show() = 0;
private:
};

template <class T>
class InternalNode: public Node<T>
{
public:
	InternalNode(T* theObject, Node<T>* next);
	virtual ~InternalNode() { delete next; delete object; }
	virtual Node<T>* insert(T* object);
	virtual void show()
	{
		object->show();
		next->show();
	}
private:
	T* object;
	Node<T>* next;
};

template <class T>
InternalNode<T>::InternalNode(T* newObject, Node<T>* newNext):
object(newObject), next(newNext)
{ }

template <class T>
Node<T>* InternalNode<T>::insert(T* newObject)
{
	int result = object->compare(*newObject);
	
	switch(result)
	{
	case kIsSame:
	case kIsLarger:
		{
			InternalNode<T> * objectNode =
			new InternalNode<T>(newObject, this);
			return objectNode;
		}
	case kIsSmaller:
		next = next->insert(newObject);
		return this;
	}
	return this;
}

template <class T>
class TailNode: public Node<T>
{
public:
	TailNode() {}
	virtual ~TailNode() {}
	virtual Node<T>* insert(T* object);
	virtual void show() {}
private:
};

template <class T>
Node<T>* TailNode<T>::insert(T* object)
{
	InternalNode<T>* objectNode =
		new InternalNode<T>(object, this);
	return objectNode;
}

template <class T>
class HeadNode: public Node<T>
{
public:
	HeadNode();
	virtual ~HeadNode() { delete next; }
	virtual Node<T>* insert(T* object);
	virtual void show() { next->show(); }
private:
	Node<T>* next;
};

template <class T>
HeadNode<T>::HeadNode()
{
	next = new TailNode<T>;
}

template <class T>
Node<T>* HeadNode<T>::insert(T* object)
{
	next = next->insert(object);
	return this;
}

template <class T>
class LinkedList
{
public:
	LinkedList();
	~LinkedList() { delete head; }
	void insert(T* object);
	void showAll() { head->show(); }
private:
	HeadNode<T>* head;
};

template <class T>
LinkedList<T>::LinkedList()
{
	head = new HeadNode<T>;
}

template <class T>
void LinkedList<T>::insert(T* pObject)
{
	head->insert(pObject);
}

void getRobots(LinkedList<Robot>& listOfRobots);
void getData(LinkedList<Data>& listOfData);
void getCyborgs(LinkedList<Cyborg>& listOfCyborgs);

int main()
{
	LinkedList<Robot> listOfRobots;
	LinkedList<Data> listOfData;
	LinkedList<Cyborg> listOfCyborgs;

	getRobots(listOfRobots);
	getData(listOfData);
	getCyborgs(listOfCyborgs);

	cout << "\n";
	listOfRobots.showAll();
	cout << "\n";
	listOfData.showAll();
	cout << "\n";
	listOfCyborgs.showAll();
	return 0;
}

void getRobots(LinkedList<Robot>& listOfRobots)
{
	Robot* pRobot;
	int val;

	while (true)
	{
		cout << "How old is your robot (negative to stop)? ";
		cin >> val;
		if (val < 0)
			break;
		pRobot = new Robot(val);
		listOfRobots.insert(pRobot);
	}
}

void getData(LinkedList<Data>& listOfData)
{
	Data* pData;
	int val;

	while (true)
	{
		cout << "What data value to store (negative to stop)? ";
		cin >> val;
		if (val < 0)
			break;
		pData = new Data(val);
		listOfData.insert(pData);
	}
}

void getCyborgs(LinkedList<Cyborg>& listOfCyborgs)
{
	Cyborg* pCyborg;
	int val;

	while (true)
	{
		cout << "Enter age of cyborg (negative to stop): ";
		cin >> val;
		if (val < 0)
			break;
		pCyborg = new Cyborg(val);
		listOfCyborgs.insert(pCyborg);
	}
}
