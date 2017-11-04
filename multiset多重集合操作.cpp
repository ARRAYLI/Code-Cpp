#include<iostream>
#include<set>
using namespace std;

void test()
{
	multiset<int>  mulset;
	int tmp = 0;

	cout << "请输入multimset集合的值：" << endl;
	cin >> tmp;
	while (tmp!=0)
	{
		mulset.insert(tmp);
		cout << "请输入multimset集合的值：" << endl;
		cin >> tmp;
	}

	// 遍历
	for (multiset<int>::iterator it=mulset.begin();it!=mulset.end();++it)
	{
		cout << *it<<"  ";
	}
	cout << endl;

	// 删除
	while (!mulset.empty())
	{
		multiset<int>::iterator it = mulset.begin();
		cout <<*it <<"  ";
		mulset.erase(it);
	}
	cout << endl;
}

int main(void)
{
	test();
	return 0;
}