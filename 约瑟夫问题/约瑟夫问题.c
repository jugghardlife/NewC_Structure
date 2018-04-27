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

//��ӡ�ص�
void MyPrint(CircleLinkNode* data)
{
	MyNum* p=(MyNum*)data;
	printf("%d ",p->val);
}
//�Ƚϻص�
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
	//�������
	CircleLinkNode* pCurrent;
	//����ѭ������
	CircleLinkList* clist=Init_CircleLinKList();
	//�����������
	
	for(i=0;i<8;i++)
	{
		num[i].val=i+1;
		Insert_CircleLinKList(clist,i,(CircleLinkNode*)&num[i]);
	}

	////����ֵɾ��
	//RemoveByPos_CircleLinkList(clist,5);

	////��ӡ
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

			//�����ɾ��������һ�����
			pNext=pCurrent->next;
			//����ֵɾ��
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
		printf("����");
	}

	//�ͷ������ڴ�
	FreeSpace_CircleLinkList(clist);

	printf("\n");
	system("pause");
	return 0;
}