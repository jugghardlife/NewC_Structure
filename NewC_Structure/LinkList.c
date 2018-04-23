#include "LinkList.h"

//初始化链表
LinkList* Init_LinkList()
{
	LinkList* list=(LinkList*)malloc(sizeof(LinkList));
	list->size=0;

	//头结点 是不保存数据信息
	list->head=(LinkNode*)malloc(sizeof(LinkNode));
	list->head->data=NULL;
	list->head->next=NULL;
	return list;
}
//指定位置插入
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

	//友好处理，pos越界
	if(pos<0 || pos>list->size)
	{
		pos=list->size;
	}
	
	//创建新的结点
	newnode->data=data;
	newnode->next=NULL;
	//找节点
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}

	//新结点入链表
	newnode->next=pCurrent->next;
	pCurrent->next=newnode;

	list->size++;
}
//删除指定位置的值
void RemoveByPos_LinkList(LinkList* list,int pos)
{
	int i;
	LinkNode* pCurrent=list->head;
	LinkNode* pDel;
	if(NULL==list)
	{
		return;
	}
	//查找删除结点前一个结点
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}
	
	//缓存删除的结点
	pDel=pCurrent->next;
	pCurrent->next=pDel->next;
	//释放删除结点的内存
	free(pDel);

	list->size--;
}
//获取链表的长度
int Size_LinkList(LinkList* list)
{
	return list->size;
}
//查找
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

	//遍历查找
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
//返回第一个结点
void* Front_LinkList(LinkList* list)
{
	return list->head->next->data;
}
//打印链表结点
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
//释放链表内存
void FreeSpace_LinkList(LinkList* list)
{
	LinkNode* pCurrent=list->head;
	if(NULL==list)
	{
		return;
	}

	while(pCurrent!=NULL)
	{
		//缓存下一个节点
		LinkNode *pNext=pCurrent->next;
		free(pCurrent);
		pCurrent=pNext;
	}
	//释放链表内存
	list->size=0;
	free(list);
}
