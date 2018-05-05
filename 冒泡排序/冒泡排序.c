#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 10000
int flag=0;//��ʾû�������

long getSystemTime()
{
	struct timeb tb;
	ftime(&tb);
	return tb.time*1000+tb.millitm;
}

//��������
void Swap(int* a,int* b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}

//ð������
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

//��ӡ����
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

	printf("ð�������ʱ�䣺%ld\n",t_end-t_start);
	//PrintArray(arr,MAX);

	system("pause");
	return 0;
}