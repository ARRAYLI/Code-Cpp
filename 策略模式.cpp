#include<iostream>
using namespace std;

class Stratrgy
{
public :
	virtual void crpty() = 0;			// ���ܷ���
};

// �ԳƼ���   �ٶȿ죬���ܴ����ݿ��ļ�  �ص㣺������Կ �ͽ�����Կ ��һ����
// �ǶԳƼ���   �����ٶ���   ����ǿ�ȸ�   ��ȫ�Ը�   �ص� ��������Կ�ͽ�����Կ��һ��   ��Կ�ԣ���Կ��˽Կ��  

// AES�����㷨
class AES:public Stratrgy
{
public:
	virtual void crpty()			// ���ܷ���
	{
		cout << "AES �����㷨" << endl;
	}
};

// DES�����㷨
class DES:public Stratrgy
{
public:
	virtual void crpty()			// ���ܷ���
	{
		cout << "DES���� �㷨" << endl;
	}
};

// ִ���㷨�Ļ���
class Context
{
public:
	void setStrategy(Stratrgy *strategy)
	{
		this->m_strategy = strategy;
	}

	void myoperator()
	{
		m_strategy->crpty();
	}
private:
	Stratrgy *m_strategy;
};
int main(void)
{
	// 1����ͳ�ķ��� �ᵼ���㷨д���ڿͻ��� 

	DES *des = new DES;

	des->crpty();

	delete des;
	des = NULL;


	// 2��ʹ�ò���ģʽ���������㷨�Ϳͻ��˵���϶� 
	Stratrgy *strategy = NULL;
	//strategy = new AES;
	strategy = new DES;
	Context *context = new Context;
	context->setStrategy(strategy);
	context->myoperator();

	delete strategy;
	delete context;

	return 0;
}