#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdlib.h>
#include <stdio.h>

//����ڵ�
typedef struct LINKNODE
{
	void* data;    //ָ���κ����͵�����
	struct LINKNODE* next;
}LinkNode;

//����ṹ��
typedef struct LINKLIST
{
	LinkNode* head;
	int size;
}LinkList;

//��ӡ����ָ��
typedef void(*PRINTLINKNODE)(void*);
//��ʼ������
LinkList* Init_LinkList();
//ָ��λ�ò���
void Insert_LinkList(LinkList* list,int pos,void *data);
//ɾ��ָ��λ�õ�ֵ
void RemoveByPos_LinkList(LinkList* list,int pos);
//��ȡ����ĳ���
int Size_LinkList(LinkList* list);
//����
int Find_LinkList(LinkList* list,void* data);
//���ص�һ�����
void* Front_LinkList(LinkList* list);
//��ӡ������
void Print_LinkList(LinkList* list,PRINTLINKNODE print);
//�ͷ������ڴ�
void FreeSpace_LinkList(LinkList* list);


#endif