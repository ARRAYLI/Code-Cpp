#include<iostream>
#include<vector>
using namespace std;

class Teacher
{
public:
	Teacher(char *name,int age)
	{
		m_name = new char[strlen(name) + 1];
		strcpy(m_name,name);
		m_age = age;
	}
	~Teacher()
	{
		if (NULL != m_name)
		{
			delete [] m_name;
			m_name = NULL;
			m_age = 0;
		}
	}

	// 拷贝构造函数
	Teacher(const Teacher& obj)
	{
		m_name = new char[strlen(obj.m_name) + 1];
		strcpy(m_name,obj.m_name);
		m_age = obj.m_age;
	}

	//  重载 =  操作符
	// t3 = t2 = t1
	Teacher & operator=(const Teacher & obj)
	{
		// 先把旧的内存释放掉
		if (m_name != NULL)
		{
			delete  [] m_name;
			m_name  = NULL;
			m_age = 0;
		}

		// 根据 t1 的大小分配内存 
		m_name = new char[strlen(obj.m_name) + 1];
		
		// copy t1 的数据
		m_name = strcpy(m_name, obj.m_name);
		m_age = obj.m_age;
	}
private:
	char*	m_name;
	int		m_age;
};

void test()
{
	Teacher t("zhangsan",31);
	vector<Teacher>   v;
	v.push_back(t);			// 把 t 拷贝了一份到容器中...
}

int main(void)
{
	test();

	return 0;
}