#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/timeb.h>

#define MAX 100000

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

//希尔排序
void ShellSort(int arr[],int length)
{
	int increasement=length;
	int i,j,k;
	do
	{
		//确定分量
		increasement=increasement/3+1;
		for(i=0;i<increasement;i++)
		{
			for(j=i+increasement;j<length;j+=increasement)
			{
				if(arr[j]<arr[j-increasement])
				{
					int temp=arr[j];
					for(k=j-increasement;k>=0&&temp<arr[k];k-=increasement)
					{
						arr[k+increasement]=arr[k];
					}
					arr[k+increasement]=temp;
				}
			}
		}
	}
	while(increasement>1);
}


//插入排序
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
	int arr2[MAX];
	int RandNum;
	long tshell_start;
	long tshell_end;
	long ishell_start;
	long ishell_end;
	int i;
	srand((unsigned)time(NULL));
	for(i=0;i<MAX;i++)
	{
		RandNum=rand()%MAX;
		arr[i]=RandNum;
		arr2[i]=RandNum;
	}

	tshell_start=getSystemTime();
	ShellSort(arr,MAX);
	tshell_end=getSystemTime();
	
	printf("希尔排序需要的时间%ld\n",tshell_end-tshell_start);


	ishell_start=getSystemTime();
	InsertSort(arr2,MAX);
	ishell_end=getSystemTime();
	
	printf("插入排序需要的时间%ld\n",ishell_end-ishell_start);

	system("pause");
	return 0;
}