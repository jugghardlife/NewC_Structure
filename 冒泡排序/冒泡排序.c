#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 10000
int flag=0;//表示没有排序好

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time*1000+tb.millitm;
}

//交换函数
void Swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//冒泡排序
void BubbleSort(int arr[],int length)
{
	int i;
	int j;
	for(i=0;i<length;i++)
	{
		for(j=length-1;j>i&&flag==0;j--)
		{
			flag=1;
			if(arr[j-1]<arr[j])
			{
				flag=0;
				Swap(&arr[j-1],&arr[j]);
			}
		}
	}
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

int main()
{
	int arr[MAX];
	int i;
	long t_start;
	long t_end;
	srand((unsigned int)time(NULL));

	for(i=0;i<MAX;i++)
	{
		arr[i]=rand()%MAX;
	}

	//PrintArray(arr,MAX);
	

	printf("~~~~~~~~~~~~~~~~~~~~\n");
	
	t_start=getSystemTime();
	BubbleSort(arr,MAX);
	t_end=getSystemTime();

	printf("冒泡排序的时间：%ld\n",t_end-t_start);
	//PrintArray(arr,MAX);

	system("pause");
	return 0;
}