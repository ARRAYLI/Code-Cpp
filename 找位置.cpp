/*
abcaaAB12ab12

a:0,a:3,a:4,a:9
b:1,b:10
1:7,1:11
2:8,2:12

*/

/*
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef struct ele
{
	char data;
	int count;
	int pos[100];  //保留位置
	int numble;
	bool butter;
	int sum;
}ele;

void search(char buf[], int len)
{
	char buf1[100];
	strcpy(buf1, buf);
	sort(buf, buf + len);
	ele rec[1000];
	int j = 0, m = 0;
	for (int i = 0; i<len; i++)
	{
		char r = buf[i], t = 0;
		rec[j++].data = r;   //保存重复的数
		while (buf[i] == r)
		{
			t++;
			i++;
		}
		rec[j - 1].count = t;  //保留每个非重复的个数
	}

	for (int k = 0; k<j; k++)
	{
		int p = 0;
		for (int u = 0; u<len; u++)      //对字符串再次遍历 在此过程中对rec的不同数的位置元素进行赋值
		{
			if (rec[k].data == buf1[u])
				rec[k].pos[p++] = u;

		}
		rec[k].numble = rec[k].sum = p;
		rec[k].butter = false;   //对开关进行赋初值 为第三次做准备
	}

	for (int w = 0; w<len; w++)
	{
		for (int h = 0; h<j; h++)
		{
			if (rec[h].sum != 1)
			{
				if (rec[h].butter == false && buf1[w] == rec[h].data)
				{
					int a = 0;
					while (rec[h].numble != 0)
					{

						if (rec[h].numble == 1)
							printf("%c:%d\n", rec[h].data, rec[h].pos[a]);
						else printf("%c:%d,", rec[h].data, rec[h].pos[a]);
						rec[h].numble--;
						a++;
					}

					//rec[h].butter==true;
				}
			}
		}
	}
}

int main()
{
	char buf[1000];
	while (scanf("%s", &buf) != EOF)
	{
		int len = strlen(buf);
		search(buf, len);
	}
	return 0;
}
*/

/*
#include <stdio.h>
#include <string.h>

void myPrint(char a, char* str)
{
	int i, flag = 0, len = strlen(str);
	for (i = 0; i < len; i++) {
		if (flag == 0 && str[i] == a) {
			printf("%c:%d", a, i);
			flag = 1;
		}
		else if (flag == 1 && str[i] == a)
			printf(",%c:%d", a, i);
	}
	printf("\n");
}

int main()
{
	char str[100];
	int i, len, count[128] = { 0 };
	while (gets_s(str)) {
		for (i = 0; i < 128; i++)
			count[i] = 0;
		len = strlen(str);
		for (i = 0; i < len; i++) {
		//	char c = str[i];
		//	count[c]++;
			count[str[i]]++;
		}
		for (i = 0; i < len; i++) {
			if (count[str[i]] > 1) {
				myPrint(str[i], str);
				count[str[i]] = -1;
			}
		}
	}
	return 0;
}

*/

#include<stdio.h>
#include<string.h>
int main(void)
{
	char str[100] = "";
	int k;
	while (scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		for (int i = 0; i<len; i++)
		{
			k = 0;
			if (str[i] =='*')
				continue;
			for (int j = i + 1; j<len; j++)
			{
			
				if (str[i] == str[j])
				{
					k++;
					if (k == 1)
					{
						printf("%c:%d,", str[i], i);
						printf("%c:%d", str[j], j);
					}
					else
					{
						printf(",%c:%d", str[j], j);
						str[j] = '*';
					}
				}
			}

			if (k != 0)
				printf("\n");
		}
	}
	return 0;
}