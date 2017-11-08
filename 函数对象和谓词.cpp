#include<iostream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<set>
#include<string>
#include<numeric>


using namespace std;

// 函数对象，类重载了....
template<typename T>
class ShowElement
{
public:
	ShowElement()
	{
		n = 0;
	}
	void operator()(T & t)
	{
		n++;
		cout << t<<" ";
	}
	void printN()
	{
		cout << "n: "<<n << endl;
	}
private:
	int   n;
};

// 函数模板 ===》 函数
template<typename T>
void FuncShowElement(T &t)
{
	cout <<t <<endl;
}

// 普通函数
void FuncShowElement2(int &t)
{
	cout << t << endl;
}

// 函数对象  定义：  函数对象和普通函数对的区别

void test()
{
	int a = 10;
	ShowElement<int>  showElem;
	showElem(a);		// 函数对象 () 的执行 很像一个函数     // 仿函数

	FuncShowElement<int>(a);
	FuncShowElement2(a);
}

// 函数对象是属于一个类对象，能突破函数的概念，能保持调用信息
// 函数对象的好处
// for_each 算法中  对象做函数参数
// for_each 算法中  函数对象做返回值

void test1()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	for_each(v.begin(),v.end(),ShowElement<int>());			// 匿名函数对象   匿名仿函数
	cout << endl;
	for_each(v.begin(), v.end(),FuncShowElement2);
	cout << endl;

	ShowElement<int> show1;
	// 函数对象    做函数参数
	/*
	template<class _InIt,
		class _Fn1> inline
		_Fn1 for_each(_InIt _First, _InIt _Last, _Fn1 _Func)
	{	// perform function for each element
		_DEBUG_RANGE_PTR(_First, _Last, _Func);
		_For_each_unchecked(_Unchecked(_First), _Unchecked(_Last), _Func);
		return (_Func);
	}
	*/

	// 1 for_each 算法的  函数对象的传递  是元素值传递，不是引用传递
	for_each(v.begin(), v.end(), show1);
	show1.printN();

	cout << "通过  for_each  算法的返回值查看调用次数：" << endl;
	show1 = for_each(v.begin(),v.end(),show1);
	show1.printN();

}

template<typename T>
class IsDiv
{
public:
	IsDiv(T &divisor)
	{
		this->divisor = divisor;
	}
	bool operator()(const T &t)
	{
		return (t % divisor == 0);
	}
private:
	T   divisor;
};

void test2()
{
	vector<int> v;
	for (int i=10;i<33;i++)
	{
		v.push_back(i);
	}

	int a = 4;
	vector<int>::iterator it;
	IsDiv<int> myDiv(a);

	/*
	
	template<class _InIt,
	class _Pr> inline
	_InIt find_if(_InIt _First, _InIt _Last, _Pr _Pred)
	{	// find first satisfying _Pred
	_DEBUG_RANGE_PTR(_First, _Last, _Pred);
	return (_Rechecked(_First,
		_Find_if_unchecked(_Unchecked(_First), _Unchecked(_Last), _Pred)));
	}

	*/


	it = find_if(v.begin(),v.end(),myDiv);
	if (it == v.end())
	{
		cout << "容器中的元素" << endl;
	}
	else
	{
		cout << "第一个被 4 整除的元素是："<<*it << endl;
	}
}


// 二元函数对象
template<typename T> 
class SumAdd
{
public:
	T operator()(T &t1,T &t2)
	{
		return t1 + t2;
	}
};

void test3()
{
	vector<int>	 v1, v2;
	vector<int>  v3;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	v3.resize(10);

	/*
	
	template<class _InIt1,
	class _InIt2,
	class _OutIt,
	class _Fn2> inline
	_OutIt transform(_InIt1 _First1, _InIt1 _Last1,
		_InIt2 _First2, _OutIt _Dest, _Fn2 _Func)
	{	// transform [_First1, _Last1) and [_First2, ...) with _Func
	_DEFINE_DEPRECATE_UNCHECKED(transform);
	_USE_DEPRECATE_UNCHECKED(_First2);
	_USE_DEPRECATE_UNCHECKED(_Dest);
	return (_Transform_no_deprecate(_First1, _Last1, _First2, _Dest, _Func));
	}
	
	*/

	// transform 把运算结果的 迭代器对的开始位置  返回出来
	transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),SumAdd<int>());

	for (vector<int>::iterator it=v3.begin();it!=v3.end();++it)
	{
		cout << *it << endl;
	}

}

bool MyCompare(const int &a,const int &b)
{
	return a < b;		// 从小到大
}


// 二元谓词
void test4()
{
	vector<int>  v(10);

	for (int i=0;i<10;i++)
	{
		int tmp = rand() % 100;
		v[i] = tmp;
	}

	for (vector<int>::iterator it=v.begin();it!=v.end();++it)
	{
		cout <<*it << endl;
	}

	cout << endl;
	for_each(v.begin(),v.end(),FuncShowElement2);

	// 排序
	sort(v.begin(),v.end(),MyCompare);

	cout << endl;
	for_each(v.begin(), v.end(), FuncShowElement2);
}


/*
struct CompareNoCase
{
	bool operator()(const string &str1,const string &str2)
	{
		string str1_;
		str1_.resize(str1.size());
		transform(str1.begin(),str1.end(),str1_.begin(),tolower);

		string str2_;
		str2_.resize(str2.size());
		transform(str2.begin(), str2.end(), str2_.begin(), tolower);

		return (str1_ < str2_ );		// 从小到大排序
	//	return (str1 < str2);
	}
};
*/


// 二元谓词 在 set 中的调用
void test5()
{
	set<string>  set1;
	set1.insert("bbb");
	set1.insert("aaa");
	set1.insert("ccc");

	/*
		iterator find(const key_type& _Keyval)
		{	// find an element in mutable sequence that matches _Keyval
		iterator _Where = lower_bound(_Keyval);
		return (_Where == end()
			|| _DEBUG_LT_PRED(this->_Getcomp(),
				_Keyval, this->_Key(_Where._Mynode()))
					? end() : _Where);
		}
	*/
    set<string>::iterator it = set1.find("aaa");
	if (it==set1.end())
	{
		cout << "没有找到 aaa " << endl;
	}
	else
	{
		cout << "查找到  aaa " << endl;
	}
	
	
	/*
	set<string, CompareNoCase> set2;
	set2.insert("bbb");
	set2.insert("aaa");
	set2.insert("ccc");
	string s = "aAa";
	*/

}

int main(void)
{
	// test();			// 函数对象基本概念
	// test1();			// 函数对象的好处    函数对象做函数参数   函数对象做返回值
	// test2();			// 一元谓词
	// test3();			// 二元函数对象和二元谓词
	// test4();			// 二元函数对象和二元谓词
	test5();
	return 0;
}