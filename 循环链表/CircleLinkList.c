#include "CircleLinkList.h"

//初始化函数
CircleLinkList* Init_CircleLinKList()
{
	CircleLinkList* clist=(CircleLinkList*)malloc(sizeof(CircleLinkList));
	clist->head.next=&(clist->head);
	clist->size=0;
	return clist;
}
//插入函数
void Insert_CircleLinKList(CircleLinkList* clist,int pos,CircleLinkNode* data)
{
	//辅助指针变量
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

	//根据位置查找结点
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}

	//新数据插入链表
	data->next=pCurrent->next;
	pCurrent->next=data;

	clist->size++;
}
//获取第一个元素
CircleLinkNode* Front_CircleLinkList(CircleLinkList* clist)
{
	return clist->head.next;
}
//根据位置删除
void RemoveByPos_CircleLinkList(CircleLinkList* clist,int pos)
{
	//辅助指针变量
	CircleLinkNode* pCurrent=&(clist->head);
	//缓存当前结点的下一个结点
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
	
	//根据pos找节点
	for(i=0;i<pos;i++)
	{
		pCurrent=pCurrent->next;
	}
	
	
	pCurrent->next=pNext->next;

	clist->size--;
}
//根据值删除
void RemoveByValue_CircleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare)
{
	CircleLinkNode* pPrev=&(clist->head);
	//辅助指针
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

	//这个是循环链表
	for(i=0;i<clist->size;i++)
	{
		if(compare(pCurrent,data)==CIRCLELINKLIST_TRUE)
		{
			//删除
			pPrev->next=pCurrent->next;
			clist->size--;
			break;
		}
		pPrev=pCurrent;
		pCurrent=pPrev->next;
	}
}
//获得链表的长度
int Size_CircleLinkList(CircleLinkList* clist)
{
	return clist->size;
}
//判断是否为空
int IsEmpty_CircleLinkList(CircleLinkList* clist)
{
	if(0==clist->size)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}
//查找
int Find_CircleLinkList(CircleLinkList* clist,CircleLinkNode* data,COMPARENODE compare)
{
	//辅助指针变量
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
//打印结点
void Print_CircleLinkList(CircleLinkList* clist,PRINTNODE print)
{
	//辅助指针变量
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
//释放内存
void FreeSpace_CircleLinkList(CircleLinkList* clist)
{
	if(NULL==clist)
	{
		return ;
	}
	free(clist);
}