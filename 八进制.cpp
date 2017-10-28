#include<iostream>
using namespace std;
int main(void)
{
	int arr[100001] = { 0 };
	int num = 0;

	while (cin >> num)
	{
		int k = 0;
		while (num != 0)
		{
			int t = num % 16;
			arr[k] = t;
			num /= 16;
			k++;
		}

		for (int i = k-1;i >= 0; i--)
		{
			cout << arr[i];
		}
		cout << endl;
	}
	return 0;
}