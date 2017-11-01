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

// ��Ԣ���̶�
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

// �������̶�
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

// ���ʦ��ָ���ߣ� �������߼�
// ������  �ɾ���Ļ�
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


	// ��һ����������Ĺ��̶�
	bulider= new VilaBulider;

	// ����� ָ�� ���̶� �ɻ�
	director= new Director(bulider);
	director->Construct();
	house = bulider->GetHouse();
	house->GetWall();
	house->GetFloor();
	house->GetWindow();

	delete house;
	delete director;
	delete bulider;

	// ��һ����Ԣ���̶�
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
		h->setDoor("��");
	}
	
	void bulidWall(House *h)
	{
		h->setWall("ǽ��");
	}

	void bulidWindow(House *h)
	{
		h->setWindow("����");
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
	// �ͻ�ֱ���췿��

	//House *house = new House;
	//house->setDoor("��");
	//house->setWall("ǽ");
	//house->setWindow("����");

	//delete house;
	//house = NULL;

	// �빤�̶ӣ����췿��
	House *house = NULL;
	Bulid *bulid = new Bulid;
	bulid->makeHouse();
	house = bulid->getHouse();

	house->getDoor();
	house->getWall();
	house->getWindow();

	return 0;
}
