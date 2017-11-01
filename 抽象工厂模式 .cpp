#include<iostream>
using namespace std;

class Fruit
{
public:
	virtual void  sayName() = 0;
};

class AbstractFactory
{
public:
	virtual Fruit*	creatApple() = 0;
	virtual Fruit*	creatBanana() = 0;
};

class NorthApple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "我是北方苹果!" << endl;
	}
};

class NorthBanana :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "我是北方香蕉" << endl;
	}
};

class SourthApple :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "我是南方苹果" << endl;
	}
};

class SourthBanana :public Fruit
{
public:
	virtual void sayName()
	{
		cout << "我是南方香蕉" << endl;
	}
};

class NorthFactory :public AbstractFactory
{
	virtual Fruit* creatApple()
	{
		return new NorthApple;
	}
	virtual Fruit* creatBanana()
	{
		return new NorthBanana;
	}
};

class SourthFactory :public AbstractFactory
{
	virtual Fruit* creatApple()
	{
		return new SourthApple;
	}
	virtual Fruit* creatBanana()
	{
		return new SourthBanana;
	}
};

int main(void)
{
	AbstractFactory *af = NULL;
	Fruit *fruit = NULL;

	// --------北方工厂
	af = new NorthFactory;
	fruit = af->creatApple();
	fruit->sayName();
	delete  fruit;

	fruit = af->creatBanana();
	fruit->sayName();
	delete fruit;
	delete af;

	// --------南方工厂
	af = new SourthFactory;
	fruit = af->creatApple();
	fruit->sayName();
	delete  fruit;

	fruit = af->creatBanana();
	fruit->sayName();
	delete fruit;
	delete  af;
	return 0;
}