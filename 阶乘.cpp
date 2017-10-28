#include<iostream>
using namespace std;

int fac(int x)
{
	int result = 1;
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	for (int i = 2; i <= x; i++)
		result *= i;
	return result;
}

int main(void)
{
	int n = 0;
	while (cin >> n)
	{

		int y1 = 0, y2 = 0;


		for (int i = 0; i <= n; i++)
		{
			if (i % 2 == 0)
			{
				y2 += fac(i);
			}
			else
			{
				y1 += fac(i);
			}
		}
		cout << y1 << " " << y2 << endl;
	}
	return 0;
}