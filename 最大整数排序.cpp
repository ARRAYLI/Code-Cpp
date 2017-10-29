/*
题目描述
对N个长度最长可达到1000的数进行排序。
输入描述 :

输入第一行为一个整数N，(1 <= N <= 100)。
接下来的N行每行有一个数，数的长度范围为1 <= len <= 1000。
每个数都是一个正数，并且保证不包含前缀零。



输出描述 :

可能有多组测试数据，对于每组数据，将给出的N个数从小到大进行排序，输出排序后的结果，每个数占一行。


输入例子 :

3
11111111111111111111111111111
2222222222222222222222222222222222
33333333


输出例子 :

	33333333
	11111111111111111111111111111
	2222222222222222222222222222222222
*/

#include<iostream>
#include<string.h>
using namespace std;

int main(void)
{
	char str[200][1000];
	int num = 0;
	while (cin >> num)
	{
		int i, j;
		for (i = 0; i<num; i++)
			cin >> (str[i]);
		for (i = 0; i<num - 1; i++)
		{
			for (j = i + 1; j<num; j++)
			{
				char s[1000] = "";
				if (strlen(str[i]) > strlen(str[j]) || (strlen(str[i]) == strlen(str[j])) && strcmp(str[i], str[j])>0)
				{
					strcpy(s, str[i]);
					strcpy(str[i], str[j]);
					strcpy(str[j], s);
				}
			}
		}
		for (i = 0; i<num; i++)
			puts(str[i]);
	}
	return 0;
}