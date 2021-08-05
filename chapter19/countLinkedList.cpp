/*********************************************************
*
* Answer to exercise 1 in chapter 19
*
* Modified 19.1 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

enum { kIsSmaller, kIsLarger, kIsSame };

// all classes in linked list must have a show() and compare()
class Data
{
public:
	Data() { }
	Data(int newValue) { value = newValue; }
	int compare(const Data&);
	void show() { cout << value << "\n"; }
	
private:
	int value;
};

// decides where to place the object in the list
int Data::compare(const Data& otherData)
{
	if (value < otherData.value)
		return kIsSmaller;
	if (value > otherData.value)
		return kIsLarger;
	else
		return kIsSame;
}

// forward class declarations
class Node;
class HeadNode;
class TailNode;
class InternalNode;

// an ADT representing a node
// each derived class must override insert() and show()
class Node
{
public:
	Node() { }
	virtual ~Node() { }
	virtual Node* insert(Data* data) = 0;
	virtual void show() = 0;
	virtual int count() = 0; 
private:
};

// a node to hold objects of type Data
class InternalNode : public Node
{
public:
	InternalNode(Data* data, Node* next);
	virtual ~InternalNode() { delete next; delete data; }
	virtual Node* insert(Data* data);
	virtual void show()
		{ data->show(); next->show(); } // delegate to next node
	virtual int count()
		{ return next->count() + 1; } // recursively count

private:
	Data* data; // holds data class 
	Node* next; // points to next node in the linked list	
};

// simple constructor
InternalNode::InternalNode(Data* newData, Node* newNext):
data(newData), next(newNext)
{ }

// store new object in list the object figures out where it goes and inserts it
Node* InternalNode::insert(Data* otherData)
{
	// is the new object bigger or smaller than the current one
	int result = data-> compare(*otherData);

	switch (result)
	{
	// if same it goes first
	case kIsSame:  // fall to next case
	case kIsLarger:  // new data comes before current
		{
			InternalNode * dataNode =
				new InternalNode(otherData, this);
			return dataNode;
		}
	// if larger pass to next node to handle
	case kIsSmaller:
		{
			next = next->insert(otherData);
			return this;
		}
	}
	return this;
}

// last node in list
class TailNode : public Node
{
public:
	TailNode() { }
	virtual ~TailNode() { }
	virtual Node* insert(Data* data);
	virtual void show() { }
	virtual int count() { return 0; } // not an internal node so zero count 
private:
};

// data must come before tail
Node* TailNode::insert(Data* data)
{
	InternalNode* dataNode = new InternalNode(data, this);
	return dataNode;
}

// head which points to head of the list
class HeadNode : public Node
{
public:
	HeadNode();
	virtual ~HeadNode() { delete next; }
	virtual Node* insert(Data* data);
	virtual void show() { next->show(); }
	virtual int count()
		{ return next->count() + 0; } // zero count not an internal node
private:
	Node* next;
};

// create tail
HeadNode::HeadNode()
{
	next = new TailNode;
}

// nothing comes before head so pass data to next node
Node* HeadNode::insert(Data* data)
{
	next = next->insert(data);
	return this;
}

// pass to other classes for most of the work
class LinkedList
{
public:
	LinkedList();
	~LinkedList() { delete head; }
	void insert(Data* data);
	void showAll() { head->show(); }
	int getInternalNodeCount() { return head->count(); }
private:
	HeadNode* head;
};	

// create head node which spawns tail node
LinkedList::LinkedList()
{
	head = new HeadNode;
}

// delegate insert to head ndoe
void LinkedList::insert(Data* pData)
{
	head->insert(pData);
}

int main()
{
	Data* pData;
	int value = 0;
	LinkedList list;

	while (true)
	{
		cout << "Enter value (negative number to stop)? ";
		cin >> value;
		if (value < 0)
			break;
		pData = new Data(value);
		list.insert(pData);
	}

	// display the list
	list.showAll();
	
	// display the count of internal nodes
	cout << "Total internal nodes: " << list.getInternalNodeCount() << "\n";
	return 0;
}
