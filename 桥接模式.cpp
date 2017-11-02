#include<iostream>
using namespace std;

class Engine
{
public:
	virtual void installEngine() = 0;
};

class Engine4400cc:public Engine
{
public:
	virtual void installEngine()
	{
		cout << "����4400cc������  ��װ���" << endl;
	}
};

class Engine4500cc :public Engine
{
public:
	virtual void installEngine()
	{
		cout << "����4500cc������  ��װ���" << endl;
	}
};

class Car
{
public:
	Car(Engine *engine)
	{
		m_engine = engine;
	}
	virtual void installEngine() = 0;

protected:
	Engine *m_engine;
};

class BMW5 :public Car
{
public:
	BMW5(Engine *engine) :Car(engine)
	{
	}
	virtual void installEngine()
	{
		m_engine->installEngine();
	}

};

class BMW6 :public Car
{
public:
	BMW6(Engine *engine) :Car(engine)
	{
	}
	virtual void installEngine()
	{
		m_engine->installEngine();
	}

};


int main(void)
{
	Engine *engine = NULL;
	BMW6*	bmw6 = NULL;

	engine = new Engine4400cc;
	bmw6 = new BMW6(engine);
	bmw6->installEngine();

	delete bmw6;
	delete engine;


	return 0;
}