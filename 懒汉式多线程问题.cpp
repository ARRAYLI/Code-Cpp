// 03����ʽ���߳�����.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include<Windows.h>
#include<process.h>
#include<iostream>
using namespace std;


// ����ʽ����ģʽ

// ���캯�������̰߳�ȫ����

class Singleton
{
private:
	Singleton()
	{
		cout << "Singleton  ���캯��ִ�� begin" << endl;
		Sleep(1000);
		cout << "Singleton  ���캯��ִ�� end" << endl;
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

// ��̬��Ա���������ʼ��
Singleton* Singleton::m_psl = NULL;
int *Singleton::m_count = 0;
void test()
{
	Singleton *p1 = Singleton::getInstance();
	Singleton *p2 = Singleton::getInstance();

	if (p1 == p2)
	{
		cout << "��ͬһ������" << endl;
	}
	else
	{
		cout << "����ͬһ������" << endl;
	}
	Singleton::FreeSingleton();

}

void MyThreadFunc(void *)
{
//	cout << "�����߳���..." << endl;
	cout << "�����߳���...\n";
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


