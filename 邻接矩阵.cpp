#if 0
#include<stdio.h>
#define X 4
#define Y 4
// ��ӡ����
void pri(int a[][Y])
{
	int i, j;
	for (i = 0; i < X; i++)
	{
		for (j = 0; j < X; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
//�������
void scan(int b[][Y])
{
	int m, n;
	//printf("��������Ŀ����ʾͼ���ڽӾ���A�� \n");
	for (m = 0; m < X; m++)
		for (n = 0; n < Y; n++)
			scanf_s("%d", &b[m][n]);
}
//������ӣ�
void plus(int a[][Y], int b[][Y], int c[][Y])
{
	int d, s;
	for (d = 0; d < X; d++)
		for (s = 0; s < Y; s++)
			c[d][s] = a[d][s] + b[d][s];
	pri(c);
}
//�������
void mul(const int a[][Y], const int b[][Y], int c[][Y])
{
	int i, j, k;
	c[X][Y] = 0;
	for (i = 0; i < X; i++)
		for (j = 0; j < X; j++) {
			c[i][j] = 0;//add
			for (k = 0; k < X; k++)
				//c[i][j] += a[j][k] * b[k][j];//j ����
				c[i][j] += a[i][k] * b[k][j];
		}
	//printf("����Ϊ%d");
	pri(c);


}
//�������
void subtract(int a[][Y], int b[][Y], int c[][Y])
{
	int i, j;
	for (i = 0; i < X; i++)
		for (j = 0; j < X; j++)
			c[i][j] = a[i][j] - b[i][j];
	pri(c);
}
void copy(const int in[][Y], int out[][Y])
{
	for (int i = 0; i < X; i++)
		for (int j = 0; j < Y; j++)
			out[i][j] = in[i][j];
}
void Tlhl(int a[][Y])
{
	int temp = 1;
	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < X; i++)
	{
		for (int j = 0; j < X; j++)
		{
			sum1 += a[i][j];
			if (j == i)
				sum2 += a[i][j];
		}
	}
	printf("����Ϊ��ͨ·�У�%d��\n", sum1);
	printf("��·�У�%d��\n", sum2);
}
//������׳�(A^1~A^4);
void Fact(int a[][Y], int c[][Y])
{
	int i, j, k, x, temp = 1;
	int sum1 = 0, sum2 = 0;
	int d[X][Y] = { 0 };
	int b[X][Y] = { 0 };
	printf("����������ͼ���ڽӾ���A��\n");
	scan(a);
	copy(a, d);//��a���Ƹ�d
	for (x = 0; x < 3; x++)
	{
		printf("����� %d�� ��A�׳ˣ�   \n", temp);

		mul(a, d, c);//����a d  ��� c
		Tlhl(c);
		copy(c, d);//��c���Ƹ�d ���ڲ�����һ��ѭ��
		temp++;
		//pri(c);

	}
}
int main()
{
	int a[X][Y] = { 0 };// { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int m = 1, n = 1, o, p;
	//int a[X][Y];
	int b[X][Y] = { 0 }, c[X][Y] = { 0 }, d[X][Y] = { 0 };
	while (m == 1)
	{
		printf("�����룺1--��ʾ�����ļ� �� ������  2--��ʾ�����׳�\n");
		scanf_s("%d", &p);
		if (p == 1)
		{
			printf(" ���������A��\n");
			scan(a);
			printf(" ���������B��\n");
			scan(b);
			printf("�����������������ͣ�1---�������  2---�������  3---�������\n");
			scanf_s("%d", &o);
			if (o == 1)   plus(a, b, c);
			if (o == 2)  subtract(a, b, c);
			if (o == 3)  mul(a, b, c);
			printf("������1��ʾ�������㣬2��ʾ�˳�����\n");
			scanf_s("%d", &m);
			printf("\n");
		}
		else
		{
			Fact(a, c);
			printf("������1��ʾ�������㣬2��ʾ�˳�����\n");
			scanf_s("%d", &m);
			printf("\n");

		}

	}
	return 0;
}
#endif
#include<stdio.h>
#define X 100
#define Y 100
int temp = 1;
int len = 0;
// ��ӡ����
void pri(int a[][Y], int len)
{
	int i, j;

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len; j++)
			printf("%5d", a[i][j]);
		printf("\n");
	}
}
//�������
void scan(int b[][Y], int len)
{
	int m, n;
	//printf("��������Ŀ����ʾͼ���ڽӾ���A�� \n");
	for (m = 0; m < len; m++)
		for (n = 0; n <len; n++)
			scanf("%d", &b[m][n]);
}
//������ӣ�
void plus(int a[][Y], int b[][Y], int c[][Y], int len)
{
	int d, s;
	for (d = 0; d < len; d++)
		for (s = 0; s <len; s++)
			c[d][s] = a[d][s] + b[d][s];
	pri(c, len);
}
//�������
void mul(const int a[][Y], const int b[][Y], int c[][Y], int len)
{
	int i, j, k;
	c[X][Y] = 0;
	for (i = 0; i <len; i++)
		for (j = 0; j < len; j++) {
			c[i][j] = 0;//add
			for (k = 0; k <len; k++)
				//c[i][j] += a[j][k] * b[k][j];//j ����
				c[i][j] += a[i][k] * b[k][j];
		}
	//printf("����Ϊ%d");
	pri(c, len);
}
//�������
void subtract(int a[][Y], int b[][Y], int c[][Y], int len)
{
	int i, j;
	for (i = 0; i <len; i++)
		for (j = 0; j < len; j++)
			c[i][j] = a[i][j] - b[i][j];
	pri(c, len);
}
void copy(const int in[][Y], int out[][Y], int len)
{
	for (int i = 0; i <len; i++)
		for (int j = 0; j <len; j++)
			out[i][j] = in[i][j];
}
void Tlhl(int a[][Y], int len)
{

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i <len; i++)
	{
		for (int j = 0; j <len; j++)
		{
			sum1 += a[i][j];
			if (j == i)
				sum2 += a[i][j];
		}
	}
	printf("����Ϊ%d��ͨ·�У�%d��\n", temp, sum1);
	printf("��·�У�%d��\n", sum2);
}
//������׳�(A^1~A^4);
void Fact(int a[][Y], int c[][Y], int len)
{
	int i, j, k, x;
	int sum1 = 0, sum2 = 0;
	int d[X][Y] = { 0 };
	int b[X][Y] = { 0 };
	printf("����������ͼ���ڽӾ���A��\n");
	scan(a, len);
	copy(a, d, len);//��a���Ƹ�d
	printf("����� %d�� ��A�׳ˣ�   \n", temp);
	{
		pri(a, len);

		Tlhl(a, len);
		temp++;
	}
	for (x = 0; x < len; x++)
	{
		printf("����� %d�� ��A�׳ˣ�   \n", temp);

		mul(a, d, c, len);//����a d  ��� c
		Tlhl(c, len);
		copy(c, d, len);//��c���Ƹ�d ���ڲ�����һ��ѭ��
		temp++;
		//pri(c);

	}
}
int main()
{
	int a[X][Y] = { 0 };// { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int m = 1, n = 1, o, p;
	//int a[X][Y];
	int b[X][Y] = { 0 }, c[X][Y] = { 0 }, d[X][Y] = { 0 };
	while (m == 1)
	{
		printf("�����룺1--��ʾ�����ļ� �� ������  2--��ʾ�����׳�\n");
		scanf("%d", &p);

		if (p == 1)
		{
			printf("������Ҫ���ڽӾ���Ľ�����\n");
			scanf("%d", &len);
			printf(" ���������A��\n");
			scan(a, len);
			printf(" ���������B��\n");
			scan(b, len);
			printf("�����������������ͣ�1---�������  2---�������  3---�������\n");
			scanf("%d", &o);
			if (o == 1)   plus(a, b, c, len);
			if (o == 2)  subtract(a, b, c, len);
			if (o == 3)  mul(a, b, c, len);
			printf("������1��ʾ�������㣬2��ʾ�˳�����\n");
			scanf("%d", &m);
			printf("\n");
		}
		else
		{
			printf("������Ҫ���ڽӾ���Ľ�����\n");
			scanf("%d", &len);
			Fact(a, c, len);
			printf("������1��ʾ�������㣬2��ʾ�˳�����\n");
			scanf("%d", &m);
			printf("\n");

		}

	}
	return 0;
}
