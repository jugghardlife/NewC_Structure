#include "qLinkList.h"


//��ʼ������
LinkList* Init_LinkList()
{
	LinkList* list=(LinkList*)malloc(sizeof(LinkList));
	list->head.next=NULL;
	list->size=0;
	return list;
}
//����
void Insert_LinkList(LinkList* list,int pos,LinkNode* data)
{
	int i;
	LinkNode* pCurrent=&(list->head);
	if(NULL==list)
	{
		return ;
	}

	if(NULL==data)
	{
		return ;
	}

	if(pos<0 || pos>list->size)
	{
		pos=list->size;
	}

	//���Ҳ���λ��
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}
	
	//�����½��
	data->next=pCurrent->next;
	pCurrent->next=data;

	list->size++;
}
//ɾ��
void Remove_LinkList(LinkList* list,int pos)
{	
	int i;
	//����ָ�����
	LinkNode* pCurrent=&(list->head);
	if(NULL==list)
	{
		return ;
	}
	
	if(pos<0 || pos>list->size)
	{
		return ;
	}
	
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}
	//ɾ�����
	pCurrent->next=pCurrent->next->next;
	list->size--;
}
//����
int Find_LinkList(LinkList* list,LinkNode* data,COMPARENODE compare)
{
	//����ָ��
	LinkNode* pCurrent=list->head.next;
	int index=0;
	int flag=-1;
	if(NULL==list)
	{
		return -1;
	}

	if(NULL==data)
	{
		return -1;
	}
	
	//����
	while(pCurrent !=NULL)
	{
		if(compare(pCurrent,data)==0)
		{
			flag=index;
			break;
		}
		pCurrent = pCurrent->next;
		index++;
	}
	return flag;
}
//���������С
int Size_LinkList(LinkList* list)
{
	return 0;
}
//��ӡ
void Print_LinkList(LinkList* list,PRINTNODE print)
{
	//����ָ��
	LinkNode* pCurrent=list->head.next;

	if(NULL==list)
	{
		return ;
	}
	while(pCurrent!=NULL)
	{
		print(pCurrent);
		pCurrent=pCurrent->next;
	}
}
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list)
{
	if(NULL==list)
	{
		return ;
	}

	free(list);
}