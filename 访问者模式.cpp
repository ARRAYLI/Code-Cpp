/* ��������

������һ����԰����һ�������ͬ����ɲ��֣��ù�԰���ڶ�������ߣ���๤A�����ɨ��԰��A���֣���๤B�����ɨ��԰��B���֣�
��԰�Ĺ����߸�������������Ƿ���ɣ��ϼ��쵼�����Ӳ칫԰�ȵȡ�Ҳ����˵������ͬһ����԰����ͬ�ķ������в�ͬ����Ϊ������
���ҷ����ߵ�����Ҳ������Ҫ����ʱ������ƶ��仯����Ϊ����չ�ԣ�

*/

#include<iostream>
#include<list>
using namespace std;

// ��԰�ĸ�������
class ParkElement;

// ������
class Visitor
{
public:
	virtual void visit(ParkElement *parkelement) = 0;
};

class ParkElement
{
public:
	virtual void accept(Visitor *visit) = 0;
};


// ��԰��A����
class ParkA :public ParkElement
{
public:
	virtual void accept(Visitor *visit)
	{
		visit->visit(this);			// ��԰���ܷ����߷��� �÷�����������
	}
};

// ��԰��B����
class ParkB :public ParkElement
{
public:
	virtual void accept(Visitor *visit)
	{
		visit->visit(this);			// ��԰���ܷ����߷��� �÷�����������
	}
};

// ������԰
class Park :public ParkElement
{
public:
	Park()
	{
		m_list.clear();
	}
	void setParkElement(ParkElement* pe)
	{
		m_list.push_back(pe);
	}
	virtual void accept(Visitor *visit)
	{
		for (list<ParkElement*>::iterator it=m_list.begin();it!=m_list.end();++it)
		{
			(*it)->accept(visit);
		}
	}
private:
	list<ParkElement*> m_list;     // ��԰��ÿһ������  Ӧ���ù�԰��  ÿһ������    ����   �����߷���
};

// ������A
class VisitorA :public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "��๤A  ��ɹ�԰A���ֵ� ��ɨ " << endl;
	}
};

// ������A
class VisitorB :public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "��๤B  ��ɹ�԰B���ֵ� ��ɨ " << endl;
	}
};

// ������
class ManagerVisitor :public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "����Ա  ����  ��԰  �ĸ���  ����" << endl;
	}
};

void test1()
{
	Visitor *vA = new VisitorA;
	Visitor *vB = new VisitorB;
		
	ParkA*  parkA = new ParkA;
	ParkB*	parkB = new ParkB;

	parkA->accept(vA);
	parkB->accept(vB);

	delete vA;
	delete vB;
	delete parkA;
	delete parkB;
}

void test2()
{
	Visitor* vManager = new  ManagerVisitor;
	Park*  park = new Park;
	
	ParkElement *parkA = new ParkA;
	ParkElement *parkB = new ParkB;

	park->setParkElement(parkA);
	park->setParkElement(parkB);

	park->accept(vManager);

	delete vManager;
	delete park;
	delete parkA;
	delete parkB;

}


int main(void)
{
	// test1();
	test2();
	return 0;
}