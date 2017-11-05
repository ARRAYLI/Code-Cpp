#include<iostream>
#include<vector>

using namespace std;

// vector ��̬�������Ӻ�ɾ��

void test()
{
	vector<int> v1;
	
	cout << "length: "<< v1.size()<< endl;

	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);

	cout << "length: " << v1.size() << endl;
	cout << "ͷ��Ԫ���ǣ�" << v1.front() << endl;	// v1.front() ���Ի�ȡͷ��Ԫ�ص�ֵ

	// �޸�ͷ��Ԫ��
	// ��������ֵ		Ӧ�÷���һ������

	v1.front() = 11;
	v1.back() = 55;


	while (v1.size()>0)
	{
		cout <<"β��Ԫ���ǣ�" <<v1.back() << endl;	// v1.back() ���Ի�ȡβ��Ԫ�ص�ֵ
		v1.pop_back();		// ɾ��β��Ԫ��
	}
}

// vector��̬����ĳ�ʼ��

void  test1()
{
	vector<int>  v1;
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);

	vector<int>  v2 = v1;			// �����ʼ��
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

// vector ��̬����ı���

void test2()
{
	vector<int>  v(10);			// ��ǰ���ڴ�׼���ã����鳤��ָ���ã���ʱvector�е����ݵ�ֵ��Ϊ  0 

	for (int i=0;i<10;i++)
	{
		v[i] = i + 1;
	}

	printV(v);
}

// vector��̬���� push_back()

void test3()
{
	vector<int> v(10);		//  ��ǰ���ڴ����� 

	v.push_back(100);
	v.push_back(200);
	printV(v);
	cout << "size: " <<v.size()<< endl;
}

// 1 ������  end()�����
//	1   3   5
//  ��					����������α�ʾ�������Ŀ�ʼλ�� �� v.begin();
//			  ��		����������α�ʾ��������ĩβλ�� �� v.end();
// ��it==v.end()��ʱ��  ˵����������Ѿ����������...
// end() ��λ��Ӧ����5�ĺ���

// 2 ������������

void test4()
{
	vector<int>  v(10);

	// ��vector�е�10��Ԫ�ظ���ֵ
	for (int i=0;i<v.size();++i)
	{
		v[i] = i + 1;
	}

	// �������     ���������
	for (vector<int>::iterator it=v.begin();it!=v.end();++it)
	{
		cout << *it<<" ";
	}
	cout << endl;

	// �������		���������
	for (vector<int>::reverse_iterator it =v.rbegin(); it != v.rend(); ++it)
	{
		cout << *it << " ";
	}

	cout << endl;
}

// vector ��̬������Ԫ�ص�ɾ��

void test5()
{
	vector<int>  v(10);

	for (int i=0;i<v.size();++i)
	{
		v[i] = i + 1;
	}

	// ����ɾ��
	v.erase(v.begin(),v.begin()+3);
	printV(v);

	// ����Ԫ�ص�λ��  ָ��λ��ɾ��
	v.erase(v.begin());			// ɾ��ͷ��Ԫ��
	printV(v);

	// ����Ԫ�ص�ֵɾ��
	v[1] = 2;
	v[3] = 2;
	printV(v);

	for (vector<int>::iterator it=v.begin();it!=v.end();)
	{
		if (*it==2)
		{
			it=v.erase(it);		// ��ɾ����������ָ���Ԫ�ص�ʱ��  erase()ɾ���������� it �Զ������ƶ�
		}
		else
		{
		   ++it;
		}
	}
	printV(v);

	v.insert(v.begin(),100);		// ͷ�巨
	v.insert(v.end(),200);			// β�巨
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