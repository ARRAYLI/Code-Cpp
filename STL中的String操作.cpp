#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// string的初始化
void test1()
{
	string s1 = "aaaa";
	string s2("bbbb");
	string s3 = s2;		//   通过拷贝构造函数来 初始化对象  s3
	string s4(10,'a');

	cout << "s1: " <<s1<< endl;
	cout << "s2: " << s2 << endl;
	cout << "s3: " << s3 << endl;
	cout << "s4: " << s4 << endl;
}

// string 的遍历

void test2()
{
	string s1 = "abcdefg";

	// 1 数组方式遍历
	for (int i = 0; i < s1.length(); i++)
	{
		cout << s1[i] << " ";
	}
	cout << endl;

	// 2迭代器方式遍历
	for (string::iterator it=s1.begin();it!=s1.end();++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	// 3 抛出异常
	try                
	{
		for (int i = 0; i < s1.length()+3; i++)
		{
			cout << s1.at(i) << " ";			// at() 可以抛出异常
		}

	}
	catch (...)					// 捕捉所有异常
	{
		cout << "发生异常！" << endl;
	}
	try
	{
		for (int i = 0; i < s1.length() + 3; i++)
		{
			cout << s1[i]<< " ";			// 出现错误 不向外面抛出异常   程序引起的中断
		}
	}
	catch (...)			// 捕捉所有异常
	{
		cout << "发生异常！" << endl;
	}
}

// 字符指针和 string 的转换
void test3()
{
	string s1 = "aaabbb";
	
	// 1 s1=====>char * 
	printf("s1 : %s\n",s1.c_str());

	//2  char *====>string 

	// 3 s1的内容copy进 buf 中
	char buf[128] = {0};
	s1.copy(buf,3,0);				//	注意 只给你copy 3 个字符  不会变成 C 风格
	cout << "buf: " << buf << endl;
}

// 字符串的连接

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

// 字符串的查找和替换

void test5()
{
	string s1 = "abc hello abc 111 abc 222 abc 333";

	// 第一次出现 abc index
	int index = s1.find("abc",0);		// 位置从下标0开始

	cout << "index: " << index<<endl;


	// 案例1 求abc出现的次数  以及每次出现的数组下标
	int offindex= s1.find("abc",0);
	while (offindex!=string::npos)				// string::npos表示保证大于任何有效下标的值
	{
		cout << "offindex: " << offindex << endl;
		offindex += 1;				// 下标继续往后移动，直到字符串结束为止
		offindex = s1.find("abc",offindex);
	}

	// 案例2   把小写abc=====>大写ABC

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
	cout << "s1转换后的结果是：" << s1 << endl;
}

// string 的截断（区间删除）和插入

void  test6()
{
	string s1 = "hello1 hello2 hello1";
	string::iterator it =find(s1.begin(),s1.end(),'1');				// 这里用到算法 find ，需要添加头文件 <algorithm>

	if (it!=s1.end())
	{
		s1.erase(it);
	}
	cout << "s1删除后的结果是：" <<s1<< endl;

	s1.erase(s1.begin(),s1.end());
	cout << "s1全部删除,s1: "<<s1 << endl;
	cout << "s1的长度是："<<s1.length() << endl;

	string s2 = "BBB";
	s2.insert(0,"AAA");				// 头插法
	cout << s2 << endl;

	s2.insert(s2.length(),"CCC");		// 尾插法
	cout << s2 << endl;

}

// string  的相关算法

void test7()
{
	string s1 = "AAAbbb";

	// 1 函数的入口地址  2 函数的对象  3预定义的函数对象
	transform(s1.begin(),s1.end(),s1.begin(),towupper);			// 这里的towlower是预定义的函数对象，这里实质上是通过函数名来调用函数
	cout << "s1: "<<s1 << endl;

	string s2 = "AAAbbb";
	transform(s2.begin(),s2.end(),s2.begin(),tolower);			// tolower  小写函数
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