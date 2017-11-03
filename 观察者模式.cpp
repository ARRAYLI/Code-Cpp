#include<iostream>
#include<string>
#include<list>
using namespace std;

//  秘书
class Secretary;

// 观察者
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
		cout << "老板来了我很害怕..." << endl;
	}
private:
	Secretary *m_secretary;
};


class Secretary
{
public:
	Secretary()
	{
		m_list.clear();			// 给观察者集合清空
	}
	// 通知事件
	void Notify(string info)      	// 秘书通知所有人消息
	{
		// 给所有的观察者发送信息
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
	list<PlayserObserver*>m_list;			// 观察者集合
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
	secretary->Notify("老板来了");
	secretary->Notify("老板走了");
	
	delete po1;
	delete po2;
	delete  secretary;
	return 0;
}