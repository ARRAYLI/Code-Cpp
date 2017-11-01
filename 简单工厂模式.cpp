#include<iostream>
#include<string.h>
using namespace std;

class Fruit
{
public:
	virtual void getFruit() = 0;
};

class Banana :public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "�����㽶..." << endl;
	}
};

class Apple :public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "����ƻ��..." << endl;
	}
};

class Factory 
{
public:
	Fruit *creat(char *p)
	{
		if (strcmp(p,"banana")==0)
		{
			return new Banana;
		}
		else if (strcmp(p, "apple") == 0)
		{
			return new Apple;
		}
		else
		{
			cout << "��֧�֣�" << endl;
			return NULL;
		}
	}

};

int main(void)
{
	Factory *f = new Factory;
	Fruit *fruit = NULL;

	// ���������㽶
	fruit = f->creat("banana");
	fruit->getFruit();
	delete fruit;

	// ��������ƻ��
	fruit = f->creat("apple");
	fruit->getFruit();
	delete fruit;
	delete f;
	f = NULL;
	return 0;
}