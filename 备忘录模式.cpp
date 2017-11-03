#include<iostream>
#include<string>
using namespace std;

// Caretaker    管理者
// MememTo		备忘录

class MememTo
{
public:
	MememTo(string name, int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setAge(int age)
	{
		m_age = age;
	}
	
private:
	string	m_name;
	int		m_age;
};

class Person
{
public:
	Person(string name,int age)
	{
		m_name = name;
		m_age = age;
	}
	string getName()
	{
		return m_name;
	}
	int getAge()
	{
		return m_age;
	}
	void setName(string name)
	{
		m_name = name;
	}
	void setAge(int age)
	{
		m_age = age;
	}
	// 保存
	MememTo *createMememTo()
	{
		return new MememTo(m_name, m_age);
	}
	// 还原
	void setMememTo(MememTo* memto)
	{
		m_age = memto->getAge();
		m_name = memto->getName();
	}

	void printT()
	{
		cout << "m_name: " << m_name << ", m_age: " << m_age << endl;
	}
private:
	string	m_name;
	int		m_age;
};

class Caretaker
{
public:
	Caretaker(MememTo *memto)
	{
		m_memto = memto;
	}

	MememTo *getMememTo()
	{
		return m_memto;
	}
	void setMememTo(MememTo *mememto)
	{
		m_memto = mememto;
	}
private:
	MememTo * m_memto;
};
void test1()
{
	MememTo *memto = NULL;
	Person *p = new Person("张三",32);
	p->printT();

	// 创建Person的一个对象状态
	cout << "------------------------" << endl;
	memto = p->createMememTo();
	p->setAge(26);
	p->printT();

	cout << "还原旧的状态" << endl;
	p->setMememTo(memto);
	p->printT();

	delete memto;
	delete p;
}

void test2()
{
//	MememTo *memto = NULL;
	Caretaker *caretaker = NULL;

	Person *p = new Person("张三", 32);
	p->printT();

	// 创建Person的一个对象状态
	cout << "------------------------" << endl;
	caretaker = new Caretaker(p->createMememTo());

	p->setAge(26);
	p->printT();

	cout << "还原旧的状态" << endl;
	p->setMememTo(caretaker->getMememTo());
	p->printT();
	delete caretaker;
	delete p;
}

int main(void)
{
//	test1();
	test2();
	return 0;
}