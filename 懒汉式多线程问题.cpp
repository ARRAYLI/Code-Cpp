// 03懒汉式多线程问题.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include<Windows.h>
#include<process.h>
#include<iostream>
using namespace std;


// 懒汉式单例模式

// 构造函数不是线程安全函数

class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton  构造函数执行 begin" << endl;
		Sleep(1000);
		cout << "Singleton  构造函数执行 end" << endl;
	}
public:
	static	Singleton *getInstance()
	{
		if (NULL == m_psl)
		{
			m_count++;
			m_psl = new Singleton;
		}
		return m_psl;
	}
	static void FreeSingleton()
	{
		if (NULL != m_psl)
		{
			delete m_psl;
			m_psl = NULL;
		}
	}
	void printS()
	{
		cout << "Singleton printS test" << endl;
	}
private:
	static Singleton *m_psl;
	static int *m_count;
};

// 静态成员变量类外初始化
Singleton* Singleton::m_psl = NULL;
int *Singleton::m_count = 0;
void test()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	if (p1 == p2)
	{
		cout << "是同一个对象" << endl;
	}
	else
	{
		cout << "不是同一个对象" << endl;
	}
	Singleton::FreeSingleton();

}

void MyThreadFunc(void *)
{
//	cout << "我是线程体..." << endl;
	cout << "我是线程体...\n";
	Singleton::getInstance()->printS();
}

int main()
{		  
	HANDLE hThread[10];
	for (int i=0;i<3;i++)
	{
		hThread[i] = (HANDLE)_beginthread(MyThreadFunc,0,NULL);
	}

	for (int i=0;i<3;i++)
	{
		WaitForSingleObject(hThread[i],INFINITE);
	}

	cout << "hello" << endl;
    return 0;
}


