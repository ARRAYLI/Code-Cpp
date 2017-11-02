#include<iostream>
#include<string>

using namespace std;

class Person
{
public:
	Person(string name,int sex,int condi)
	{
		m_name = name;
		m_sex = sex;
		m_condi = condi;
	}

	int getCondi()
	{
		return m_condi;
	}

	string getName()
	{
		return m_name;
	}
	int getSex()
	{
		return m_sex;
	}
	virtual void getPartner(Person *p) = 0;
protected:
	string	m_name;
	int		m_sex;   // 1表示男   2表示女
	int     m_condi;		// 表示男女找对象的条件
};


class Woman:public Person
{
public:
	Woman(string name, int sex, int condi):Person(name,sex,condi)
	{
	}

	
	virtual void getPartner(Person *p)
	{
		if (this->m_sex==p->getSex())
		{
			cout << "我不是同性恋..." << endl;
		}
		if (this->getCondi()==p->getCondi())
		{
			cout <<this->getName() << "和"<<p->getName()<<" 是绝配" << endl;
		}
		else
		{
			cout << this->getName() << "和" << p->getName() << " 不能配对" << endl;
		}
	}
private:
};

class Man:public Person
{
public:
	Man(string name, int sex, int condi):Person(name,sex,condi)
	{

	}

	virtual void getPartner(Person *p)
	{
		if (this->m_sex == p->getSex())
		{
			cout << "我不是同性恋..." << endl;
		}
		if (this->getCondi() == p->getCondi())
		{
			cout << this->getName() << "和" << p->getName() << " 是绝配" << endl;
		}
		else
		{
			cout << this->getName() << "和" << p->getName() << " 不能配对" << endl;
		}
	}
private:
	
};

int main(void)
{
	Person *xioafang = new  Woman("小芳",2,5);
	Person *zhangsan = new Man("张三",1,5);
	Person *lisi = new Woman("李四",1,4);
	xioafang->getPartner(lisi);

	delete xioafang;
	delete	zhangsan;
	delete	lisi;

	return 0;
}