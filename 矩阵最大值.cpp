/*

编写一个程序输入一个mXn的矩阵存储并输出，并且求出每行的最大值和每行的总和。 要求把每行总和放入每行最大值的位置，如果有多个最大值，取下标值最小的那一个作为最大值。 最后将结果矩阵输出。
输入描述:

输入的第一行包括两个整数m和n(1<=m,n<=100)，分别代表矩阵的行和列的维数。
接下来的m行每行有n个数，代表矩阵的元素。



输出描述:

可能有多组测试数据，对于每组数据，输出按题目要求执行后的矩阵。


输入例子:

3 3
1 1 1
1 1 1
1 1 1
3 3
3 2 3
2 3 2
3 2 3


输出例子:

3 1 1
3 1 1
3 1 1
8 2 3
2 7 2
8 2 3


*/



#include<iostream>
using namespace std;

int main(void)
{
	int row ;
	int clo;
	int arr[100][100];
	int i, j;
	
	int p_x = 0, p_y = 0;
	while (cin >> row >> clo)
	{
		for ( i = 0; i < row; i++)
			for (j = 0; j < clo; j++)
				cin >> arr[i][j];

	//	show(arr,row,clo);

		for (i = 0; i < row; i++)
		{
			int sum = 0;
			int  maxValue = arr[i][0];
			p_x = i, p_y = 0;
			for (j = 0; j < clo; j++)
			{
				sum += arr[i][j];
				if (arr[i][j] >maxValue)
				{
					maxValue = arr[i][j];
					p_x = i;
					p_y = j;
				}
			}

			arr[p_x][p_y] = sum;
		}


		for (i = 0; i < row; i++)
		{
			for (j = 0; j < clo; j++)
			{
				cout << arr[i][j];
				if (j != clo - 1)
					cout << " ";
				else
					cout << endl;

			}
			cout << endl;
		}

	}




	return 0;
}