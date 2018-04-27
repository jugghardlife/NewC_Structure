#include "CircleLinkList.h"

//��ʼ������
CircleLinkList* Init_CircleLinKList()
{
	CircleLinkList* clist=(CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next=&(clist->head);
	clist->size=0;
	return clist;
}
//���뺯��
void Insert_CircleLinKList(CircleLinkList* clist,int pos,CircleLinkNode* data)
{
	//����ָ�����
	CircleLinkNode* pCurrent=&(clist->head);
	int i=0;
	if(NULL==clist)
	{
		return ;
	}

	if(NULL==data)
	{
		return ;
	}

	if(pos<0 || pos>clist->size)
	{
		pos=clist->size;
	}

	//����λ�ò��ҽ��
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}

	//�����ݲ�������
	data->next=pCurrent->next;
	pCurrent->next=data;

	clist->size++;
}
//��ȡ��һ��Ԫ��
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}
//����λ��ɾ��
void RemoveByPos_CircleLinkList(CircleLinkList* clist,int pos)
{
	//����ָ�����
	CircleLinkNode* pCurrent=&(clist->head);
	//���浱ǰ������һ�����
	CircleLinkNode* pNext=pCurrent->next;
	int i;
	if(NULL==clist)
	{
		return ;
	}

	if(pos<0||pos>=clist->size)
	{
		return ;
	}
	
	//����pos�ҽڵ�
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}
	
	
	pCurrent->next=pNext->next;

	clist->size--;
}
//����ֵɾ��
void RemoveByValue_CircleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare)
{
	CircleLinkNode* pPrev=&(clist->head);
	//����ָ��
	CircleLinkNode* pCurrent=pPrev->next;
	int i;
	if(NULL==clist)
	{
		return ;
	}
	
	if(NULL==data)
	{
		return ;
	}

	//�����ѭ������
	for(i=0;i<clist->size;i++)
	{
		if(compare(pCurrent,data)==CIRCLELINKLIST_TRUE)
		{
			//ɾ��
			pPrev->next=pCurrent->next;
			clist->size--;
			break;
		}
		pPrev=pCurrent;
		pCurrent=pPrev->next;
	}
}
//�������ĳ���
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}
//�ж��Ƿ�Ϊ��
int IsEmpty_CircleLinkList(CircleLinkList* clist)
{
	if(0==clist->size)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
//����
int Find_CircleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare)
{
	//����ָ�����
	CircleLinkNode* pCurrent=clist->head.next;
	int i;
	int flag=-1;
	if(NULL==clist)
	{
		return -1;
	}
	
	if(NULL==data)
	{
		return -1;
	}
	
	for(i=0;i<clist->size;i++)
	{	
		if(CIRCLELINKLIST_TRUE==compare(pCurrent,data))
		{
			flag=i;
			break ;
		}
		pCurrent=pCurrent->next;
	}

	return flag;
}
//��ӡ���
void Print_CircleLinkList(CircleLinkList* clist,PRINTNODE print)
{
	//����ָ�����
	CircleLinkNode* pCurrent=clist->head.next;
	int i;

	if(NULL==clist)
	{
		return ;
	}
	
	for(i=0;i<clist->size;i++)
	{
		if(pCurrent==&(clist->head))
		{
			pCurrent=pCurrent->next;
		}
		print(pCurrent);
		pCurrent=pCurrent->next;
	}
}
//�ͷ��ڴ�
void FreeSpace_CircleLinkList(CircleLinkList* clist)
{
	if(NULL==clist)
	{
		return ;
	}
	free(clist);
}