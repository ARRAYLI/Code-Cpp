#include<iostream>
using namespace std;

// ��Computer��ܺ;���ĳ��̽��н����

class HardDisk
{
public:
	virtual void work() = 0;
private:
};

class Mem
{
public:
	virtual void work() = 0;
};

class Cpu
{
public:
	virtual void work() = 0;
private:
};

class InterCpu :public Cpu
{
public:
	virtual void work()
	{
		cout << "����Inter���ҹ�������" << endl;
	}
};

class JSD :public Mem
{
public:
	virtual void work()
	{
		cout << "���ǽ�ʿ�٣��ҹ�������" << endl;
	}
};

class HSD :public HardDisk
{
public:
	virtual void work()
	{
		cout << "�������գ��ҹ�������" << endl;
	}
};

class Computer
{
public:
	// HardDisk
	// Mem
	// Cpu
	Computer(HardDisk *harddisk, Mem *mem, Cpu *cpu)
	{
		m_harddisk = harddisk;
		m_cpu = cpu;
		m_mem = mem;
	}

	void work()
	{
		m_harddisk->work();
		m_mem->work();
		m_cpu->work();
	}
private:
	HardDisk *m_harddisk;
	Cpu	     *m_cpu;
	Mem		 *m_mem;
};

class A
{
public:
	void doA()
	{
	}
	void doB()
	{
	}
};

class B:public A 
{
public:
	void doB()
	{
	}

private:

};

class C
{
public:
	C(A*a)
	{
	}
	void setA(A *a)
	{
		this->a = a;
	}
private:
	A *a;
};


int main(void)
{
	HardDisk *hd = NULL;
	Mem *mem = NULL;
	Cpu *cpu = NULL;
	hd = new HSD;
	mem = new JSD;
	cpu = new InterCpu;
	Computer *cp = new Computer(hd,mem,cpu);
	cp->work();

	delete cp;
	delete cpu;
	delete mem;
	delete hd;
	return 0;
}