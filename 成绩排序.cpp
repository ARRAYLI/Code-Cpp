/*

题目描述
有N个学生的数据，将学生数据按成绩高低排序，如果成绩相同则按姓名字符的字母序排序，如果姓名的字母序也相同则按照学生的年龄排序，并输出N个学生排序后的信息。
输入描述:

测试数据有多组，每组输入第一行有一个整数N（N<=1000），接下来的N行包括N个学生的数据。
每个学生的数据包括姓名（长度不超过100的字符串）、年龄（整形数）、成绩（小于等于100的正数）。



输出描述:

将学生信息按成绩进行排序，成绩相同的则按姓名的字母序进行排序。
然后输出学生信息，按照如下格式：
姓名 年龄 成绩

学生姓名的字母序区分字母的大小写，如A要比a的字母序靠前(因为A的ASC码比a的ASC码要小)。


输入例子:

3
abc 20 99
bcd 19 97
bed 20 97


输出例子:

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


