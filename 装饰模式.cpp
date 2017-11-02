#include<iostream>
using namespace std;

class Car
{
public:
	virtual void show() = 0;
};

class RunCar:public Car
{
public:
	virtual void show()
	{
		cout << "可以跑" << endl;
	}

};

class SwimCar:public Car
{
public:
	SwimCar(Car* car)
	{
		m_car = car;
	}
	void swim()
	{
		cout << "可以游泳" << endl;
	}
	virtual void show()
	{
		m_car->show();
		swim();
	}

private:
	Car* m_car;
};

class FlyCar :public Car
{
public:
	FlyCar(Car*car)
	{
		m_car = car;
	}
	void Fly()
	{
		cout << "可以飞" << endl;
	}
	virtual void show()
	{
		m_car->show();
		Fly();
	}
private:
	Car *m_car;
};

int main(void)
{
	Car *car = NULL;
	car = new RunCar;
	car->show();
	
	cout<< endl;

	SwimCar *sw = new SwimCar(car);
	sw->show();
	
	cout << endl;
	FlyCar *fc = new FlyCar(sw);
	fc->show();

	delete sw;
	delete fc;
	return 0;
}