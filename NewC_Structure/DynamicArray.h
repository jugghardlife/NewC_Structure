#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//��̬�����ڴ棬���Խ���������ݵ��ڴ����ڶ���
//����capacity��ʾ�ҵ�����ڴ澫���ƶ���Ŷ���Ԫ��
//size���� ��¼��ǰ�����о����Ԫ�ظ���


// ��̬����Ľṹ��
typedef struct DYNAMICARRAY
{
	int* pAddr;
	int size;
	int capacity;
}Dynamic_Array;

//дһϵ�е����DYNAMICARRAY�ṹ������ĺ���
//��ʼ��
Dynamic_Array* Init_Array();
//����
void Push_Back_Array(Dynamic_Array *arr,int value);
//����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array *arr,int pos);
//����ֵɾ��
void RemoveByValue_Array(Dynamic_Array *arr,int value);
//����
int Find_Array(Dynamic_Array *arr,int value);
//��ӡ
void Print_Array(Dynamic_Array *arr);
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array *arr);
//�������
void Clear_Array(Dynamic_Array *arr);
//��ö�̬��������
int Capacity_Array(Dynamic_Array *arr);
//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array *arr);
//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array *arr,int pos);


#endif