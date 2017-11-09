#include<iostream>
using namespace std;

class Student
{
public:
	Student(char *name)
	{
		m_len = strlen(name) + 1;
		m_name = new char[m_len];
		strcpy(m_name, name);

	}
	// 拷贝构造函数
	// Student s2 = s2;     
	Student(const Student &obj)
	{
		m_len = obj.m_len;
		m_name = new char[m_len];
		strcpy(m_name,obj.m_name);
	}

	// = 会造成内存泄漏
	void operator=(Student &obj)
	{
		// 释放之前的内存空间
		if (obj.m_name!=NULL)
		{
			delete m_name;
			m_name = NULL;
			m_len = 0;
		}
		// 重新分配内存空间
		m_len = obj.m_len;
		m_name = new char[obj.m_len];
		strcpy(m_name,obj.m_name);
	}

	~Student()
	{
		if (NULL!=m_name)
		{
			delete m_name;
			m_name = NULL;
			m_len = 0;
		}
	}

private:
	char	*m_name;
	int		m_len;
};

void Copy()
{
	Student s1("abc");
	Student s2 = s1;     // 用一个对象去初始化另一个新的同类型对象
	// 析构时，先析构s2,后析构s1,此时出现core down

	// = 会造成内存泄漏
	Student s3("");
	s3 = s1;
}

int main(void)
{
	// Copy();
	char *p = new char[4];
	strcpy(p,"abc");
	cout << p << endl;
	int a = 0;
	return 0;
}

/*

深拷贝：当对象中含有指针域的时候，在对象之间进行初始化（即调用对象的拷贝构造函数）或者是 = 操作符的时候，将对象内的指针
		所包含的内存空间中的内容也进行拷贝。
浅拷贝：当对象中含有指针域的时候，在对象之间进行初始化（即调用对象的拷贝构造函数）或者是 = 操作符的时候，单纯的将指针的值（也就是所指内存空间的首地址）进行拷贝
		这就导致两个对象的指针域是同一块内存空间，所以在对象生命周期完毕时，调用析构函数，释放内存的时候会出现code down的情况
原因分析：
		因为C++默认的拷贝构造函数和 = 操作都是浅拷贝操作，即只是将指针进行赋值
解决方案：重写类的拷贝构造函数 和 = 运算符

需要注意的点：

		1. 深拷贝和浅拷贝发生发生在类成员中包含有指针域的时候。

		2. =操作符和对象的初始化是两种不同的东西！

		3. 特别注意：在进行等号操作重载的时，先将原来的内存空间释放，（内存泄漏）
*/


// 此时这里的对象s2的指针应该进行深拷贝，动态分配内存空间，然后进行赋值，而不只是把 s1 的指针赋值给 s2 让它们指向同一块内存空间