#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	virtual Person*clone()=0;
	virtual void printT() = 0;
};

class CPlusPlusProgram:public Person
{
public:
	CPlusPlusProgram()
	{
		m_name = "";
		m_age = 0;
		m_p = NULL;
		setReMeme("");
	}
	CPlusPlusProgram(string name, int age,char *p)
	{
		m_name = name;
		m_age = age;
		m_p = NULL;
		setReMeme(p);
	}

	
	// Ç³¿½±´
	Person *clone()
	{
		CPlusPlusProgram *tmp = new CPlusPlusProgram;
		*tmp = *this;
		return tmp;
	}
	
	void setReMeme(char *p)
	{
		if (m_p!=NULL)
		{
			delete m_p;
		}
		m_p = new char[strlen(p) + 1];
		strcpy(m_p,p);
	}
	

	
	// Éî¿½±´
	/*Person *clone()
	{
		CPlusPlusProgram *tmp = new CPlusPlusProgram;
		tmp->m_name = this->m_name;
		tmp->m_age = this->m_age;

		int len = strlen(this->m_p);
		if (tmp->m_p != NULL)
		{
			delete tmp->m_p;
			tmp->m_p = NULL;
		}
		tmp->m_p = new char[len + 1];
		strcpy(tmp->m_p, this->m_p);

		return tmp;
	}*/
	
	void printT()
	{
		cout << "m_name: " << m_name << "  m_age: " << m_age<<"  m_p: " <<&m_p<< endl;
	}
private:
	string m_name;
	int m_age;
	char *m_p;
};


int main(void)
{
	Person *c1 = new CPlusPlusProgram("ÕÅÈý",20,"AAA");
	c1->printT();

	Person *c2 = c1->clone();
	c2->printT();
	return 0;
}