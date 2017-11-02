#include<iostream>
using namespace std;

// Ŀ��ӿ���
class current18v
{
public:
	virtual void useCurrrent18v() = 0;
};

// ��Ҫ�������
class current220v
{
public:
	void Usecurrent220v()
	{
		cout << "����220v����ӭʹ��	" <<endl;
	}
};

// ��������
class Adapter:public current18v
{
public:
	Adapter(current220v *current220v)
	{
		m_current220v = current220v;
	}

	virtual void useCurrrent18v()
	{
		cout << "������ ����220v" << endl;
		m_current220v->Usecurrent220v();
	}

private:
	current220v *m_current220v;
};

int main(void)
{
	current220v *_current220v = NULL;
	Adapter	*	adapter = NULL;
	_current220v = new current220v;
	adapter = new Adapter(_current220v);
	adapter->useCurrrent18v();

	delete _current220v;
	delete adapter;
	return 0;
}