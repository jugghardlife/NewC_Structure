#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//动态增长内存，策略将存放在数据的内存存放在堆上
//容量capacity表示我的这块内存精简移动存放多少元素
//size概念 记录当前数组中具体的元素个数


// 动态数组的结构体
typedef struct DYNAMICARRAY
{
	int* pAddr;
	int size;
	int capacity;
}Dynamic_Array;

//写一系列的相关DYNAMICARRAY结构体操作的函数
//初始化
Dynamic_Array* Init_Array();
//插入
void Push_Back_Array(Dynamic_Array *arr,int value);
//根据位置删除
void RemoveByPos_Array(Dynamic_Array *arr,int pos);
//根据值删除
void RemoveByValue_Array(Dynamic_Array *arr,int value);
//查找
int Find_Array(Dynamic_Array *arr,int value);
//打印
void Print_Array(Dynamic_Array *arr);
//释放动态数组的内存
void FreeSpace_Array(Dynamic_Array *arr);
//清空数组
void Clear_Array(Dynamic_Array *arr);
//获得动态数组容量
int Capacity_Array(Dynamic_Array *arr);
//获得动态数组当前元素个数
int Size_Array(Dynamic_Array *arr);
//根据位置获得某个位置元素
int At_Array(Dynamic_Array *arr,int pos);


#endif