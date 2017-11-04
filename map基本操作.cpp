#include<iostream>
#include<string>
#include<map>
using namespace std;


// map Ԫ�ص����/����/ɾ����������

void test()
{
	map<int,string> map1;

	// ����1
	map1.insert(pair<int,string>(1,"teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	// ����2
	map1.insert(make_pair<int, string>(3, "teacher03"));
	map1.insert(make_pair<int, string>(4, "teacher04"));

	// ����3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	// ����4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	// �����ı���
	for (map<int,string>::iterator it=map1.begin();it!=map1.end();++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "������������" << endl;
	
	// ����Ԫ�ص�ɾ��
	while (!map1.empty())
	{
		map<int, string>::iterator it1 = map1.begin();
		cout << it1->first << "\t" << it1->second << endl;
		map1.erase(it1);
	}
	cout << endl;
}

// ����� 4 �ַ�����ͬ
// ǰ 3 �ַ�������ֵΪ  pair<iterator, bool>			�� key  �Ѵ��� �򱨴�
//	�� 4 �ַ���											��key �Ѵ���  ���޸�

void test1()
{
	map<int, string> map1;

	// typedef pair<iterator, bool> _Pairib;

	// ����1
	pair<map<int, string>::iterator, bool>  mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	// ����2
	pair<map<int, string>::iterator, bool>  mypair3 = map1.insert(pair<int, string>(3, "teacher03"));
//	map1.insert(make_pair<int, string>(3, "teacher03"));
	map1.insert(make_pair<int, string>(4, "teacher05"));

	// ����3
	pair<map<int, string>::iterator, bool>  mypair5 = map1.insert(pair<int, string>(5, "teacher05"));
	if (mypair5.second != true)
	{
		cout << "key 5 ����ʧ��" << endl;
	}
	else
	{
		cout << mypair5.first->first << "\t" << mypair5.first->second << endl;
	}

	//	map1.insert(map<int, string>::value_type(5, "teacher55"));
	pair<map<int, string>::iterator, bool>  mypair6 = map1.insert(map<int, string>::value_type(5, "teacher55"));
	if (mypair6.second != true)
	{
		cout << "key 5 ����ʧ��" << endl;
	}
	else
	{
		cout << mypair6.first->first << "\t" << mypair6.first->second << endl;
	}


	// ����4
	map1[7] = "teacher07";
	map1[7] = "teacher77";

	// �����ı���
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "������������" << endl;

}

void test2()
{
	map<int, string> map1;

	// ����1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	// ����2
	map1.insert(make_pair<int, string>(3, "teacher03"));
	map1.insert(make_pair<int, string>(4, "teacher04"));

	// ����3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	// ����4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	// �����ı���
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "������������" << endl;

	// map �Ĳ���
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "key 100 ��ֵ������" << endl;
	}
	else
	{
		cout << it2->first << "\t" << it2->second << endl;
	}

	// equal_range   // �쳣����
	// typedef pair<iterator, iterator> _Pairii;

	pair<map<int, string>::iterator, map<int, string>::iterator>  maypair2 = map1.equal_range(5);    // ��������������   �γ�һ��pair
	if (maypair2.first == map1.end())
	{
		cout << "��һ�������� ===�� 5 ��λ�ò�����" << endl;
	}
	else
	{
		cout << maypair2.first->first << "\t" << maypair2.first->second << endl;
	}
	if (maypair2.second == map1.end())
	{
		cout << "�ڶ��������� ===�� 5 ��λ�ò�����" << endl;
	}
	else
	{
		cout << maypair2.second->first << "\t" << maypair2.second->second << endl;
	}

}

int main(void)
{
	// test();
	// test1();
	test2();
	return 0;
}