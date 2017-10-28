/*

题目描述
输入一个N*N的矩阵，将其转置后输出。要求：不得使用任何数组(就地逆置)。
输入描述:

输入的第一行包括一个整数N,(1<=N<=100)，代表矩阵的维数。
接下来的N行每行有N个整数，分别代表矩阵的元素。



输出描述:

可能有多组测试数据，对于每组数据，将输入的矩阵转置后输出。


输入例子:

3
1 2 3
4 5 6
7 8 9


输出例子:

1 4 7
2 5 8
3 6 9

*/

#include<iostream>
using namespace std;
#define  LEN 100

void Change(int (*arr)[100],int  num)
{
	int i, j;
	for (i = 0; i < num; i++)
	{
		for (j = i+1; j < num; j++)
		{
				int temp = arr[i][j];
				arr[i][j] = arr[j][i];
				arr[j][i] = temp;
		}
	}
}

int main(void)
{

	int arr[LEN][LEN];
	int num = 0;
	while (cin>>num)
	{
		int i, j;
		for (i = 0; i < num; i++)
			for (j = 0; j < num; j++)
				cin >> arr[i][j];

		Change(arr,num);

		for (int i = 0; i < num; i++)
		{
			for (int j =0; j < num; j++)
			{
				if (j==0)
				{
					cout << arr[i][j];
				}
				else
				{
					cout << " " << arr[i][j];
				}
			}
			cout << endl;
		}

	}

	return 0;
}



/*


5

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25


1 2 11 16 21
6 7 12 17 22
3 8 13 14 15
4 9 18 19 20
5 10 23 24 25







*/