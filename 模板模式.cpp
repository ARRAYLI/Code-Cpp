#include<iostream>
using namespace std;

class MakeCar
{
public:
	virtual void makeBody() = 0;
	virtual void makeTail() = 0;
	virtual void makeHead() = 0;
	
	virtual void make()     // Ä£°åº¯Êý
	{
		makeTail();
		makeBody();
		makeHead();
	}
};

class Jeep:public MakeCar
{
	virtual void makeBody()
	{
		cout << "Jeep Body" << endl;
	}
	virtual void makeTail()
	{
		cout << "Jeep Tail" << endl;
	
	}
	virtual void makeHead()
	{
		cout << "Jeep Head" << endl;
	}
};

class BMW :public MakeCar
{
	virtual void makeBody()
	{
		cout << "BMW Body" << endl;
	}
	virtual void makeTail()
	{
		cout << "BMW Tail" << endl;

	}
	virtual void makeHead()
	{
		cout << "BMW Head" << endl;
	}
};

int main(void)
{
	MakeCar *car1 = new Jeep;
	car1->make();

	delete  car1;
	car1 = NULL;

	MakeCar *car2 = new BMW;
	car2->make();
	delete  car2;
	car2 = NULL;
	return 0;
}