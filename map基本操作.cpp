#include<iostream>
#include<string>
#include<map>
using namespace std;


// map 元素的添加/遍历/删除基本操作

void test()
{
	map<int,string> map1;

	// 方法1
	map1.insert(pair<int,string>(1,"teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	// 方法2
	map1.insert(make_pair<int, string>(3, "teacher03"));
	map1.insert(make_pair<int, string>(4, "teacher04"));

	// 方法3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	// 方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	// 容器的遍历
	for (map<int,string>::iterator it=map1.begin();it!=map1.end();++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "容器遍历结束" << endl;
	
	// 容器元素的删除
	while (!map1.empty())
	{
		map<int, string>::iterator it1 = map1.begin();
		cout << it1->first << "\t" << it1->second << endl;
		map1.erase(it1);
	}
	cout << endl;
}

// 插入的 4 种方法异同
// 前 3 种方法返回值为  pair<iterator, bool>			若 key  已存在 则报错
//	第 4 种方法											若key 已存在  则修改

void test1()
{
	map<int, string> map1;

	// typedef pair<iterator, bool> _Pairib;

	// 方法1
	pair<map<int, string>::iterator, bool>  mypair1 = map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	// 方法2
	pair<map<int, string>::iterator, bool>  mypair3 = map1.insert(pair<int, string>(3, "teacher03"));
//	map1.insert(make_pair<int, string>(3, "teacher03"));
	map1.insert(make_pair<int, string>(4, "teacher05"));

	// 方法3
	pair<map<int, string>::iterator, bool>  mypair5 = map1.insert(pair<int, string>(5, "teacher05"));
	if (mypair5.second != true)
	{
		cout << "key 5 插入失败" << endl;
	}
	else
	{
		cout << mypair5.first->first << "\t" << mypair5.first->second << endl;
	}

	//	map1.insert(map<int, string>::value_type(5, "teacher55"));
	pair<map<int, string>::iterator, bool>  mypair6 = map1.insert(map<int, string>::value_type(5, "teacher55"));
	if (mypair6.second != true)
	{
		cout << "key 5 插入失败" << endl;
	}
	else
	{
		cout << mypair6.first->first << "\t" << mypair6.first->second << endl;
	}


	// 方法4
	map1[7] = "teacher07";
	map1[7] = "teacher77";

	// 容器的遍历
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "容器遍历结束" << endl;

}

void test2()
{
	map<int, string> map1;

	// 方法1
	map1.insert(pair<int, string>(1, "teacher01"));
	map1.insert(pair<int, string>(2, "teacher02"));

	// 方法2
	map1.insert(make_pair<int, string>(3, "teacher03"));
	map1.insert(make_pair<int, string>(4, "teacher04"));

	// 方法3
	map1.insert(map<int, string>::value_type(5, "teacher05"));
	map1.insert(map<int, string>::value_type(6, "teacher06"));

	// 方法4
	map1[7] = "teacher07";
	map1[8] = "teacher08";

	// 容器的遍历
	for (map<int, string>::iterator it = map1.begin(); it != map1.end(); ++it)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	cout << "容器遍历结束" << endl;

	// map 的查找
	map<int, string>::iterator it2 = map1.find(100);
	if (it2 == map1.end())
	{
		cout << "key 100 的值不存在" << endl;
	}
	else
	{
		cout << it2->first << "\t" << it2->second << endl;
	}

	// equal_range   // 异常处理
	// typedef pair<iterator, iterator> _Pairii;

	pair<map<int, string>::iterator, map<int, string>::iterator>  maypair2 = map1.equal_range(5);    // 返回两个迭代器   形成一个pair
	if (maypair2.first == map1.end())
	{
		cout << "第一个迭代器 ===》 5 的位置不存在" << endl;
	}
	else
	{
		cout << maypair2.first->first << "\t" << maypair2.first->second << endl;
	}
	if (maypair2.second == map1.end())
	{
		cout << "第二个迭代器 ===》 5 的位置不存在" << endl;
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