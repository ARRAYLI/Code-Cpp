/*

题目描述
编一个程序，读入用户输入的，以“.”结尾的一行文字，统计一共有多少个单词，并分别输出每个单词含有多少个字符。 （凡是以一个或多个空格隔开的部分就为一个单词）
输入描述:

输入包括1行字符串，以“.”结束，字符串中包含多个单词，单词之间以一个或多个空格隔开。



输出描述:

可能有多组测试数据，对于每组数据，
输出字符串中每个单词包含的字母的个数。


输入例子:

hello how are you.


输出例子:

5 3 3 3

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//该代码利用了scanf函数在输入字符串时，不能输入空格的性质
int main()
{
	char str[1000000];
	while (scanf("%s", str) != EOF)
	{
		int len = strlen(str);

		if (str[len - 1] == '.')
		{
			printf("%d\n", len - 1);
		}
		else
			printf("%d ", len);
	}
}