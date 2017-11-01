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
		cout << "我是香蕉..." << endl;
	}
};

class Apple :public Fruit
{
public:
	virtual void getFruit()
	{
		cout << "我是苹果..." << endl;
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
			cout << "不支持！" << endl;
			return NULL;
		}
	}

};

int main(void)
{
	Factory *f = new Factory;
	Fruit *fruit = NULL;

	// 工厂生产香蕉
	fruit = f->creat("banana");
	fruit->getFruit();
	delete fruit;

	// 工厂生产苹果
	fruit = f->creat("apple");
	fruit->getFruit();
	delete fruit;
	delete f;
	f = NULL;
	return 0;
}