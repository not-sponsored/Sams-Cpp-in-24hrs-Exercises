/*********************************************************
*
* Answer to exercise 1 in chapter 22 
*
* Modified 22.1 from Sams Teach Yourself C++ in 24 Hours by Rogers Cadenhead 
* and Jesse Liberty
*  
* Compiled with g++ (GCC) 11.1.0
*
*********************************************************/

#include <iostream>
using std::cout;
using std::cin;

class Condition
{
public:
	Condition() { }
	virtual ~Condition() { cout << "Condition destructor\n"; }
	virtual void log() = 0;
};

class Normal : public Condition
{
public:
	Normal() { log(); }
	virtual ~Normal() { cout << "Normal destructor\n"; }
	virtual void log() { cout << "Logging normal condition...\n"; }
};

class Error : public Condition
{
public:
	Error() { log(); }
	virtual ~Error() { cout << "Error destructor\n"; }
	virtual void log() { cout << "Logging error!\n"; }
};

class Alarm : public Condition
{
public:
	Alarm();
	virtual ~Alarm() { cout << "Alarm destructor\n"; }
	virtual void warn() { cout << "Warning\n"; }
	virtual void log() { cout << "General alarm log\n"; }
	virtual void call() = 0;
};

Alarm::Alarm()
{
	log();
	warn();
}

class FireAlarm : public Alarm
{
public:
	FireAlarm() { log(); }
	virtual ~FireAlarm() { cout << "FireAlarm destructor\n"; }
	virtual void call() { cout << "Calling fire department!\n"; }
	virtual void log() { cout << "Logging fire called\n"; }
};

int main()
{
	int input;
	int okay = 1;
	Condition *pCondition;
	while (okay)
	{
		cout << "(0) Quit (1) Normal (2) Fire: ";
		cin >> input;
		okay = input;
		switch (input)
		{
		case 0:
			break;
		case 1:
			pCondition = new Normal;
			delete pCondition;
			break;
		case 2:
			pCondition = new FireAlarm;
			delete pCondition;
			break;
		default:
			pCondition = new Error;
			delete pCondition;
			okay = 0;
			break;
		}
	}
	return 0;
}


