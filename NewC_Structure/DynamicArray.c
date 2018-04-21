#include "DynamicArray.h"

//��̬����ĳ�ʼ��
Dynamic_Array* Init_Array()
{	
	//�����ڴ�
	Dynamic_Array* myArray=(Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	//��ʼ��
	myArray->size=0;
	myArray->capacity=20;
	myArray->pAddr=(int*)malloc(sizeof(int)*myArray->capacity);
	
	return myArray;
}
//����
void Push_Back_Array(Dynamic_Array *arr,int value)
{
	if(NULL==arr)
	{
		return;
	}

	//�жϿռ��Ƿ��㹻
	if(arr->size==arr->capacity)
	{
		//��һ������һ��������ڴ�ռ䣬�¿ռ��ǾͿռ��2��
		int *newSpace=(int*)malloc(sizeof(int)*arr->capacity*2);
		//�ڶ����������ݵ��µĿռ�
		memcy(newSpace,arr->pAddr,arr->capacity*sizeof(int));
		//�������ͷžɿռ���ڴ�
		free(arr->pAddr);
		//��������
		arr->capacity=arr->capacity*2;
		arr->pAddr=newSpace;
	}
	//������Ԫ��
	arr->pAddr[arr->size]=value;
	arr->size++;
}
//����λ��ɾ��
void RemoveByPos_Array(Dynamic_Array *arr,int pos)
{

}
//����ֵɾ��
void RemoveByValue_Array(Dynamic_Array *arr,int value)
{

}
//����
int Find_Array(Dynamic_Array *arr,int value)
{
	return 0;
}
//��ӡ
void Print_Array(Dynamic_Array *arr)
{
	int i;
	if(NULL==arr)
	{
		return;
	}
	for(i=0;i<arr->size;i++)
	{
		printf("%d",arr->pAddr[i]);
	}
}
//�ͷŶ�̬������ڴ�
void FreeSpace_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}
	if(arr->pAddr!=NULL)
	{
		free(arr->pAddr);
	}
	free(arr);
}
//�������
void Clear_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}

	arr->size=0;
}
//��ö�̬��������
int Capacity_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}
	
	return arr->capacity;
}
//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}

	return arr->size;
}
//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array *arr,int pos)
{
	if(NULL==arr)
	{
		return;
	}
	return arr->pAddr[pos];
}