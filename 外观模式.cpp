#include<iostream>
using namespace std;

class SubSystemA
{
public:
	void doThing()
	{
		cout << "SubSystemA run" << endl;
	}

};

class SubSystemB
{
public:
	void doThing()
	{
		cout << "SubSystemB run" << endl;
	}

};

class SubSystemC
{
public:
	void doThing()
	{
		cout << "SubSystemC run" << endl;
	}

};

class Facade
{
public:
	Facade()
	{
		subA = new SubSystemA;
		subB = new SubSystemB;
		subC = new SubSystemC;
	}
	~Facade()
	{
		delete subA;
		subA = NULL;
		delete subB;
		subB = NULL;
		delete subC;
		subC = NULL;

	}
	void doThing()
	{
		subA->doThing();
		subB->doThing();
		subC->doThing();
	}
private:
	SubSystemA *subA;
	SubSystemB *subB;
	SubSystemC *subC;
};
void test()
{
	SubSystemA *subA = new SubSystemA;
	SubSystemB *subB = new SubSystemB;
	SubSystemC *subC = new SubSystemC;

	subA->doThing();
	subB->doThing();
	subC->doThing();

	delete subA;
	subA = NULL;
	delete subB;
	subB = NULL;
	delete subC;
	subC = NULL;
}

void test1()
{
	Facade *facade = new Facade;
	facade->doThing();
}
int main(void)
{
	test();
	test1();
	return 0;
}