#include<iostream>
using namespace std;
#include<stack>

// ջģ��
// ջ���㷨   ���������͵ķ���
void test()
{
	//  ��ջ
	stack<int>  s;
	for (int i=0;i<10;i++)
	{
		s.push(i+1);
	}

	cout << "ջ�Ĵ�СΪ��"<<s.size() << endl;

	// ��ջ
	while (!s.empty())
	{
		int tmp = s.top();
		cout <<tmp <<" ";
		s.pop();
	}
	cout << endl;
}

class Teacher
{
public:
	void printT()
	{
		cout <<"age: " <<age << endl;
	}
public:
	int age;
	char name[10];
};

void test1()
{
	Teacher  t1, t2, t3;
	t1.age = 22;
	t2.age = 23;
	t3.age = 24;
	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);

	while (!s.empty())
	{
		Teacher tmp = s.top();
		tmp.printT();
		s.pop();
	}
}


void test2()
{
	Teacher  t1, t2, t3;
	t1.age = 22;
	t2.age = 23;
	t3.age = 24;
	stack<Teacher*> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);

	while (!s.empty())
	{
		Teacher *tmp = s.top();
		tmp->printT();
		s.pop();
	}

}

int main(void)
{
	// test();
	// test1();
	test2();
	return 0;
}