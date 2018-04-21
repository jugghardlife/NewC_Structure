#include "DynamicArray.h"

//动态数组的初始化
Dynamic_Array* Init_Array()
{	
	//申请内存
	Dynamic_Array* myArray=(Dynamic_Array*)malloc(sizeof(Dynamic_Array));
	//初始化
	myArray->size=0;
	myArray->capacity=20;
	myArray->pAddr=(int*)malloc(sizeof(int)*myArray->capacity);
	
	return myArray;
}
//插入
void Push_Back_Array(Dynamic_Array *arr,int value)
{
	if(NULL==arr)
	{
		return;
	}

	//判断空间是否足够
	if(arr->size==arr->capacity)
	{
		//第一步申请一个更大的内存空间，新空间是就空间的2倍
		int *newSpace=(int*)malloc(sizeof(int)*arr->capacity*2);
		//第二步拷贝数据到新的空间
		memcy(newSpace,arr->pAddr,arr->capacity*sizeof(int));
		//第三步释放旧空间的内存
		free(arr->pAddr);
		//更新容量
		arr->capacity=arr->capacity*2;
		arr->pAddr=newSpace;
	}
	//插入新元素
	arr->pAddr[arr->size]=value;
	arr->size++;
}
//根据位置删除
void RemoveByPos_Array(Dynamic_Array *arr,int pos)
{

}
//根据值删除
void RemoveByValue_Array(Dynamic_Array *arr,int value)
{

}
//查找
int Find_Array(Dynamic_Array *arr,int value)
{
	return 0;
}
//打印
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
//释放动态数组的内存
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
//清空数组
void Clear_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}

	arr->size=0;
}
//获得动态数组容量
int Capacity_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}
	
	return arr->capacity;
}
//获得动态数组当前元素个数
int Size_Array(Dynamic_Array *arr)
{
	if(NULL==arr)
	{
		return;
	}

	return arr->size;
}
//根据位置获得某个位置元素
int At_Array(Dynamic_Array *arr,int pos)
{
	if(NULL==arr)
	{
		return;
	}
	return arr->pAddr[pos];
}