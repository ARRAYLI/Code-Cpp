#include<iostream>
#include<string>
#include<map>
using namespace std;

// Multimap 案例 :
// 1个key值可以对应多个valude  =分组 
// 公司有销售部 sale （员工2名）、技术研发部 development （1人）、财务部 Financial （2人） 
// 人员信息有：姓名，年龄，电话、工资等组成
// 通过 multimap进行 信息的插入、保存、显示
// 分部门显示员工信息 

class Person
{
public:
	Person()
	{
	
	}
	Person(string name,int age,string tel="",double sal=0.0)
	{
		this->name = name;
		this->age = age;
		this->tel = tel;
		this->salary =sal;
	}
	~Person()
	{
	
	}

	string	name;
	int		age;
	string  tel;
	double  salary;
};

void test()
{
	Person p1("王1",31,"18892139133",5000);
	Person p2("王2", 32,"15902356458",6000);
	Person p3("张3", 33,"13543689412",4500);
	Person p4("赵4", 34,"18756234100",8000);
	Person p5("赵5", 35,"18795345211",12000);

	multimap<string, Person>  mulmap;

	// sale 部门
	mulmap.insert(make_pair("sale",p1));
	mulmap.insert(make_pair("sale", p2));

	// development 部门
	mulmap.insert(make_pair("development",p3));

	// Financial 部门
	mulmap.insert(make_pair("Financial",p4));
	mulmap.insert(make_pair("Financial", p5));

	// 按照条件   检索数据   进行修改
	for (multimap<string,Person>::iterator it=mulmap.begin();it!=mulmap.end();++it)
	{
		if (it->second.age == 32)
		{
			it->second.name = "name32";
		}
		//cout << it->second.name << "\t" << it->second.age << "\t" << it->second.salary << "\t" << it->second.tel << endl;
	}

	// 遍历容器
	for (multimap<string, Person>::iterator it = mulmap.begin(); it != mulmap.end(); ++it)
	{
		cout << it->second.name << "\t" << it->second.age << "\t" << it->second.salary << "\t" << it->second.tel << endl;
	}
}

int main(void)
{
	test();

	return 0;
}