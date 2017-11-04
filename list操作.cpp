#include<iostream>
#include<list>
using namespace std;

// list的基本操作
void test()
{
	list<int>   l;
	cout << "list 的大小："<<l.size() << endl;

	for (int i=0;i<10;i++)
	{
		l.push_back(i);			// 尾部插入元素    尾插法 
	}
	cout << "list 的大小：" << l.size() << endl;
	
	list<int>::iterator it = l.begin();

	while (it!=l.end())
	{
		cout << *it<<" ";
		++it;
	}
	cout << endl;

	// list 不能随机访问
	// 0   1   2   3   4   5   6    7
	//            ▲

	it = l.begin();
	it++;
	it++;
	it++;

	// it=it+5;		// 不能支持随机的访问容器
	l.insert(it,100);			// 100 插入到 l 容器的哪个位置了?

	for (list<int>::iterator it=l.begin();it!=l.end();++it)
	{
		cout << *it<<"  ";
	}

	cout << endl;
	// 结论1   链表的结点index,序号是从  0 号位置开始的
	// 在  3 号位置插入元素  让原来的3 号位置变成4号   原来的4号位置变成 5号位置

}

// list 的删除

void test1()
{
	list<int>   l;
	cout << "list 的大小：" << l.size() << endl;

	for (int i = 0; i<10; i++)
	{
		l.push_back(i);			// 尾部插入元素    尾插法 
	}
	cout << "list 的大小：" << l.size() << endl;

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
	l.erase(l.begin());				// 删除list 容器中的首个元素
	l.remove(100);					// 删除list 容器中的所有值为100的元素
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