/*
给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述:

输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。



输出描述:

可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。


输入例子:

2000 3
2000 31
2000 40
2000 60
2000 61
2001 60


输出例子:

2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01


*/

/*
#include<iostream>
#include<iomanip>
using namespace std;

int mon = 0, day = 0;

void CalcDtae(int *Months,int days)
{
	for (int i =days;i>0;i--)
	{
		if (day==Months[mon])
		{
			mon++;
			day = 1;
		}
		else
		{
			day++;
		}
	}
}
int main(void)
{
	int year = 0, days = 0;
	int Months[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	while (cin >> year >> days)
	{

		if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		{
			Months[1] = 29;
			CalcDtae(Months,days);
		}
		else
		{
			Months[1] = 28;

			CalcDtae(Months,days);
		}
		cout << year << "-" << setw(2) << setfill('0') << mon+1 << "-" << setw(2) << setfill('0')<<day << endl;
		mon = 0, day = 0;
	}

	return 0;
}

*/


#include<iostream>
using namespace std;

int main(void)
{
	int a[10] = { 9,3,5,6,7,1,2,4,0,8 };

	int i, j;
	//for (i = 0; i < 9; i++)
	//{
	//	for (j = i+1; j < 10; j++)
	//	{
	//		if (a[i] > a[j])
	//		{
	//			int t = a[i];
	//			a[i] = a[j];
	//			a[j] = t;
	//		}
	//	}
	//}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 10-1-i; j++)
		{
			if (a[j] > a[j+1])
			{
				int t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}





	for (i = 0; i < 10; i++)
	{
		cout << a[i] << "," << endl;

	}



	//int row = 0;
	//int arr[100][100];
	//bool flag = true;
	//while (cin >> row)
	//{
	//	int i, j;
	//	for (i = 0; i<row; i++)
	//		for (j = 0; j<row; j++)
	//			cin >> arr[i][j];
	//	for (i = 0; i<row; i++)
	//	{
	//		for (j = 0; j<row; j++)
	//		{
	//			if (arr[i][j] != arr[j][i])
	//			{
	//				flag = false;
	//			}
	//		}

	//	}

	//	if (flag == true)
	//		cout << "Yes!" << endl;
	//	else
	//		cout << "No!" << endl;
	//}

	return 0;
}