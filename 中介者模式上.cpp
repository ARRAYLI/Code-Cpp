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
	int		m_sex;   // 1��ʾ��   2��ʾŮ
	int     m_condi;		// ��ʾ��Ů�Ҷ��������
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
			cout << "�Ҳ���ͬ����..." << endl;
		}
		if (this->getCondi()==p->getCondi())
		{
			cout <<this->getName() << "��"<<p->getName()<<" �Ǿ���" << endl;
		}
		else
		{
			cout << this->getName() << "��" << p->getName() << " �������" << endl;
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
			cout << "�Ҳ���ͬ����..." << endl;
		}
		if (this->getCondi() == p->getCondi())
		{
			cout << this->getName() << "��" << p->getName() << " �Ǿ���" << endl;
		}
		else
		{
			cout << this->getName() << "��" << p->getName() << " �������" << endl;
		}
	}
private:
	
};

int main(void)
{
	Person *xioafang = new  Woman("С��",2,5);
	Person *zhangsan = new Man("����",1,5);
	Person *lisi = new Woman("����",1,4);
	xioafang->getPartner(lisi);

	delete xioafang;
	delete	zhangsan;
	delete	lisi;

	return 0;
}