/*

��дһ����������һ��mXn�ľ���洢��������������ÿ�е����ֵ��ÿ�е��ܺ͡� Ҫ���ÿ���ܺͷ���ÿ�����ֵ��λ�ã�����ж�����ֵ��ȡ�±�ֵ��С����һ����Ϊ���ֵ�� ��󽫽�����������
��������:

����ĵ�һ�а�����������m��n(1<=m,n<=100)���ֱ���������к��е�ά����
��������m��ÿ����n��������������Ԫ�ء�



�������:

�����ж���������ݣ�����ÿ�����ݣ��������ĿҪ��ִ�к�ľ���


��������:

3 3
1 1 1
1 1 1
1 1 1
3 3
3 2 3
2 3 2
3 2 3


�������:

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