#include<iostream>
#include<list>
#include<string>
using namespace std;

// �ļ���ͼ��
class IFile
{		 
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile*> *getChild() = 0;
};

// �ļ�Ҷ�ӽڵ�
class File :public IFile
{
public:
	File(string name)
	{
		m_name = name;
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		return -1;
	}
	virtual int remove(IFile *ifile)
	{
		return -1;
	}
	virtual list<IFile*>* getChild()
	{
		return NULL;
	}

private:
	string m_name;
};

// Ŀ¼�ڵ�
class Dir:public IFile
{
public:
	Dir(string name)
	{
		m_name = name;
		m_list = new list<IFile*>;
		m_list->clear();
	}
	virtual void display()
	{
		cout << m_name << endl;
	}
	virtual int add(IFile *ifile)
	{
		m_list->push_back(ifile);
		return 0;
	}
	virtual int remove(IFile *ifile)
	{
		m_list->remove(ifile);
		return 0;
	}
	virtual list<IFile*>* getChild()
	{
		return m_list;
	}

private:
	string m_name;
	list<IFile*>* m_list;
};

// �ݹ����ʾ��
void showTree(IFile* root,int level)
{
	int i = 0;
	if (NULL==root)
	{
		return;
	}

	for (i=0;i<level;i++)
	{
		cout << "\t";
	}

	// 1����ʾ���ڵ�
	root->display();

	// 2����������к���
			// ���������ļ�������ʾ�ļ�����
			// ��������Ŀ¼���ݹ�showTree(��Ŀ¼)
	
	list<IFile*>* mylist = root->getChild();

	if (mylist!=NULL)			// ˵����һ��Ŀ¼
	{
		for (list<IFile*>::iterator it = mylist->begin(); it != mylist->end(); ++it)
		{
			if ((*it)->getChild()==NULL)
			{
				for (i = 0; i<=level; i++)
				{
					cout << "\t";
				}
				(*it)->display();
			}
			else
			{
				showTree(*it,level+1);
			}
		}
	}
}
int main(void)
{
	Dir *root = new Dir("C");
//	root->display();
	
	Dir *dir1 = new Dir("111dir");
	File *aaaFile = new File("aaa.txt");
	root->display();

	// ��ȡroot�ڵ��µĺ��ӽڵ�
	list<IFile*>* mylist = root->getChild();

	root->add(dir1);
	root->add(aaaFile);

	for (list<IFile*>::iterator it=mylist->begin();it!=mylist->end();++it)
	{
		(*it)->display();
	}

	Dir *dir2 = new Dir("222dir");
	File *bbbFile = new File("bbb.txt");
	dir1->add(dir2);
	dir1->add(bbbFile);

	cout << "ͨ��showTree ��ʽ��ʾ root ����µ������ӽ��" << endl;

	showTree(root,0);
	return 0;
}

