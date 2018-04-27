#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

#define M 8
#define N 3

typedef struct MyNum
{
	CircleLinkNode node;
	int val;
}MyNum;

//打印回调
void MyPrint(CircleLinkNode* data)
{
	MyNum* p=(MyNum*)data;
	printf("%d ",p->val);
}
//比较回调
int MyCompare(CircleLinkNode* data1,CircleLinkNode* data2)
{
	MyNum* num1=(MyNum*)data1;
	MyNum* num2=(MyNum*)data2;
	if(num1->val==num2->val)
	{
		return CIRCLELINKLIST_TRUE;
	}
	return CIRCLELINKLIST_FALSE;
}

int main()
{
	int i;
	int index=1;
	MyNum* tempNum;
	MyNum* temNum;
	MyNum num[M];
	CircleLinkNode* pNext;
	//辅助结点
	CircleLinkNode* pCurrent;
	//创建循环链表
	CircleLinkList* clist=Init_CircleLinKList();
	//链表插入数据
	
	for(i=0;i<8;i++)
	{
		num[i].val=i+1;
		Insert_CircleLinKList(clist,i,(CircleLinkNode*)&num[i]);
	}

	////根据值删除
	//RemoveByPos_CircleLinkList(clist,5);

	////打印
	//Print_CircleLinkList(clist,MyPrint);
	pCurrent=clist->head.next;
	while(Size_CircleLinkList(clist)>1)
	{
		if(pCurrent==&(clist->head))
		{
			pCurrent=pCurrent->next;
		}
		if(index==N)
		{
			tempNum=(MyNum*)pCurrent;
			printf("%d ",tempNum->val);

			//缓存待删除结点的下一个结点
			pNext=pCurrent->next;
			//根据值删除
			RemoveByValue_CircleLinkList(clist,pCurrent,MyCompare);
			pCurrent=pNext;
			if(pCurrent==&(clist->head))
			{
				pCurrent=pCurrent->next;
			}
			index=1;
		}
		
		pCurrent=pCurrent->next;
		index++;
	}

	if(1==Size_CircleLinkList(clist))
	{
		temNum=(MyNum*)Front_CircleLinkList(clist);
		printf("%d ",temNum->val);
	}
	else
	{
		printf("出错！");
	}

	//释放链表内存
	FreeSpace_CircleLinkList(clist);

	printf("\n");
	system("pause");
	return 0;
}