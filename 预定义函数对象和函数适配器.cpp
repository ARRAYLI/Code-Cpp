#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<string>
using namespace std;

//  plus<int>  Ԥ����õĺ�������    ��ʵ�ֲ�ͬ�������͵� ���� + ����
// ʵ������������   ���㷨�ķ���    ====��ͨ������������ʵ��

void test()
{
	/*
	template<class _Ty = void>
	struct plus
	{	// functor for operator+
	typedef _Ty first_argument_type;
	typedef _Ty second_argument_type;
	typedef _Ty result_type;

	constexpr _Ty operator()(const _Ty& _Left, const _Ty& _Right) const
		{	// apply operator+ to operands
		return (_Left + _Right);
		}
	};
	
	*/


	plus<int>  intAdd;
	int x = 10;
	int y = 20;
	int z = intAdd(x,y);		// x+y
	cout << "z: " <<z<< endl;


	plus<string> strAdd;

	string str1 = "aaa";
	string str2 = "bbb";

	string str3 = strAdd(str1,str2);
	cout <<"str3: "<<str3 << endl;
	

	vector<string>  v;
	v.push_back("bbb");
	v.push_back("aaa");
	v.push_back("ccc");
	v.push_back("zzz");
	v.push_back("ccc");
	v.push_back("ccc");
	

	for (vector<string>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it << endl;
	}
	sort(v.begin(),v.end(),greater<string>());
	cout << "�����Ľ���ǣ�" << endl;
	for (vector<string>::iterator it=v.begin();it!=v.end();++it)
	{
		cout <<*it << endl;
	}

	// ��ϵ�κ�������
	// �� ccc ���ֵĴ���
	string sc = "ccc";

	// equal_to<string>()  ����������   ���������������  �Ҳ��������� sc 
	// bind2nd ����������  ��Ԥ����ĺ�������͵ڶ����������а�
	int num = count_if(v.begin(),v.end(),bind2nd(equal_to<string>(),sc));
	// int num = count(v.begin(),v.end(),"ccc");
	cout << "num: "<<num << endl;
}

class IsGreator
{
public:
	IsGreator(int m)
	{
		m_num = m;
	}

	bool operator()(int &m)
	{
		if (m>m_num)
		{
			return true;
		}
		return false;
	}
private:
	int m_num;
};

void test1()
{
	vector<int>  v;

	for (int i=0;i<10;i++)
	{
		v.push_back(i+1);
	}
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << *it <<"  ";
	}
	cout << endl;

	int num1 = count(v.begin(),v.end(),3);
	cout << "num1: "<<num1 << endl;

	// ͨ��ν�� ����� 2 �ĸ���
	int num2 = count_if(v.begin(),v.end(),IsGreator(2));
	cout << "num2: " <<num2<< endl;

	// ͨ��Ԥ���庯������ �� ���� 2 �ĸ���
	// greater<int>()  ����������  ���������������Ԫ��   �Ҳ����̶��� 2 ��ͨ��bind2nd���ģ�
	int num3 = count_if(v.begin(),v.end(),bind2nd(greater<int>(),2));
	cout << "num3: "<<num3 << endl;

	// �������ĸ���

	int num4 = count_if(v.begin(),v.end(),bind2nd(modulus<int>(),2));
	cout << "num4: "<<num4 << endl;

	// �� ż���ĸ���

	int num5 = count_if(v.begin(), v.end(), not1(bind2nd(modulus<int>(), 2)));
	cout << "num5: " << num5 << endl;
}

int main(void)
{
	 // test();
	test1();  // �����������ۺϰ���
	return 0;
}