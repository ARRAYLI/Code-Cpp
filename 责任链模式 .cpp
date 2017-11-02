// ������ģʽ��

// �쳵�����׳�����δ��벻��������ģʽ������������ģʽ���׳�
#if 0
#include<iostream>
using  namespace std;

// �쳵������
class CarHandle
{
public :
	virtual void HandleCar() = 0;    // �쳵������ӿ�
};

// �쳵ͷ
class HeadCarHandle:public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵ͷ" << endl;
	}
};

// �쳵��
class BodyCarHandle:public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵��" << endl;
	}
};

// �쳵β
class TailCarHandle:public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵β" << endl;
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

// ������ģʽ ��

#include<iostream>
using namespace std;

// �쳵������
class CarHandle
{
public:
	virtual void HandleCar() = 0;    // �쳵������ӿ�
	CarHandle *setNextHandle(CarHandle *handle)
	{
		m_carhandle = handle;
		return m_carhandle;
	}
protected:
	CarHandle *m_carhandle;			// ������һ�����ݴ���Ԫ
};

// �쳵ͷ
class HeadCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵ͷ" << endl;

		// ���공ͷ�Ժ� ������ݽ�����һ��������
		if (m_carhandle!=NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};

// �쳵��
class BodyCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵��" << endl;
		// ���공���Ժ� ������ݽ�����һ��������
		if (m_carhandle != NULL)
		{
			m_carhandle->HandleCar();
		}
	}
};

// �쳵β
class TailCarHandle :public CarHandle
{
public:
	virtual void HandleCar()
	{
		cout << "�쳵β" << endl;
		// ���공���Ժ� ������ݽ�����һ��������
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

	// ����ԵĴ����ϵ
	headcarhandle->setNextHandle(tailcarhandle);
	tailcarhandle->setNextHandle(bodycarhandle);
	bodycarhandle->setNextHandle(NULL);

	headcarhandle->HandleCar();

	delete headcarhandle;
	delete bodycarhandle;
	delete tailcarhandle;

	return 0;
}
