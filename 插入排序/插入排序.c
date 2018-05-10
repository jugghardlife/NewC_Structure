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

//´òÓ¡º¯Êý
void PrintArray(int arr[],int length)
{
	int i;
	for(i=0;i<length;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
}

//²åÈëÅÅÐò
void InsertSort(int arr[],int length)
{
	int j;
	int i;
	for(i=1;i<length;i++)
	{
		if(arr[i]<arr[i-1])
		{
			int temp=arr[i];
			for(j=i-1;j>=0&&temp<arr[j];j--)
			{
				arr[j+1]=arr[j];
			}
			arr[j+1]=temp;
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

	InsertSort(arr,MAX);

	PrintArray(arr,MAX);

	system("pause");
	return 0;
}