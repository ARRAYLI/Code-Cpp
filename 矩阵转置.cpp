/*

��Ŀ����
����һ��N*N�ľ��󣬽���ת�ú������Ҫ�󣺲���ʹ���κ�����(�͵�����)��
��������:

����ĵ�һ�а���һ������N,(1<=N<=100)����������ά����
��������N��ÿ����N���������ֱ��������Ԫ�ء�



�������:

�����ж���������ݣ�����ÿ�����ݣ�������ľ���ת�ú������


��������:

3
1 2 3
4 5 6
7 8 9


�������:

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