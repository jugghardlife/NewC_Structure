#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircleLinkList.h"

typedef struct PERSON
{
	CircleLinkNode node;
	char name[64];
	int age;
	int score;
}Person;

//打印回调
void MyPrint(CircleLinkNode* data)
{
	Person* p=(Person*)data;
	printf("Name:%s Age:%d Score:%d\n",p->name,p->age,p->score);
}

//比较回调
int MyCompare(CircleLinkNode* node1,CircleLinkNode* node2)
{
	Person* p1=(Person*)node1;
	Person* p2=(Person*)node2;

	if(strcmp(p1->name,p2->name)==0&&p1->age==p2->age&&p1->score==p2->score)
	{
		return CIRCLELINKLIST_TRUE;
	}

	return CIRCLELINKLIST_FALSE;
}

int main()
{	
	//创建循环链表
	CircleLinkList* clist=Init_CircleLinKList();
	
	Person pDel;
	//创建数据
	Person p1,p2,p3,p4,p5;
	strcpy(p1.name,"aaa");
	strcpy(p2.name,"bbb");
	strcpy(p3.name,"ccc");
	strcpy(p4.name,"ddd");
	strcpy(p5.name,"eee");
	
	p1.age=18;
	p2.age=17;
	p3.age=16;
	p4.age=19;
	p5.age=20;

	p1.score=100;
	p2.score=99;
	p3.score=22;
	p4.score=59;
	p5.score=61;

	//数据入链表
	Insert_CircleLinKList(clist,0,(CircleLinkNode*)&p1);
	Insert_CircleLinKList(clist,0,(CircleLinkNode*)&p2);
	Insert_CircleLinKList(clist,0,(CircleLinkNode*)&p3);
	Insert_CircleLinKList(clist,0,(CircleLinkNode*)&p4);
	Insert_CircleLinKList(clist,0,(CircleLinkNode*)&p5);

	//打印
	Print_CircleLinkList(clist,MyPrint);
	
	printf("--------------\n");
	
	//删除数据
	
	strcpy(pDel.name,"aaa");
	pDel.age=18;
	pDel.score=100;

	//根据值删除
	RemoveByValue_CircleLinkList(clist,(CircleLinkNode*)&pDel,MyCompare);
	//根据值删除
	RemoveByPos_CircleLinkList(clist,1);
	//打印
	Print_CircleLinkList(clist,MyPrint);

	//释放内存
	FreeSpace_CircleLinkList(clist);
	
	system("pause");
	return 0;
}