/*
����һ�����Ȳ�����1000���ַ������ж����ǲ��ǻ���(˳�����������ͬ)�ġ�
��������:

�������һ���ַ������䳤�Ȳ�����1000��



�������:

�����ж���������ݣ�����ÿ�����ݣ�����ǻ����ַ��������"Yes!�����������"No!"��


��������:

hellolleh
helloworld


�������:

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