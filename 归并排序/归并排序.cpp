#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <sys/timeb.h>

using namespace std;

#define MAX 10

//��������
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

//��ӡ
void PrintArray(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

//�ϲ��㷨 ��С����
void Merge(int arr[],int start,int end,int mid,int* temp)
{
	int i_start=start;
	int i_end=mid;
	int j_start=mid+1;
	int j_end=end;

	//��ʾ�����ռ��ж��ٸ�Ԫ��
	int length=0;

	//�ϲ�������������
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

	//i�������
	while(i_start<=i_end)
	{
		temp[length]=arr[i_start];
		length++;
		i_start++;
	}

	//j�������
	while(j_start<=j_end)
	{
		temp[length]=arr[j_start];
		length++;
		j_start++;
	}

	//�����ռ����ݸ���ԭ�ռ�
	for(int i=0;i<length;i++)
	{
		arr[start+i]=temp[i];
	}
}

//�鲢����
void MergeSort(int arr[],int start,int end,int* temp)
{
	if(start>=end)
	{
		return ;
	}

	int mid = (start + end) / 2;
	//����
	MergeSort(arr,start,mid,temp);
	MergeSort(arr,mid+1,end,temp);

	//�ϲ�
	Merge(arr,start,end,mid,temp);
}

int main(void)
{
	int* myArr=CreatArray();
	PrintArray(myArr,MAX);
	//�����ռ�
	int* temp=(int*)malloc(sizeof(int)*MAX);
	MergeSort(myArr,0,MAX-1,temp);
	
	PrintArray(myArr,MAX);


	//�ͷſռ�
	free(temp);
	free(myArr);

	system("pause");
	return 0;
}