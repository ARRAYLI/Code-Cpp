/*
N��¥����¥���⣺һ�ο��������׻�һ�ף����ж�������¥��ʽ����Ҫ����÷ǵݹ飩
��������:

�������һ������N,(1<=N<90)��



�������:

�����ж���������ݣ�����ÿ�����ݣ�
�����¥�ݽ�����Nʱ����¥��ʽ������


��������:

4


�������:

5
*/

#include<iostream>
using namespace std;

int main(void)
{
	int num = 0;
	long long int arr[1000] = { 0 };
	while (cin >> num)
	{
		long long int result = 0;
		if (num == 1 || num == 2)
		{
			cout << num << endl;
		}
		if (num>2 && num<90) {
			arr[1] = 1;
			arr[2] = 2;
			for (int i = 3; i <= num; i++)
			{
				arr[i] = arr[i - 1] + arr[i - 2];
				result = arr[i];
			}
			cout << result << endl;
		}
	}
	return 0;
}
