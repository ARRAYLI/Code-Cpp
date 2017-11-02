#include<iostream>
using namespace std;

class Stratrgy
{
public :
	virtual void crpty() = 0;			// 加密方法
};

// 对称加密   速度快，加密大数据块文件  特点：加密秘钥 和解密秘钥 是一样的
// 非对称加密   加密速度慢   加密强度高   安全性高   特点 ：加密秘钥和解密秘钥不一样   密钥对（公钥和私钥）  

// AES加密算法
class AES:public Stratrgy
{
public:
	virtual void crpty()			// 加密方法
	{
		cout << "AES 加密算法" << endl;
	}
};

// DES加密算法
class DES:public Stratrgy
{
public:
	virtual void crpty()			// 加密方法
	{
		cout << "DES加密 算法" << endl;
	}
};

// 执行算法的环境
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
	// 1、传统的方法 会导致算法写死在客户端 

	DES *des = new DES;

	des->crpty();

	delete des;
	des = NULL;


	// 2、使用策略模式，会接耦合算法和客户端的耦合度 
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