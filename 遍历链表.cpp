/*

建立一个升序链表并遍历输出。
输入描述:

输入的每个案例中第一行包括1个整数：n(1<=n<=1000)，接下来的一行包括n个整数。



输出描述:

可能有多组测试数据，对于每组数据，
将n个整数建立升序链表，之后遍历链表并输出。


输入例子:

4
3 5 7 9


输出例子:

3 5 7 9


*/

#include<iostream>
using namespace std;

typedef struct __Node
{
	int data;
	struct __Node *next;
}Node,*PNode; 

// 初始化链表

void InitLinkList(PNode *pHead)
{
	*pHead = new Node;
	(*pHead)->next = NULL;
	(*pHead)->data = 0;
}

// 尾插结点
void InsertByTail(PNode *pHead,int val)
{
	PNode pNext = new Node;
	pNext->data = val;
	if ((*pHead)->next==NULL)
	{
		(*pHead)->next = pNext;
		pNext->next = NULL;
	}
	else
	{
		PNode pNNode = *pHead;
		while (pNNode->next!=NULL)
		{
			pNNode = pNNode->next;
		}

		pNNode->next = pNext;
		pNext->next = NULL;
	}
}

// 打印结点中的值

void show(PNode *pHead)
{
	PNode ppHead = (*pHead)->next;
	while (ppHead!=NULL)
	{
		cout <<ppHead->data << " ";
	}
	cout << endl;
}

// 销毁链表

void DestoryLinkList(PNode *pHead)
{
	while (*pHead!=NULL)
	{
		PNode *pTemp = pHead;
		(*pHead) = (*pHead)->next;
		delete pTemp;
		pTemp = NULL;
	}
}


int main(void)
{
	Node *pHead=NULL;
	InitLinkList(&pHead);
	InsertByTail(&pHead,1);
	InsertByTail(&pHead, 2);
	InsertByTail(&pHead, 3);
	InsertByTail(&pHead, 4);
	show(&pHead);
	DestoryLinkList(&pHead);
	return 0;
}