/*
��Ŀ����
��N��������ɴﵽ1000������������
�������� :

�����һ��Ϊһ������N��(1 <= N <= 100)��
��������N��ÿ����һ���������ĳ��ȷ�ΧΪ1 <= len <= 1000��
ÿ��������һ�����������ұ�֤������ǰ׺�㡣



������� :

�����ж���������ݣ�����ÿ�����ݣ���������N������С�������������������Ľ����ÿ����ռһ�С�


�������� :

3
11111111111111111111111111111
2222222222222222222222222222222222
33333333


������� :

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