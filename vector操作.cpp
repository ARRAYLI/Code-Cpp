#include<iostream>
#include<vector>

using namespace std;

// vector 动态数组的添加和删除

void test()
{
	vector<int> v1;
	
	cout << "length: "<< v1.size()<< endl;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	cout << "length: " << v1.size() << endl;
	cout << "头部元素是：" << v1.front() << endl;	// v1.front() 可以获取头部元素的值

	// 修改头部元素
	// 函数当佐值		应该返回一个引用

	v1.front() = 11;
	v1.back() = 55;


	while (v1.size()>0)
	{
		cout <<"尾部元素是：" <<v1.back() << endl;	// v1.back() 可以获取尾部元素的值
		v1.pop_back();		// 删除尾部元素
	}
}

// vector动态数组的初始化

void  test1()
{
	vector<int>  v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int>  v2 = v1;			// 对象初始化
	vector<int>  v3(v1.begin(),v1.begin()+2);

}

void printV(vector<int> &v)
{
	for (int i=0;i<v.size();i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;
}

// vector 动态数组的遍历

void test2()
{
	vector<int>  v(10);			// 提前把内存准备好，数组长度指定好，此时vector中的内容的值都为  0 

	for (int i=0;i<10;i++)
	{
		v[i] = i + 1;
	}

	printV(v);
}

// vector动态数组 push_back()

void test3()
{
	vector<int> v(10);		//  提前把内存分配好 

	v.push_back(100);
	v.push_back(200);
	printV(v);
	cout << "size: " <<v.size()<< endl;
}

// 1 迭代器  end()的理解
//	1   3   5
//  ▲					这里的三角形表示迭代器的开始位置 即 v.begin();
//			  ▲		这里的三角形表示迭代器的末尾位置 即 v.end();
// 当it==v.end()的时候  说明这个容器已经遍历完毕了...
// end() 的位置应该是5的后面

// 2 迭代器的种类

void test4()
{
	vector<int>  v(10);

	// 给vector中的10个元素赋初值
	for (int i=0;i<v.size();++i)
	{
		v[i] = i + 1;
	}

	// 正向遍历     正向迭代器
	for (vector<int>::iterator it=v.begin();it!=v.end();++it)
	{
		cout << *it<<" ";
	}
	cout << endl;

	// 逆序遍历		反向迭代器
	for (vector<int>::reverse_iterator it =v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;
}

// vector 动态数组中元素的删除

void test5()
{
	vector<int>  v(10);

	for (int i=0;i<v.size();++i)
	{
		v[i] = i + 1;
	}

	// 区间删除
	v.erase(v.begin(),v.begin()+3);
	printV(v);

	// 根据元素的位置  指定位置删除
	v.erase(v.begin());			// 删除头部元素
	printV(v);

	// 根据元素的值删除
	v[1] = 2;
	v[3] = 2;
	printV(v);

	for (vector<int>::iterator it=v.begin();it!=v.end();)
	{
		if (*it==2)
		{
			it=v.erase(it);		// 当删除迭代器所指向的元素的时候  erase()删除函数会让 it 自动向下移动
		}
		else
		{
		   ++it;
		}
	}
	printV(v);

	v.insert(v.begin(),100);		// 头插法
	v.insert(v.end(),200);			// 尾插法
	printV(v);
}

int main(void)
{
	// test();
	// test1();
	// test2();
	// test3();
	// test4();
	test5();
	return 0;
}