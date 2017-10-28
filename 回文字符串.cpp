/*
给出一个长度不超过1000的字符串，判断它是不是回文(顺读，逆读均相同)的。
输入描述:

输入包括一行字符串，其长度不超过1000。



输出描述:

可能有多组测试数据，对于每组数据，如果是回文字符串则输出"Yes!”，否则输出"No!"。


输入例子:

hellolleh
helloworld


输出例子:

Yes!
No!

*/

#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
	char str[1000] = "";
	while (cin >> str)
	{
		int len = strlen(str);
		int count = 0;
		for (int i = 0; i<len / 2; i++)
		{
			if (str[i] == str[len - i - 1]) {
				count++;
			}
			else
			{
				cout << "No!" << endl;
				break;
			}
		}
		if (count == len / 2)
			cout << "Yes!" << endl;
	}
	return 0;
}