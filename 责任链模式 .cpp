// 责任链模式上

// 造车问题抛出，这段代码不是责任链模式，而是责任链模式的抛出
#if 0
#include<iostream>
using  namespace std;

// 造车抽象类
class CarHandle
{
public :
	virtual void HandleCar() = 0;    // 造车抽象类接口
};

// 造车头
class HeadCarHandle:public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车头" << endl;
	}
};

// 造车身
class BodyCarHandle:public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车身" << endl;
	}
};

// 造车尾
class TailCarHandle:public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车尾" << endl;
	}
};


int main(void)
{
	HeadCarHandle *headcarhandle = new HeadCarHandle;
	BodyCarHandle *bodycarhandle = new BodyCarHandle;
	TailCarHandle *tailcarhandle = new TailCarHandle;

	headcarhandle->HandleCar();
	bodycarhandle->HandleCar();
	tailcarhandle->HandleCar();

	delete headcarhandle;
	delete bodycarhandle;
	delete tailcarhandle;

	return 0;
}
#endif

// 责任链模式 下

#include<iostream>
using namespace std;

// 造车抽象类
class CarHandle
{
public:
	virtual void HandleCar() = 0;    // 造车抽象类接口
	CarHandle *setNextHandle(CarHandle *handle)
	{
		m_carhandle = handle;
		return m_carhandle;
	}
protected:
	CarHandle *m_carhandle;			// 保存下一个数据吹单元
};

// 造车头
class HeadCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车头" << endl;

		// 造完车头以后 把任务递交给下一个处理者
		if (m_carhandle!=NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};

// 造车身
class BodyCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车身" << endl;
		// 造完车身以后 把任务递交给下一个处理者
		if (m_carhandle != NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};

// 造车尾
class TailCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "造车尾" << endl;
		// 造完车身以后 把任务递交给下一个处理者
		if (m_carhandle != NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};


int main(void)
{
	HeadCarHandle *headcarhandle = new HeadCarHandle;
	BodyCarHandle *bodycarhandle = new BodyCarHandle;
	TailCarHandle *tailcarhandle = new TailCarHandle;

	// 任务对的处理关系
	headcarhandle->setNextHandle(tailcarhandle);
	tailcarhandle->setNextHandle(bodycarhandle);
	bodycarhandle->setNextHandle(NULL);

	headcarhandle->HandleCar();

	delete headcarhandle;
	delete bodycarhandle;
	delete tailcarhandle;

	return 0;
}
