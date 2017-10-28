/*
N阶楼梯上楼问题：一次可以走两阶或一阶，问有多少种上楼方式。（要求采用非递归）
输入描述:

输入包括一个整数N,(1<=N<90)。



输出描述:

可能有多组测试数据，对于每组数据，
输出当楼梯阶数是N时的上楼方式个数。


输入例子:

4


输出例子:

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
