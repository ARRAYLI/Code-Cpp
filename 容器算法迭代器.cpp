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

// ������װ �������͵�Ԫ��
void test()
{
	vector<int>  v;			// ����    �����Ԫ��copy��������
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(3);

	// 1 3 5 3 

	// ������   �൱��һ��ָ��  ����

	for (vector<int>::iterator it=v.begin();it!=v.end();++it)
	{
		cout << *it << "   ";
	}
	
//		�㷨  ���vector�����е����� 3 �ĸ���
	/// �㷨  �㷨�͵�����    �����޷������

	int num = count(v.begin(),v.end(),3);

	cout << "num: = "<<num << endl;
}

// ������װ�����͵�Ԫ��
void test1()
{
	Teacher t1, t2, t3;
	vector<Teacher>  v;			// ����    �����Ԫ��copy��������
	t1.age = 30;
	t2.age = 32;
	t3.age = 33;
	
	v.push_back(t1);
	v.push_back(t2);
	v.push_back(t3);

	// 1 3 5 3 

	// ������   �൱��һ��ָ��  ����

	for (vector<Teacher>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << it->age << "   ";
	}

	//		�㷨  ���vector�����е����� 3 �ĸ���
	/// �㷨  �㷨�͵�����    �����޷������
}

// ������װָ�����͵�Ԫ��
void test2()
{

	Teacher t1, t2, t3;
	vector<Teacher*>  v;			// ����    �����Ԫ��copy��������
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

	// ������   �൱��һ��ָ��  ����

	for (vector<Teacher*>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it)->age << "   ";
	}

	//		�㷨  ���vector�����е����� 3 �ĸ���
	/// �㷨  �㷨�͵�����    �����޷������
}
int main(void)
{
	// test();
	// test1();
	test2();
	return 0;
}