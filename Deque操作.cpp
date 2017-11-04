#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

void printD(deque<int>& d)
{
	for (deque<int>::iterator it=d.begin();it!=d.end();++it)
	{
		cout <<*it<<"  ";
	}
	cout << endl;
}

void test()
{
	deque<int>  d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);

	d1.push_front(-11);
	d1.push_front(-33);
	d1.push_front(-55);

	cout << "头部元素是：" << d1.front() << endl;
	cout << "尾部元素是：" << d1.back() << endl;
	printD(d1);

	d1.pop_front();
	d1.pop_back();
	printD(d1);

	// 查找  -33 在数组下标的值
	deque<int>::iterator it = find(d1.begin(), d1.end(), -33);				// find() 为查找算法
	if (it != d1.end())
	{
		cout << "-33 在 deque 中的下标是：" <<distance(d1.begin(),it)<< endl;		// distance() 为计算距离算法
	}
	else
	{
		cout << "没有找到 -33 的元素" << endl;
	}
}

int main(void)
{
	test();
	return 0;
}