#include<iostream>
#include<list>
#include<string>
using namespace std;

// 文件视图类
class IFile
{		 
public:
	virtual void display() = 0;
	virtual int add(IFile *ifile) = 0;
	virtual int remove(IFile *ifile) = 0;
	virtual list<IFile*> *getChild() = 0;
};

// 文件叶子节点
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

// 目录节点
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

// 递归的显示树
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

	// 1、显示根节点
	root->display();

	// 2、若根结点有孩子
			// 若孩子是文件，则显示文件名字
			// 若孩子是目录，递归showTree(子目录)
	
	list<IFile*>* mylist = root->getChild();

	if (mylist!=NULL)			// 说明是一个目录
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

	// 获取root节点下的孩子节点
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

	cout << "通过showTree 方式显示 root 结点下的所有子结点" << endl;

	showTree(root,0);
	return 0;
}

