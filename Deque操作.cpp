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

	cout << "ͷ��Ԫ���ǣ�" << d1.front() << endl;
	cout << "β��Ԫ���ǣ�" << d1.back() << endl;
	printD(d1);

	d1.pop_front();
	d1.pop_back();
	printD(d1);

	// ����  -33 �������±��ֵ
	deque<int>::iterator it = find(d1.begin(), d1.end(), -33);				// find() Ϊ�����㷨
	if (it != d1.end())
	{
		cout << "-33 �� deque �е��±��ǣ�" <<distance(d1.begin(),it)<< endl;		// distance() Ϊ��������㷨
	}
	else
	{
		cout << "û���ҵ� -33 ��Ԫ��" << endl;
	}
}

int main(void)
{
	test();
	return 0;
}