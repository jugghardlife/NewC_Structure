//#define _CRT_SECURE_NO_WARNINGS
//#include <stdlib.h>
//#include <stdio.h>
//#include <string.h>
//
//#include "DynamicArray.h"
//
//
//void test01()
//{
//	
//	//��ʼ����̬����
//	Dynamic_Array* myArray=Init_Array();
//	int i;
//	int pos;
//	//��ӡ����
//	printf("����������%d\n",Capacity_Array(myArray));
//	//��ӡ����
//	printf("�����С��%d\n",Size_Array(myArray));
//	//����Ԫ��
//	for(i=0;i<30;i++)
//	{
//		Push_Back_Array(myArray,i);
//	}
//	//��ӡ����
//	printf("����������%d\n",Capacity_Array(myArray));
//	//��ӡ����
//	printf("�����С��%d\n",Size_Array(myArray));
//	//��ӡ
//	Print_Array(myArray);
//	//ɾ��
//	RemoveByPos_Array(myArray,0);
//	//ɾ��
//	RemoveByValue_Array(myArray,27);
//	//��ӡ
//	Print_Array(myArray);
//	//����
//	pos=Find_Array(myArray,5);
//	printf("5���ҵ�pos:%d %d\n",pos,At_Array(myArray,pos));
//	//����
//	FreeSpace_Array(myArray);
//}
//
//int main(void)
//{
//	test01();
//	system("pause");
//	return 0;
//}