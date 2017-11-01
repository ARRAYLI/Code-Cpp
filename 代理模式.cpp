#include<iostream>
using namespace std;

class Subject
{
public:
	virtual void salebook() = 0;
};

class  ReadlSubject:public Subject
{
public:
	virtual void salebook()
	{
		cout << "����" << endl;
	}
private:
};

// a�а���b�ࣻa,b��ʵ��Э����
class dangdangProxy:public Subject
{
public:
	dangdangProxy(ReadlSubject *s)
	{
		m_realSubject = s;
	}
	dangdangProxy()
	{
	
	}
	~dangdangProxy()
	{
		if (NULL!= m_realSubject)
		{
			delete m_realSubject;
			m_realSubject = NULL;
		}
	}
	virtual void salebook()
	{
		m_realSubject = new ReadlSubject;
		dazhe();
		m_realSubject->salebook();
		dazhe();
	}
	void dazhe()
	{
		cout << "˫ʮһ����" << endl;
	}
private:
	ReadlSubject *m_realSubject;
};

int main(void)
{
	Subject *s = new dangdangProxy(new ReadlSubject);
	s->salebook();
	delete s;


	return 0;
}