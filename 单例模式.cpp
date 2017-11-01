// 懒汉式单例模式

#if 
#include<iostream>
using namespace std;

// 懒汉式单例模式
class Singleton
{
private:
	Singleton()
	{
		cout <<"Singleton  构造函数执行"<< endl;
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
		cout << "是同一个对象" << endl;
	}
	else
	{
		cout << "不是同一个对象" << endl;
	}
	Singleton::FreeSingleton();
	return 0;
}
#endif


// 饿汉式单例模式

#include<iostream>
using namespace std;

class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton 构造函数执行"<<endl;
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

// 饿汉单例模式

Singleton* Singleton::m_psl = new Singleton;

int main(void)
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	if (p1 == p2)
	{
		cout << "是同一个对象" << endl;
	}
	else
	{
		cout << "不是同一个对象" << endl;
	}
	Singleton::FreeSingleton();

	return 0;
}
