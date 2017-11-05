#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// string�ĳ�ʼ��
void test1()
{
	string s1 = "aaaa";
	string s2("bbbb");
	string s3 = s2;		//   ͨ���������캯���� ��ʼ������  s3
	string s4(10,'a');

	cout << "s1: " <<s1<< endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
}

// string �ı���

void test2()
{
	string s1 = "abcdefg";

	// 1 ���鷽ʽ����
	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	// 2��������ʽ����
	for (string::iterator it=s1.begin();it!=s1.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 3 �׳��쳣
	try                
	{
		for (int i = 0; i < s1.length()+3; i++)
		{
			cout << s1.at(i) << " ";			// at() �����׳��쳣
		}

	}
	catch (...)					// ��׽�����쳣
	{
		cout << "�����쳣��" << endl;
	}
	try
	{
		for (int i = 0; i < s1.length() + 3; i++)
		{
			cout << s1[i]<< " ";			// ���ִ��� ���������׳��쳣   ����������ж�
		}
	}
	catch (...)			// ��׽�����쳣
	{
		cout << "�����쳣��" << endl;
	}
}

// �ַ�ָ��� string ��ת��
void test3()
{
	string s1 = "aaabbb";
	
	// 1 s1=====>char * 
	printf("s1 : %s\n",s1.c_str());

	//2  char *====>string 

	// 3 s1������copy�� buf ��
	char buf[128] = {0};
	s1.copy(buf,3,0);				//	ע�� ֻ����copy 3 ���ַ�  ������ C ���
	cout << "buf: " << buf << endl;
}

// �ַ���������

void test4()
{
	string s1 = "aaa";
	string s2 = "bbb";
	s1 = s1 + s2;

	cout << "s1: " << s1 << endl;

	string s3 = "333";
	string s4 = "444";
	s3.append(s4);
	cout << "s3: " << s3 << endl;
}

// �ַ����Ĳ��Һ��滻

void test5()
{
	string s1 = "abc hello abc 111 abc 222 abc 333";

	// ��һ�γ��� abc index
	int index = s1.find("abc",0);		// λ�ô��±�0��ʼ

	cout << "index: " << index<<endl;


	// ����1 ��abc���ֵĴ���  �Լ�ÿ�γ��ֵ������±�
	int offindex= s1.find("abc",0);
	while (offindex!=string::npos)				// string::npos��ʾ��֤�����κ���Ч�±��ֵ
	{
		cout << "offindex: " << offindex << endl;
		offindex += 1;				// �±���������ƶ���ֱ���ַ�������Ϊֹ
		offindex = s1.find("abc",offindex);
	}

	// ����2   ��Сдabc=====>��дABC

	string s3 = "aaa bbb ccc";
	s3.replace(0,3,"AAA");
	cout << "s3: " << s3 << endl;


	offindex = s1.find("abc",0);
	while (offindex!=string::npos)
	{
		cout << "offindex:" <<offindex<< endl;
		s1.replace(offindex,3,"ABC");
		offindex += 1;
		offindex = s1.find("abc",offindex);
	}
	cout << "s1ת����Ľ���ǣ�" << s1 << endl;
}

// string �Ľضϣ�����ɾ�����Ͳ���

void  test6()
{
	string s1 = "hello1 hello2 hello1";
	string::iterator it =find(s1.begin(),s1.end(),'1');				// �����õ��㷨 find ����Ҫ���ͷ�ļ� <algorithm>

	if (it!=s1.end())
	{
		s1.erase(it);
	}
	cout << "s1ɾ����Ľ���ǣ�" <<s1<< endl;

	s1.erase(s1.begin(),s1.end());
	cout << "s1ȫ��ɾ��,s1: "<<s1 << endl;
	cout << "s1�ĳ����ǣ�"<<s1.length() << endl;

	string s2 = "BBB";
	s2.insert(0,"AAA");				// ͷ�巨
	cout << s2 << endl;

	s2.insert(s2.length(),"CCC");		// β�巨
	cout << s2 << endl;

}

// string  ������㷨

void test7()
{
	string s1 = "AAAbbb";

	// 1 ��������ڵ�ַ  2 �����Ķ���  3Ԥ����ĺ�������
	transform(s1.begin(),s1.end(),s1.begin(),towupper);			// �����towlower��Ԥ����ĺ�����������ʵ������ͨ�������������ú���
	cout << "s1: "<<s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(),s2.end(),s2.begin(),tolower);			// tolower  Сд����
	cout << "s2: " << s2 << endl;
}

int main(void)
{
	// test1();
	// test2();
	// test3();
	// test4();
	// test5();
	// test6();
	test7();
	return 0;
}