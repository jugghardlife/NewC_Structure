#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 20

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time*1000+tb.millitm;
}

//打印函数
void PrintArray(int arr[],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d",arr[i]);
	}
	printf("\n");
}


//交换函数
void Swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

void SelectSort(int arr[],int length)
{
	int i;
	int min;
	for(i=0;i<length;i++)
	{
		min=i
	}

}



int main()
{
	
	system("pause");
	return 0;
}