#include<iostream>
using namespace std;

class Context
{ 
public:
	Context(int num)
	{
		m_num = num;
	}
	int getNum()
	{
		return m_num;
	}

	int getRes()
	{
		return m_res;
	}
	void setNum(int num)
	{
		m_num = num;
	}
	void setRes(int res)
	{
		m_res = res;
	}
private:
	int m_num;
	int m_res;
};


class Expression
{
public:
	virtual void interpreter(Context *context) = 0;

private:
	Context *m_contex;
};

// ¼Ó·¨
class PlusExpression :public Expression
{
public:
	PlusExpression()
	{
	
	}
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		num++;
		context->setNum(num);
		context->setRes(num);
	}
};

// ¼õ·¨
class SubExpression :public Expression
{
public:
	SubExpression()
	{

	}
	virtual void interpreter(Context *context)
	{
		int num = context->getNum();
		num--;
		context->setNum(num);
		context->setRes(num);
	}
};

int main(void)
{
	Expression *expression = NULL;
	Expression *expression2 = NULL;
	Context		*contex = NULL;
	
	contex = new Context(10);
	cout << contex->getNum() << endl;

	expression = new PlusExpression;
	expression->interpreter(contex);
	cout << contex->getNum() << endl;

	expression2 = new SubExpression;
	expression2->interpreter(contex);
	cout << contex->getNum() << endl;

	delete expression;
	delete expression2;
	delete contex;
	return 0;
}