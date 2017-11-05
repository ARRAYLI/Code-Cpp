#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Teacher
{
public:
	void printT()
	{
		cout << "age: " <<age<< endl;
	}
public:
	int age;
	char name[10];
};

// 容器中装 基本类型的元素
void test()
{
	vector<int>  v;			// 容器    把你的元素copy到容器中
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(3);

	// 1 3 5 3 

	// 迭代器   相当于一个指针  分类

	for (vector<int>::iterator it=v.begin();it!=v.end();++it)
	{
		cout << *it << "   ";
	}
	
//		算法  求出vector容器中的数字 3 的个数
	/// 算法  算法和迭代器    进行无缝的连接

	int num = count(v.begin(),v.end(),3);

	cout << "num: = "<<num << endl;
}

// 容器中装类类型的元素
void test1()
{
	Teacher t1, t2, t3;
	vector<Teacher>  v;			// 容器    把你的元素copy到容器中
	t1.age = 30;
	t2.age = 32;
	t3.age = 33;
	
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	// 1 3 5 3 

	// 迭代器   相当于一个指针  分类

	for (vector<Teacher>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << it->age << "   ";
	}

	//		算法  求出vector容器中的数字 3 的个数
	/// 算法  算法和迭代器    进行无缝的连接
}

// 容器中装指针类型的元素
void test2()
{

	Teacher t1, t2, t3;
	vector<Teacher*>  v;			// 容器    把你的元素copy到容器中
	t1.age = 30;
	t2.age = 32;
	t3.age = 33;


	Teacher *p1, *p2, *p3;
	p1 = &t1;
	p2 = &t2;
	p3 = &t3;

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	// 1 3 5 3 

	// 迭代器   相当于一个指针  分类

	for (vector<Teacher*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->age << "   ";
	}

	//		算法  求出vector容器中的数字 3 的个数
	/// 算法  算法和迭代器    进行无缝的连接
}
int main(void)
{
	// test();
	// test1();
	test2();
	return 0;
}