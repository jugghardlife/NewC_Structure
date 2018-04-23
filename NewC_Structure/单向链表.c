#define _CRT_SECURE_NO_WARNING
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

//�Զ�����������
typedef struct PERSON
{
	char name[64];
	int age;
	int score;
}Person;

//��ӡ����
void MyPrint(void* data)
{
	Person* p=(Person*)data;
	printf("Name:%s Age:%d Score:%d\n",p->name,p->age,p->score);
}

int main()
{

	Person *ret;

	//����һ������
	LinkList *list=Init_LinkList();

	//��������
	Person p1={"aaa",18,100};
	Person p2={"bbb",17,90};
	Person p3={"ccc",16,80};
	Person p4={"ddd",20,92};
	Person p5={"fff",21,59};
	
	

	//���ݲ�������
	Insert_LinkList(list,0,&p1);
	Insert_LinkList(list,0,&p2);
	Insert_LinkList(list,0,&p3);
	Insert_LinkList(list,0,&p4);
	Insert_LinkList(list,0,&p5);
	
	

	//��ӡ
	Print_LinkList(list,MyPrint);
	
	printf("-------------\n");

	//ɾ��
	RemoveByPos_LinkList(list,3);

	//��ӡ
	Print_LinkList(list,MyPrint);
	
	printf("-------------\n");
	
	//���ص�һ�����
	ret=(Person*)Front_LinkList(list);
	MyPrint(ret);
	//��������
	FreeSpace_LinkList(list);

	system("pause");
	return 0;
}