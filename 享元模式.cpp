#include<iostream>
#include<string>
#include<map>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_name = name;
		this->m_age = age;
	}
	virtual void prinT() = 0;
protected:
	string m_name;
	int		m_age;
};

class Teacher :public Person
{
public:
	Teacher(string name, int age, string id) :Person(name, age)
	{
		this->m_id = id;
	}

	void prinT()
	{
		cout << "m_name: "<<m_name<<",m_age: "<<m_age<<",m_id:"<<m_age << endl;
	}
private:
	string m_id;
};

class  FlyWeightTeacherFactor
{
public:
	FlyWeightTeacherFactor()
	{
		map1.clear();
	}

	~FlyWeightTeacherFactor()
	{
		while (!map1.empty())
		{
			Person *tmp = NULL;
			
			map<string, Person*>::iterator it = map1.begin();

			tmp = it->second;

			map1.erase(it);     // 把第一个节点从容器中删除

		}
	}
	Person *GetTeacher(string id)
	{	
		Person *tmp = NULL;
		map<string, Person*>::iterator it;
		it= map1.find(id);
		if (it==map1.end())
		{
			string tmpname;
			int tmpage;

			cout <<"\n请输入老师名字name:";
			cin >> tmpname;
			cout << "请输入老师的age:";
			cin >> tmpage;

			tmp = new Teacher(tmpname,tmpage,id);
			map1.insert(pair<string,Person*>(id,tmp));
		}
		else
		{
			tmp = it->second;
		}
		return tmp;
	}
protected:

private:
	map<string, Person*> map1;
};

int main(void)
{
	Person* p1 = NULL;
	Person* p2 = NULL;
	FlyWeightTeacherFactor *fwtf = new FlyWeightTeacherFactor;
	p1=fwtf->GetTeacher("001");
	p1->prinT();

	p2 = fwtf->GetTeacher("001");
	p2->prinT();

	delete fwtf;
	fwtf = NULL;

	return 0;
}