// ����ʽ����ģʽ

#if 
#include<iostream>
using namespace std;

// ����ʽ����ģʽ
class Singleton
{
private:
	Singleton()
	{
		cout <<"Singleton  ���캯��ִ��"<< endl;
	}
public:
	static	Singleton *getInstance()
	{
		if (NULL == m_psl)
		{
			m_psl = new Singleton;
		}
		return m_psl;
	}
	static void FreeSingleton()
	{
		if (NULL!=m_psl)
		{
			delete m_psl;
			m_psl = NULL;
		}
	}
private:
	static Singleton *m_psl;
};

Singleton* Singleton::m_psl = NULL;
int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	if (p1==p2)
	{
		cout << "��ͬһ������" << endl;
	}
	else
	{
		cout << "����ͬһ������" << endl;
	}
	Singleton::FreeSingleton();
	return 0;
}
#endif


// ����ʽ����ģʽ

#include<iostream>
using namespace std;

class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton ���캯��ִ��"<<endl;
	}
public:
	static Singleton *getInstance()
	{
		return m_psl;
	}

	 static void FreeSingleton()
	{
		if (NULL != m_psl)
		{
			delete m_psl;
			m_psl = NULL;
		}
	}
private:
	static Singleton *m_psl;
};

// ��������ģʽ

Singleton* Singleton::m_psl = new Singleton;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	if (p1 == p2)
	{
		cout << "��ͬһ������" << endl;
	}
	else
	{
		cout << "����ͬһ������" << endl;
	}
	Singleton::FreeSingleton();

	return 0;
}
