/*
������������һ������������ƽ���ĵ�λ���ֵ��������� ����25��ƽ����625����λ������25�����25��һ���������� ��һ�������ж�N�Ƿ�Ϊ��������
�������� :

�������1������N��2 <= N<100��



	������� :

�����ж���������ݣ�����ÿ�����ݣ�
���"Yes!����ʾN����������
���"No!����ʾN������������


�������� :

	25
	4


	������� :

	Yes!
	No!

*/

#include<iostream>
using namespace std;

bool Judge(int num)
{
	bool ans = true;
	int n = num*num;

	while (num != 0)
	{
		if (n % 10 != num % 10)
		{
			ans = false;
			break;
		}
		n /= 10;
		num /= 10;
	}
	return ans;
}
int main(void)
{
	int num = 0;
	while (cin >> num)
	{

		if (Judge(num))
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;
	}
	return 0;
}