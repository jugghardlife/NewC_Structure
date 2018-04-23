#include "LinkList.h"

//��ʼ������
LinkList* Init_LinkList()
{
	LinkList* list=(LinkList*)malloc(sizeof(LinkList));
	list->size=0;

	//ͷ��� �ǲ�����������Ϣ
	list->head=(LinkNode*)malloc(sizeof(LinkNode));
	list->head->data=NULL;
	list->head->next=NULL;
	return list;
}
//ָ��λ�ò���
void Insert_LinkList(LinkList* list,int pos,void *data)
{
	int i;
	LinkNode* newnode=(LinkNode*)malloc(sizeof(LinkNode));
	LinkNode* pCurrent=list->head;
	if(NULL==list)
	{
		return;
	}
	
	if(NULL==data)
	{
		return;
	}

	//�Ѻô���posԽ��
	if(pos<0 || pos>list->size)
	{
		pos=list->size;
	}
	
	//�����µĽ��
	newnode->data=data;
	newnode->next=NULL;
	//�ҽڵ�
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}

	//�½��������
	newnode->next=pCurrent->next;
	pCurrent->next=newnode;

	list->size++;
}
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list,int pos)
{
	int i;
	LinkNode* pCurrent=list->head;
	LinkNode* pDel;
	if(NULL==list)
	{
		return;
	}
	//����ɾ�����ǰһ�����
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}
	
	//����ɾ���Ľ��
	pDel=pCurrent->next;
	pCurrent->next=pDel->next;
	//�ͷ�ɾ�������ڴ�
	free(pDel);

	list->size--;
}
//��ȡ����ĳ���
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//����
int Find_LinkList(LinkList* list,void* data)
{
	int i=0;
	LinkNode* pCurrent=list->head->next;
	if(NULL==list)
	{
		return -1;
	}

	if(NULL==data)
	{
		return -1;
	}

	//��������
	i=0;
	while(pCurrent!=NULL)
	{
		if(pCurrent->data==data)
		{
			break;
		}
		i++;
		pCurrent=pCurrent->next;
	}

	return i;
}
//���ص�һ�����
void* Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}
//��ӡ������
void Print_LinkList(LinkList* list,PRINTLINKNODE print)
{
	LinkNode* pCurrent=list->head->next;
	if(list==NULL)
	{
		return;
	}
	while(pCurrent!=NULL)
	{
		print(pCurrent->data);
		pCurrent=pCurrent->next;
	}
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	LinkNode* pCurrent=list->head;
	if(NULL==list)
	{
		return;
	}

	while(pCurrent!=NULL)
	{
		//������һ���ڵ�
		LinkNode *pNext=pCurrent->next;
		free(pCurrent);
		pCurrent=pNext;
	}
	//�ͷ������ڴ�
	list->size=0;
	free(list);
}
