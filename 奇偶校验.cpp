/*

��Ŀ����
����һ���ַ�����Ȼ���ÿ���ַ�������У�飬������У���Ķ�������(��'3���������10110011)��
��������:

�������һ���ַ������ַ������Ȳ�����100��



�������:

�����ж���������ݣ�����ÿ�����ݣ�
�����ַ����е�ÿһ���ַ����������Ŀ������żУ��������ÿ���ַ�У��Ľ��ռһ�С�


��������:

3
3a


�������:

10110011
10110011
01100001



*/




#include<iostream>
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
	int arr[1000] = { 0 };

	int num = 0;
	cin >> num;
	for (int i = 0; i<num; i++)
		cin >> arr[i];

	int max = arr[0];

	for (int i = 0; i<num - 1; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}

	
	sort(arr, arr + num);


	for (int i = 0; i<num - 1; i++)
	{
		if (i != num - 2)
			cout << arr[i] << " ";
		else
			cout << arr[i] << endl;
	}

	return 0;
}