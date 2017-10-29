/*
题目描述
职工有职工号，姓名，年龄.输入n个职工的信息，找出3个年龄最小的职工打印出来。
输入描述:

输入第一行包括1个整数N，1<=N<=30，代表输入数据的个数。
接下来的N行有N个职工的信息：
包括职工号(整数)， 姓名(字符串，长度不超过10)， 年龄(1<=age<=100)。



输出描述:

可能有多组测试数据，对于每组数据，
输出结果行数为N和3的较小值，分别为年龄最小的职工的信息。
关键字顺序：年龄>工号>姓名，从小到大。


输入例子:

5
501 Jack 6
102 Nathon 100
599 Lily 79
923 Lucy 15
814 Mickle 65


输出例子:

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

