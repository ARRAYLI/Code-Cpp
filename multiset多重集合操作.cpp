#include<iostream>
#include<set>
using namespace std;

void test()
{
	multiset<int>  mulset;
	int tmp = 0;

	cout << "������multimset���ϵ�ֵ��" << endl;
	cin >> tmp;
	while (tmp!=0)
	{
		mulset.insert(tmp);
		cout << "������multimset���ϵ�ֵ��" << endl;
		cin >> tmp;
	}

	// ����
	for (multiset<int>::iterator it=mulset.begin();it!=mulset.end();++it)
	{
		cout << *it<<"  ";
	}
	cout << endl;

	// ɾ��
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