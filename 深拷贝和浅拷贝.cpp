#include<iostream>
using namespace std;

class Student
{
public:
	Student(char *name)
	{
		m_len = strlen(name) + 1;
		m_name = new char[m_len];
		strcpy(m_name, name);

	}
	// �������캯��
	// Student s2 = s2;     
	Student(const Student &obj)
	{
		m_len = obj.m_len;
		m_name = new char[m_len];
		strcpy(m_name,obj.m_name);
	}

	// = ������ڴ�й©
	void operator=(Student &obj)
	{
		// �ͷ�֮ǰ���ڴ�ռ�
		if (obj.m_name!=NULL)
		{
			delete m_name;
			m_name = NULL;
			m_len = 0;
		}
		// ���·����ڴ�ռ�
		m_len = obj.m_len;
		m_name = new char[obj.m_len];
		strcpy(m_name,obj.m_name);
	}

	~Student()
	{
		if (NULL!=m_name)
		{
			delete m_name;
			m_name = NULL;
			m_len = 0;
		}
	}

private:
	char	*m_name;
	int		m_len;
};

void Copy()
{
	Student s1("abc");
	Student s2 = s1;     // ��һ������ȥ��ʼ����һ���µ�ͬ���Ͷ���
	// ����ʱ��������s2,������s1,��ʱ����core down

	// = ������ڴ�й©
	Student s3("");
	s3 = s1;
}

int main(void)
{
	// Copy();
	char *p = new char[4];
	strcpy(p,"abc");
	cout << p << endl;
	int a = 0;
	return 0;
}

/*

������������к���ָ�����ʱ���ڶ���֮����г�ʼ���������ö���Ŀ������캯���������� = ��������ʱ�򣬽������ڵ�ָ��
		���������ڴ�ռ��е�����Ҳ���п�����
ǳ�������������к���ָ�����ʱ���ڶ���֮����г�ʼ���������ö���Ŀ������캯���������� = ��������ʱ�򣬵����Ľ�ָ���ֵ��Ҳ������ָ�ڴ�ռ���׵�ַ�����п���
		��͵������������ָ������ͬһ���ڴ�ռ䣬�����ڶ��������������ʱ�����������������ͷ��ڴ��ʱ������code down�����
ԭ�������
		��ΪC++Ĭ�ϵĿ������캯���� = ��������ǳ������������ֻ�ǽ�ָ����и�ֵ
�����������д��Ŀ������캯�� �� = �����

��Ҫע��ĵ㣺

		1. �����ǳ�����������������Ա�а�����ָ�����ʱ��

		2. =�������Ͷ���ĳ�ʼ�������ֲ�ͬ�Ķ�����

		3. �ر�ע�⣺�ڽ��еȺŲ������ص�ʱ���Ƚ�ԭ�����ڴ�ռ��ͷţ����ڴ�й©��
*/


// ��ʱ����Ķ���s2��ָ��Ӧ�ý����������̬�����ڴ�ռ䣬Ȼ����и�ֵ������ֻ�ǰ� s1 ��ָ�븳ֵ�� s2 ������ָ��ͬһ���ڴ�ռ�