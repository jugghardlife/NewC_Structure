#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

void PrintArray(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

void MySwap(int arr[],int a,int b)
{
	int temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
}

/*
	@param arr ������������
	@param index		�������Ľ���±�
	@param len       ����ĳ���	
*/

void HeapAdjust(int arr[],int index,int len)
{
	//�ȱ��浱ǰ�����±�
	int max=index;
	//�������Һ��ӵ������±�
	int lchild=index*2+1;
	int rchild=index*2+2;
	if(lchild<len&&arr[lchild]>arr[max])
	{
		max=lchild;
	}

	if(rchild<len&&arr[rchild]>arr[max])
	{
		max=rchild;
	}

	if(max!=index)
	{
		//�����������
		MySwap(arr,max,index);
		HeapAdjust(arr,max,len);
	}
}

//������
void HeadSort(int myArr[],int len)
{
	//��ʼ����
	for(int i=len/2-1;i>=0;i--)
	{
		HeapAdjust(myArr,i,len);
	}

	//�����Ѷ�Ԫ�غ����һ��Ԫ��
	for(int i=len-1;i>=0;i--)
	{
		MySwap(myArr,0,i);
		HeapAdjust(myArr,0,i);
	}
}


int main(void)
{
	int myArr[]={4,2,8,0,5,7,1,3,9};
	int len=sizeof(myArr)/sizeof(int);
	PrintArray(myArr,len);
	//������
	HeadSort(myArr,len);

	PrintArray(myArr,len);
	system("pause");
	return 0;
}