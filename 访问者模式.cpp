/* 案例需求：

比如有一个公园，有一到多个不同的组成部分；该公园存在多个访问者：清洁工A负责打扫公园的A部分，清洁工B负责打扫公园的B部分，
公园的管理者负责检点各项事务是否完成，上级领导可以视察公园等等。也就是说，对于同一个公园，不同的访问者有不同的行为操作，
而且访问者的种类也可能需要根据时间的推移而变化（行为的扩展性）

*/

#include<iostream>
#include<list>
using namespace std;

// 公园的各个部分
class ParkElement;

// 访问者
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


// 公园的A部分
class ParkA :public ParkElement
{
public:
	virtual void accept(Visitor *visit)
	{
		visit->visit(this);			// 公园接受访问者访问 让访问者做操作
	}
};

// 公园的B部分
class ParkB :public ParkElement
{
public:
	virtual void accept(Visitor *visit)
	{
		visit->visit(this);			// 公园接受访问者访问 让访问者做操作
	}
};

// 整个公园
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
	list<ParkElement*> m_list;     // 公园的每一个部分  应该让公园的  每一个部分    都让   管理者访问
};

// 访问者A
class VisitorA :public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "清洁工A  完成公园A部分的 打扫 " << endl;
	}
};

// 访问者A
class VisitorB :public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "清洁工B  完成公园B部分的 打扫 " << endl;
	}
};

// 管理者
class ManagerVisitor :public Visitor
{
public:
	virtual void visit(ParkElement *parkelement)
	{
		cout << "管理员  访问  公园  的各个  部分" << endl;
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