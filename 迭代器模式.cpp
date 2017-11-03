#include<iostream>
using namespace std;

typedef int Object;							// ģ�����
#define SIZE   5

// ����ĵ�����
class MyIterator
{
public:
	virtual void First() = 0;				// �������Ŀ�ʼλ��
	virtual void Next() = 0;				// �������Ե���һ��λ��
	virtual bool isDone() = 0;				// �������Ľ���λ��
	virtual Object CurrentItem() = 0;		// ��ȡ��ǰ����
};

// ��������  ����
class Aggreagate
{
public:
	virtual MyIterator*CreateIteator() = 0;	// ����������
	virtual Object getItem(int index) = 0;	//	��ȡԪ��
	virtual int getSize() = 0;				// ��ȡ�������Ĵ�С
private:
	Object objecct[SIZE];
};

// ����ĵ�����
class  ContreteIterator :public MyIterator
{
public:
	ContreteIterator(Aggreagate *ag)
	{
		_current_index = 0;
		_ag = ag;
	}
	virtual void First()				// �������Ŀ�ʼλ��
	{
		_current_index = 0;				// �õ�ǰ �α�λ�� �ص�0
	}
		
	virtual void Next()					// �������Ե���һ��λ��
	{
		if (_current_index < _ag->getSize())
		{
			_current_index++;
		}
	}
	virtual bool isDone()				// �������Ľ���λ��
	{
		return (_current_index == _ag->getSize());
	}
	virtual Object CurrentItem() 		// ��ȡ��ǰ����
	{
		return _ag->getItem(_current_index);
	}
private:
	int			_current_index;
	Aggreagate	*_ag;
};


// ����ļ���
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
	virtual MyIterator*CreateIteator()	// ����������
	{
		return new ContreteIterator(this);			//�õ�����  ����һ�����ϵ�����
	}
	virtual Object getItem(int index)	//	��ȡԪ��
	{
		return objecct[index];
	}
	virtual int getSize()				// ��ȡ�������Ĵ�С
	{
		return SIZE;
	}
private:
	Object objecct[SIZE];
};

int main(void)
{
	// new һ������
	Aggreagate *ag = new ContreteAggreagate;

	// ����һ��������
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