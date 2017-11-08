#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<functional>
#include<iterator>
#include<numeric>

using namespace std;

void printV(vector<int> &v)
{
	for (vector<int>::iterator it=v.begin();it!=v.end();++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void printList(list<int> &v)
{
	for (list<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

// һ������� for_each() ��ʹ�õĺ������󣬲��������ã�û�з���ֵ 
void showElem(int &n)
{
	cout << n << "  ";
}

// transform() ��ʹ�õĺ������󣬲�����Ҫʹ�����ã����һ�Ҫ�з���ֵ
int showElem2(int n)
{
	cout << n << "  ";
	return n;
}

class CMyShow
{
public:
	CMyShow()
	{
		num = 0;
	}
	void operator()(int &n)
	{
		num++;
		cout << n<< "  ";
	}
	void printNum()
	{
		cout <<"num: "<<num << endl;
	}
private:
	int num;
};


// for_each() �� transform() �㷨
void test_for_each()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	printV(v);

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

	// ��������  �ص�������ڵ�ַ
	for_each(v.begin(),v.end(), showElem);
	cout << endl;

	for_each(v.begin(), v.end(), CMyShow());
	cout << endl;

	CMyShow ma;
	CMyShow my1= for_each(v.begin(), v.end(), ma);		// �� my1 ��ʼ��
	cout << endl;
	ma.printNum();		// ma �� my1��������ͬ�ĺ�������
	my1.printNum();

	my1 = for_each(v.begin(), v.end(), ma);		// �� my1 ��ʼ��
	my1.printNum();
}

int increase(int i)
{
	return i+100;
}

void test_transform()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	printV(v);

	// transform ʹ�ûص�����
	transform(v.begin(),v.end(),v.begin(), increase);
	printV(v);

	// transform ʹ��Ԥ���庯������
	transform(v.begin(), v.end(), v.begin(),negate<int>());
	printV(v);

	// transform ʹ�ú���������
	list<int>  mylist;
	mylist.resize(v.size());
	transform(v.begin(), v.end(), mylist.begin(),bind2nd(multiplies<int>(),10));
	printList(mylist);

	// transform Ҳ����ֱ�Ӱ��������������Ļ��
	transform(v.begin(), v.end(),ostream_iterator<int>(cout,"  "),negate<int>());
	cout << endl;
}

void test_for_each_vs_transform()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	
	for_each(v.begin(),v.end(),showElem);
	cout << endl;

	vector<int>  v2 = v;

	// transform() �Ժ��������Ҫ��

/*
d:\vs2015\vc\include\algorithm(950) : note: �μ������ڱ���ĺ��� ģ�� ʵ����
��_OutIt std::_Transform_no_deprecate1<int*, _OutIt, void(__cdecl *)(int &)>(_InIt, _InIt, _OutIt, _Fn1 &, 
	std::random_access_iterator_tag, std::random_access_iterator_tag)��������
			with
			[
				              _OutIt = std::_Vector_iterator<std::_Vector_val<std::_Simple_types<int>>>,
					             _InIt = int *,
					            _Fn1 = void(__cdecl *)(int &)
			]
*/

	/*

	template<class _InIt,
	class _OutIt,
	class _Fn1> inline
	_OutIt _Transform_no_deprecate1(_InIt _First, _InIt _Last,
		_OutIt _Dest, _Fn1& _Func,
		random_access_iterator_tag, random_access_iterator_tag)
	{	// transform [_First, _Last) with _Func, random-access iterators, no deprecation warnings
	_CHECK_RANIT_RANGE(_First, _Last, _Dest);
	return (_Rechecked(_Dest,
		_Transform_unchecked(_First, _Last, _Unchecked(_Dest), _Func)));			// ������ΪʲôҪ�з���ֵ
	}

	*/
	transform(v2.begin(),v2.end(),v2.begin(),showElem2);
	cout << endl;
}

void test_adjcent_find()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(2);
	v.push_back(3);
	v.push_back(5);

	// �����ظ�Ԫ��
	vector<int>::iterator it= adjacent_find(v.begin(),v.end());
	if (it == v.end())
	{
		cout << "û���ҵ��ظ�Ԫ��" << endl;
	}
	else
	{
		cout << *it << endl;
	}
	int index = distance(v.begin(),it);
	cout << "index: " << index << endl;
}

// 0 1 2 3 4 ........ n-1
// ���ַ�����  1K = 1024 ���� 10 ��
void test_binary_search()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);

    bool b= binary_search(v.begin(),v.end(),72);
	if (b)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "û����" << endl;
	}
}

void test_count()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(7);
	v.push_back(9);

	int num = count(v.begin(),v.end(),7);
	cout << num << endl;

}

// �ж� iNum �Ƿ���� 3
bool GreatThree(int iNum)
{
	return ( iNum > 3);
}

void test_count_if()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(7);
	v.push_back(9);

	int num = count_if(v.begin(),v.end(), GreatThree);
	cout << num << endl;
}

void test_find_find_if()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(7);
	v.push_back(9);
	v.push_back(7);
	v.push_back(9);

	vector<int>::iterator it = find(v.begin(),v.end(),5);
	cout << "*it: " <<*it <<endl;

	// ���ҵ���һ������ 3 �ĵ�������λ��
	vector<int>::iterator it2 = find_if(v.begin(), v.end(),GreatThree);
	cout << "*it2: " << *it2 << endl;
}

void test_merge()
{

	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);

	vector<int>  v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int>  v3;
	v3.resize(v.size()+v2.size());

	merge(v.begin(),v.end(),v2.begin(),v2.end(),v3.begin());
	printV(v3);
}

class Student
{
public:
	Student(string name,int id)
	{
		m_name = name;
		m_id = id;
	}
	void printT()
	{
		cout << "m_name: "<<m_name << "  m_age: "<<m_id << endl;
	}
public:
	string	m_name;
	int		m_id;
};

// ν��
bool Compare(const Student &st1, const Student &st2)
{
	return ( st1.m_id <  st2.m_id );   // ��С����
}


void test_sort()
{
	Student s1("�ϴ�",1);
	Student s2("�϶�", 2);
	Student s3("����", 3);
	Student s4("����", 4);
	
	vector<Student>  v1;

	v1.push_back(s4);
	v1.push_back(s1);
	v1.push_back(s3);
	v1.push_back(s2);
	
	for (vector<Student>::iterator it = v1.begin(); it != v1.end(); ++it)
	{
		it->printT();
	}

	// sort �����Զ��庯�����󣬽����Զ����������͵�����	
	// �滻 �㷨��ͳһ�� ��ʵ���㷨���������͵ķ��룩   ======�� �����ֶκ�������
	sort(v1.begin(),v1.end(),Compare);

	for (vector<Student>::iterator it=v1.begin();it!=v1.end();++it)
	{
		it->printT();
	}
}

void test_random_shuffle()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	printV(v);
	random_shuffle(v.begin(),v.end());

	printV(v);

	string str = "abcdefghi";
	random_shuffle(str.begin(),str.end());
	cout << "str: "<<str << endl;
}

void test_resverse()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	printV(v);
	reverse(v.begin(),v.end());
	printV(v);
}

void test_copy()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);

	vector<int>  v2;
	v2.resize(v.size());
	copy(v.begin(),v.end(),v2.begin());
	printV(v2);
}

// ν�� ���ڵ��� 5 

bool great_equal(int &n)
{

	return ( n >=5);
}

void test_replace_replace_if()
{
	vector<int>  v;
	v.push_back(1);
	v.push_back(3);
	v.push_back(5);
	v.push_back(7);
	v.push_back(3);

	printV(v);
	replace(v.begin(),v.end(),3,8);
	printV(v);


	replace_if(v.begin(),v.end(),great_equal,1);
	printV(v);
}

void test_swap()
{
	vector<int>  v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>  v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	swap(v1,v2);
	printV(v1);
	printV(v2);
}

void tets_fill()
{
	vector<int>  v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	printV(v1);
	fill(v1.begin(),v1.end(),8);
	printV(v1);
}


void test_union()
{

	vector<int>  v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	vector<int>  v2;
	v2.push_back(2);
	v2.push_back(4);
	v2.push_back(6);

	vector<int>  v3;

	v3.resize(v1.size()+v2.size());

	set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
	printV(v3);
}

void test_accumulate()
{
	vector<int> vecIntA;
	vecIntA.push_back(1);
	vecIntA.push_back(3);
	vecIntA.push_back(5);
	vecIntA.push_back(7);
	vecIntA.push_back(9);
	int iSum = accumulate(vecIntA.begin(), vecIntA.end(), 100);		//iSum==125
	cout <<"iSum: " << iSum<< endl;
}

int main(void)
{
	// test_for_each();
	// test_transform();
	// test_for_each_vs_transform();
	// test_adjcent_find();
	// test_binary_search();
	// test_count();
	// test_count_if();
	// test_find_find_if();
	// test_merge();
	// test_sort();
	// test_random_shuffle();
	// test_resverse();
	// test_copy();
	// test_replace_replace_if();
	// test_swap();
	// tets_fill();
	// test_union();
	test_accumulate();
	return 0;
}