#include<iostream>
using namespace std;

typedef int Object;							// 模拟对象
#define SIZE   5

// 抽象的迭代器
class MyIterator
{
public:
	virtual void First() = 0;				// 迭代器的开始位置
	virtual void Next() = 0;				// 迭代器对的下一个位置
	virtual bool isDone() = 0;				// 迭代器的结束位置
	virtual Object CurrentItem() = 0;		// 获取当前对象
};

// 抽象容器  数组
class Aggreagate
{
public:
	virtual MyIterator*CreateIteator() = 0;	// 创建迭代器
	virtual Object getItem(int index) = 0;	//	获取元素
	virtual int getSize() = 0;				// 获取迭代器的大小
private:
	Object objecct[SIZE];
};

// 具体的迭代器
class  ContreteIterator :public MyIterator
{
public:
	ContreteIterator(Aggreagate *ag)
	{
		_current_index = 0;
		_ag = ag;
	}
	virtual void First()				// 迭代器的开始位置
	{
		_current_index = 0;				// 让当前 游标位置 回到0
	}
		
	virtual void Next()					// 迭代器对的下一个位置
	{
		if (_current_index < _ag->getSize())
		{
			_current_index++;
		}
	}
	virtual bool isDone()				// 迭代器的结束位置
	{
		return (_current_index == _ag->getSize());
	}
	virtual Object CurrentItem() 		// 获取当前对象
	{
		return _ag->getItem(_current_index);
	}
private:
	int			_current_index;
	Aggreagate	*_ag;
};


// 具体的集合
class ContreteAggreagate :public Aggreagate
{
public:
	ContreteAggreagate()
	{
		for (int i=0;i<SIZE;i++)
		{
			objecct[i] = i+100;
		}
	}
	virtual MyIterator*CreateIteator()	// 创建迭代器
	{
		return new ContreteIterator(this);			//让迭代器  持有一个集合的引用
	}
	virtual Object getItem(int index)	//	获取元素
	{
		return objecct[index];
	}
	virtual int getSize()				// 获取迭代器的大小
	{
		return SIZE;
	}
private:
	Object objecct[SIZE];
};

int main(void)
{
	// new 一个集合
	Aggreagate *ag = new ContreteAggreagate;

	// 创建一个迭代器
	MyIterator	*it = ag->CreateIteator();

	for (;(!it->isDone());it->Next())
	{
		cout << it->CurrentItem() << "  ";
	}
	cout << endl;
	delete ag;
	delete it;
	return 0;
}