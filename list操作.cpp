#include<iostream>
#include<list>
using namespace std;

// list�Ļ�������
void test()
{
	list<int>   l;
	cout << "list �Ĵ�С��"<<l.size() << endl;

	for (int i=0;i<10;i++)
	{
		l.push_back(i);			// β������Ԫ��    β�巨 
	}
	cout << "list �Ĵ�С��" << l.size() << endl;
	
	list<int>::iterator it = l.begin();

	while (it!=l.end())
	{
		cout << *it<<" ";
		++it;
	}
	cout << endl;

	// list �����������
	// 0   1   2   3   4   5   6    7
	//            ��

	it = l.begin();
	it++;
	it++;
	it++;

	// it=it+5;		// ����֧������ķ�������
	l.insert(it,100);			// 100 ���뵽 l �������ĸ�λ����?

	for (list<int>::iterator it=l.begin();it!=l.end();++it)
	{
		cout << *it<<"  ";
	}

	cout << endl;
	// ����1   ����Ľ��index,����Ǵ�  0 ��λ�ÿ�ʼ��
	// ��  3 ��λ�ò���Ԫ��  ��ԭ����3 ��λ�ñ��4��   ԭ����4��λ�ñ�� 5��λ��

}

// list ��ɾ��

void test1()
{
	list<int>   l;
	cout << "list �Ĵ�С��" << l.size() << endl;

	for (int i = 0; i<10; i++)
	{
		l.push_back(i);			// β������Ԫ��    β�巨 
	}
	cout << "list �Ĵ�С��" << l.size() << endl;

	list<int>::iterator it1 = l.begin();
	list<int>::iterator it2 = l.begin();
	it2++;
	it2++;
	it2++;

	l.erase(it1,it2);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << "  ";
	}

	cout << endl;

	l.insert(l.begin(),100);
	l.insert(l.begin(), 100);
	l.insert(l.begin(), 100);
	l.erase(l.begin());				// ɾ��list �����е��׸�Ԫ��
	l.remove(100);					// ɾ��list �����е�����ֵΪ100��Ԫ��
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << "  ";
	}

	cout << endl;

}

int main(void)
{
	//  test();
	test1();

	return 0;
}