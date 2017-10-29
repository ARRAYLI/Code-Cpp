/*

题目描述
不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输入描述:

每一行包括两个字符串，长度不超过100。



输出描述:

可能有多组测试数据，对于每组数据，
不借用任何字符串库函数实现无冗余地接受两个字符串，然后把它们无冗余的连接起来。
输出连接后的字符串。


输入例子:

abc def


输出例子:

abcdef


*/

#include<iostream>
#include<cstring>
using namespace std;
#define LEN 100
int main(void)
{
	char str1[LEN] = "";
	char str2[LEN] = "";
	char res[LEN + LEN] = "";
	while (cin >> str1 >> str2)
	{
		int len1 = strlen(str1);
		int len2 = strlen(str2);
		int k = 0;
		for (int i = 0; i<len1; i++)
			res[k++] = str1[i];

		for (int i = 0; i<len2; i++)
			res[k++] = str2[i];
		res[k] = '\0';
		puts(res);
		memset(str1, 0, LEN);
		memset(str2, 0, LEN);

	}
	return 0;
}



/*

input: 
   
	26958844911182213322147396433464032968499227527641110092524094945563348 17038294384565917495277469727953464972659365630664529706034397637

res:

	2695884491118221332214739643346403296849922752764111009252409494556334817038294384565917495277469727953464972659365630664529706034397637


*/