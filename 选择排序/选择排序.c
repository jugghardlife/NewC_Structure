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
		printf("%d ",arr[i]);
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
	int j;
	int min;
	//选择排序减少了交换次数
	for(i=0;i<length;i++)
	{
		min=i;
		for(j=i+1;j<length;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}

		if(min!=i)
		{
			Swap(&arr[min],&arr[i]);
		}
	}

}



int main()
{
	int arr[MAX];
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<MAX;i++)
	{
		arr[i]=rand()%MAX;
	}

	SelectSort(arr,MAX);

	PrintArray(arr,MAX);

	system("pause");
	return 0;
}