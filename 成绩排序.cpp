/*

��Ŀ����
��N��ѧ�������ݣ���ѧ�����ݰ��ɼ��ߵ���������ɼ���ͬ�������ַ�����ĸ�����������������ĸ��Ҳ��ͬ����ѧ�����������򣬲����N��ѧ����������Ϣ��
��������:

���������ж��飬ÿ�������һ����һ������N��N<=1000������������N�а���N��ѧ�������ݡ�
ÿ��ѧ�������ݰ������������Ȳ�����100���ַ����������䣨�����������ɼ���С�ڵ���100����������



�������:

��ѧ����Ϣ���ɼ��������򣬳ɼ���ͬ������������ĸ���������
Ȼ�����ѧ����Ϣ���������¸�ʽ��
���� ���� �ɼ�

ѧ����������ĸ��������ĸ�Ĵ�Сд����AҪ��a����ĸ��ǰ(��ΪA��ASC���a��ASC��ҪС)��


��������:

3
abc 20 99
bcd 19 97
bed 20 97


�������:

bcd 19 97
bed 20 97
abc 20 99

*/

#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

typedef struct
{
	char name[100];
	int age;
	int score;
}Stu;

int cmp(const Stu &stu1, const Stu &stu2)
{
	if (stu1.score != stu2.score)
		return stu1.score < stu2.score;
	else if (strcmp(stu1.name, stu2.name) != 0)
		return strcmp(stu1.name, stu2.name)<0;
	else
		return stu1.age < stu2.age;
}

int main(void)
{
	Stu stu[1000];
	int num = 0;
	while (cin >> num)
	{
		for (int i = 0; i<num; i++)
			cin >> stu[i].name >> stu[i].age >> stu[i].score;
		sort(stu, stu + num, cmp);

		for (int i = 0; i<num; i++)
			cout << stu[i].name << " " << stu[i].age << " " << stu[i].score << endl;
	}
	return 0;
}


