#if 0
#include<iostream>
#include<string>
using namespace std;

class House
{
public:
	void setWall(string wall)
	{
		m_wall = wall;
	}
	void setFloor(string floor)
	{
		m_floor = floor;
	}

	void setWindow(string window)
	{
		m_window = window;
	}

	string GetWall()
	{
		cout << m_wall << endl;
		return m_wall;
	}

	string GetFloor()
	{
		cout << m_floor << endl;
		return m_floor;
	}
	string GetWindow()
	{
		cout << m_window << endl;
		return m_window;
	}
private:
	string m_wall;
	string m_floor;
	string m_window;
};

class Bulider
{
public:
	virtual void bulidWall() = 0;
	virtual void bulidFloor() = 0;
	virtual void bulidWindow() = 0;
	virtual House* GetHouse() =0;
};

// 公寓工程队
class FlatBulider:public Bulider
{
public:
	FlatBulider()
	{
		m_house = new House;
	}
	virtual void bulidWall()
	{
		m_house->setWall("flat wall");
	}
	virtual void bulidFloor()
	{
		m_house->setFloor("flat floor");
	}
	virtual void bulidWindow()
	{
		m_house->setWindow("flat window");
	}
	virtual House* GetHouse()
	{
		return m_house;
	}
private:
	House  *m_house;
};

// 别墅工程队
class VilaBulider :public Bulider
{
public:
	VilaBulider()
	{
		m_house = new House;
	}
	virtual void bulidWall()
	{
		m_house->setWall("vila wall");
	}
	virtual void bulidFloor()
	{
		m_house->setFloor("vila floor");
	}
	virtual void bulidWindow()
	{
		m_house->setWindow("vila window");
	}
	virtual House* GetHouse()
	{
		return m_house;
	}
private:
	House  *m_house;
};

// 设计师（指挥者） 负责建造逻辑
// 建筑队  干具体的话
class Director
{
public:
	Director(Bulider* bulid)
	{
		m_bulid = bulid;
	}
	void Construct()
	{
		m_bulid->bulidWall();
		m_bulid->bulidFloor();
		m_bulid->bulidWindow();
	}
private:
	Bulider* m_bulid;
};
int main(void)
{
	House *house = NULL;
	Bulider *bulider = NULL;
	Director *director = NULL;
	VilaBulider *vilaBulider = NULL;


	// 请一个建造别墅的工程队
	bulider= new VilaBulider;

	// 设计者 指挥 工程队 干活
	director= new Director(bulider);
	director->Construct();
	house = bulider->GetHouse();
	house->GetWall();
	house->GetFloor();
	house->GetWindow();

	delete house;
	delete director;
	delete bulider;

	// 请一个公寓工程队
	bulider = new FlatBulider;

	director = new Director(bulider);
	director->Construct();
	house = bulider->GetHouse();
	house->GetWall();
	house->GetFloor();
	house->GetWindow();

	delete house;
	delete director;
	delete bulider;
	return 0;
}
#endif


#include<iostream>
#include<string>
using namespace std;

class House
{
public:
	void setDoor(string door)
	{
		m_door = door;
	}
	void setWall(string wall)
	{
		m_wall = wall;
	}
	void setWindow(string window)
	{
		m_window = window;
	}
	
	string getDoor()
	{
		cout << m_door << endl;
		return m_door;
	}
	string getWall()
	{
		cout << m_wall << endl;
		return m_wall;
	}
	string getWindow()
	{
		cout << m_window << endl;
		return m_window;
	}
private:
	string m_door;
	string m_wall;
	string m_window;
};

class Bulid
{
public:
	Bulid()
	{
		m_house = new House;
	}

	void makeHouse()
	{
		bulidDoor(m_house);
		bulidWall(m_house);
		bulidWindow(m_house);
	}
	void bulidDoor(House *h)
	{
		h->setDoor("门");
	}
	
	void bulidWall(House *h)
	{
		h->setWall("墙面");
	}

	void bulidWindow(House *h)
	{
		h->setWindow("窗户");
	}

	House *getHouse()
	{
		return m_house;
	}

private:
	House *m_house;
};

int main(void)
{
	// 客户直接造房子

	//House *house = new House;
	//house->setDoor("门");
	//house->setWall("墙");
	//house->setWindow("窗口");

	//delete house;
	//house = NULL;

	// 请工程队，建造房子
	House *house = NULL;
	Bulid *bulid = new Bulid;
	bulid->makeHouse();
	house = bulid->getHouse();

	house->getDoor();
	house->getWall();
	house->getWindow();

	return 0;
}
