/*

����һ�������������������
��������:

�����ÿ�������е�һ�а���1��������n(1<=n<=1000)����������һ�а���n��������



�������:

�����ж���������ݣ�����ÿ�����ݣ�
��n������������������֮��������������


��������:

4
3 5 7 9


�������:

3 5 7 9


*/

#include<iostream>
using namespace std;

typedef struct __Node
{
	int data;
	struct __Node *next;
}Node,*PNode; 

// ��ʼ������

void InitLinkList(PNode *pHead)
{
	*pHead = new Node;
	(*pHead)->next = NULL;
	(*pHead)->data = 0;
}

// β����
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

// ��ӡ����е�ֵ

void show(PNode *pHead)
{
	PNode ppHead = (*pHead)->next;
	while (ppHead!=NULL)
	{
		cout <<ppHead->data << " ";
	}
	cout << endl;
}

// ��������

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