#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

#define MAX 10

//创建数组
int* CreatArray()
{
	srand((unsigned int)time(NULL));
	int* arr=(int*)malloc(sizeof(int)*MAX);
	for(int i=0;i<MAX;i++)
	{
		arr[i]=rand()%MAX;
	}

	return arr;
}

//打印
void PrintArray(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//合并算法 从小到大
void Merge(int arr[],int start,int end,int mid,int* temp)
{
	int i_start=start;
	int i_end=mid;
	int j_start=mid+1;
	int j_end=end;

	//表示辅助空间有多少个元素
	int length=0;

	//合并两个有序序列
	while(i_start<=i_end&&j_start<=j_end)
	{
		if(arr[i_start]<arr[j_start])
		{
			temp[length]=arr[i_start];
			length++;
			i_start++;
		}
		else
		{
			temp[length]=arr[j_start];
			j_start++;
			length++;
		}
	}

	//i这个序列
	while(i_start<=i_end)
	{
		temp[length]=arr[i_start];
		length++;
		i_start++;
	}

	//j这个序列
	while(j_start<=j_end)
	{
		temp[length]=arr[j_start];
		length++;
		j_start++;
	}

	//辅助空间数据覆盖原空间
	for(int i=0;i<length;i++)
	{
		arr[start+i]=temp[i];
	}
}

//归并排序
void MergeSort(int arr[],int start,int end,int* temp)
{
	if(start>=end)
	{
		return ;
	}

	int mid = (start + end) / 2;
	//分组
	MergeSort(arr,start,mid,temp);
	MergeSort(arr,mid+1,end,temp);

	//合并
	Merge(arr,start,end,mid,temp);
}

int main(void)
{
	int* myArr=CreatArray();
	PrintArray(myArr,MAX);
	//辅助空间
	int* temp=(int*)malloc(sizeof(int)*MAX);
	MergeSort(myArr,0,MAX-1,temp);
	
	PrintArray(myArr,MAX);


	//释放空间
	free(temp);
	free(myArr);

	system("pause");
	return 0;
}