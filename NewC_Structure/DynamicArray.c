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
		memcpy(newSpace,arr->pAddr,arr->capacity*sizeof(int));
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
	int i;
	if(NULL==arr)
	{
		return;
	}
	if(pos<0||pos>=arr->size)
	{
		return;
	}
	
	for(i=pos;i<arr->size-1;i++)
	{
		arr->pAddr[i]=arr->pAddr[i+1];
	}
	arr->size--;
}
//����ֵɾ��
void RemoveByValue_Array(Dynamic_Array *arr,int value)
{	
	int pos=Find_Array(arr,value);

	RemoveByPos_Array(arr,pos);
}
//����
int Find_Array(Dynamic_Array *arr,int value)
{
	int pos=-1,i;
	if(NULL==arr)
	{
		return -1;
	}

	//�ҵ�ֵ��λ��
	for(i=0;i<arr->size;i++)
	{
		if(arr->pAddr[i]==value)
		{
			pos=i;
			break;
		}
	}

	return pos;
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
		printf("%d ",arr->pAddr[i]);
	}
	printf("\n");
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
		return -1;
	}
	
	return arr->capacity;
}
//��ö�̬���鵱ǰԪ�ظ���
int Size_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return -1;
	}

	return arr->size;
}
//����λ�û��ĳ��λ��Ԫ��
int At_Array(Dynamic_Array *arr,int pos)
{
	return arr->pAddr[pos];
}