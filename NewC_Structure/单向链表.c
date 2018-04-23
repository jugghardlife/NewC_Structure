#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

//自定义数据类型
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

//打印函数
void MyPrint(void* data)
{
	Person* p=(Person*)data;
	printf("Name:%s Age:%d Score:%d\n",p->name,p->age,p->score);
}

int main()
{

	Person *ret;

	//创建一个链表
	LinkList *list=Init_LinkList();

	//创建数据
	Person p1={"aaa",18,100};
	Person p2={"bbb",17,90};
	Person p3={"ccc",16,80};
	Person p4={"ddd",20,92};
	Person p5={"fff",21,59};
	
	

	//数据插入链表
	Insert_LinkList(list,0,&p1);
	Insert_LinkList(list,0,&p2);
	Insert_LinkList(list,0,&p3);
	Insert_LinkList(list,0,&p4);
	Insert_LinkList(list,0,&p5);
	
	

	//打印
	Print_LinkList(list,MyPrint);
	
	printf("-------------\n");

	//删除
	RemoveByPos_LinkList(list,3);

	//打印
	Print_LinkList(list,MyPrint);
	
	printf("-------------\n");
	
	//返回第一个结点
	ret=(Person*)Front_LinkList(list);
	MyPrint(ret);
	//销毁链表
	FreeSpace_LinkList(list);

	system("pause");
	return 0;
}