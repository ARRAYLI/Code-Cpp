/*
��Ŀ����
ְ����ְ���ţ�����������.����n��ְ������Ϣ���ҳ�3��������С��ְ����ӡ������
��������:

�����һ�а���1������N��1<=N<=30�������������ݵĸ�����
��������N����N��ְ������Ϣ��
����ְ����(����)�� ����(�ַ��������Ȳ�����10)�� ����(1<=age<=100)��



�������:

�����ж���������ݣ�����ÿ�����ݣ�
����������ΪN��3�Ľ�Сֵ���ֱ�Ϊ������С��ְ������Ϣ��
�ؼ���˳������>����>��������С����


��������:

5
501 Jack 6
102 Nathon 100
599 Lily 79
923 Lucy 15
814 Mickle 65


�������:

501 Jack 6
923 Lucy 15
814 Mickle 65

*/

#include<iostream>
using namespace std;

typedef struct /*__Employee*/
{
	int num;
	char name[10];
	int age;
}Employee;

int main(void)
{
	int count = 0;
	Employee employee[30];
	while (cin >> count)
	{
		int i, j;
		for (i = 0; i<count; i++)
		{
			cin >> employee[i].num >> employee[i].name >> employee[i].age;
		}

		for (i = 0; i<count - 1; i++)
		{
			for (j = i + 1; j<count; j++)
			{
				if (employee[i].age>employee[j].age)
				{
					Employee temp;
					temp = employee[i];
					employee[i] = employee[j];
					employee[j] =temp;
				}
			}

		}

		for (i = 0; i<3; i++)
		{
			cout << employee[i].num <<"   "<< employee[i].name << "   " << employee[i].age << endl;
		}

	}

	return 0;
}

