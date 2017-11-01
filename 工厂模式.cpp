#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void sayname() = 0;
};

class Banan :public Fruit
{
public:
	void sayname()
	{
		cout << "����Banana" << endl;
	}
};

class Apple :public Fruit 
{
public:
	void sayname()
	{
		cout << "����Apple" << endl;
	}
};

class AbFactory
{
public:
	virtual Fruit* CreatFactory() = 0;
};
class AppleFactory:public AbFactory
{
public:
	Fruit* CreatFactory()
	{
		return new Apple;
	}
};

class BananaFactory :public AbFactory
{
public:
	Fruit* CreatFactory()
	{
		return new Banan;
	}
};

class Pear:public Fruit
{
public:
	void sayname()
	{
		cout << "����Pear" << endl;
	}
};

class PearFactory :public AbFactory
{
public:
	Fruit* CreatFactory()
	{
		return new Pear;
	}
};
int main(void)
{
	AbFactory *factory = NULL;
	Fruit *fruit = NULL;

	// ���㽶
	factory = new BananaFactory;
	fruit = factory->CreatFactory();
	fruit->sayname();
	delete fruit;
	delete factory;

	// ����
	factory = new PearFactory;
	fruit = factory->CreatFactory();
	fruit->sayname();
	delete fruit;
	delete factory;
	return 0;
}