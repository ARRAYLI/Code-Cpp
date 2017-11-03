#include<iostream>
#include<string>
#include<list>
using namespace std;

//  ����
class Secretary;

// �۲���
class PlayserObserver
{
public:
	PlayserObserver(Secretary *secretary)
	{
		m_secretary = secretary;
	}
	void Update(string action)
	{
		cout << "action: " << action << endl;
		cout << "�ϰ������Һܺ���..." << endl;
	}
private:
	Secretary *m_secretary;
};


class Secretary
{
public:
	Secretary()
	{
		m_list.clear();			// ���۲��߼������
	}
	// ֪ͨ�¼�
	void Notify(string info)      	// ����֪ͨ��������Ϣ
	{
		// �����еĹ۲��߷�����Ϣ
		for (list<PlayserObserver*>::iterator it=m_list.begin();it!=m_list.end();++it)
		{
			(*it)->Update(info);
		}
	}
	void setPlayserObserver(PlayserObserver* o)
	{
		m_list.push_back(o);
	}
private:
	list<PlayserObserver*>m_list;			// �۲��߼���
};


int main(void)
{
	Secretary			*secretary = NULL;
	PlayserObserver		*po1 = NULL;
	PlayserObserver		*po2 = NULL;

	secretary = new Secretary;
	po1 = new PlayserObserver(secretary);
	po2 = new PlayserObserver(secretary);

	secretary->setPlayserObserver(po1);
	secretary->setPlayserObserver(po2);
	secretary->Notify("�ϰ�����");
	secretary->Notify("�ϰ�����");
	
	delete po1;
	delete po2;
	delete  secretary;
	return 0;
}