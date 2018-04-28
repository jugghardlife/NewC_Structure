#include "SeqQueue.h"

//初始化
SeqQueue* Init_SeqQueue()
{
	int i;
	SeqQueue* queue=(SeqQueue*)malloc(sizeof(SeqQueue));
	for(i=0;i<MAX_SIZE;i++)
	{
		queue->data[i]=NULL;
	}
	queue->size=0;
	return queue;
}
//入队
void Push_SeqQueue(SeqQueue* queue,void* data)
{
	if(NULL==queue)
	{
		return ;
	}

	if(NULL==data)
	{
		return ;
	}

	if(queue->size==MAX_SIZE)
	{
		return ;
	}

	//数组左边当做队头
	queue->data[queue->size]=data;
	queue->size++;
}	
//返回队头元素
void* Front_SeqQueue(SeqQueue* queue)
{
	if(NULL==queue)
	{
		return NULL;
	}

	if(0==queue->size)
	{
		return NULL;
	}
	return queue->data[0];
}
//出队
void Pop_SeqQueue(SeqQueue* queue)
{
	int i;
	if(NULL==queue)
	{
		return ;
	}

	if(0==queue->size)
	{
		return ;
	}
	
	for(i=0;i<queue->size-1;i++)
	{
		queue->data[i]=queue->data[i+1];
	}
	queue->size--;
}
//返回队尾的元素
void* Back_SeqQueue(SeqQueue* queue)
{
	if(NULL==queue)
	{
		return NULL;
	}

	if(0==queue->size)
	{
		return NULL;
	}

	return queue->data[queue->size-1];
}
//返回大小
int Size_SeqQueue(SeqQueue* queue)
{
	if(NULL==queue)
	{
		return -1;
	}

	return queue->size;
}
//清空队列
void Clear_SeqQueue(SeqQueue* queue)
{
	if(NULL==queue)
	{
		return ;
	}

	queue->size=0;
}
//销毁
void FreeSpace_SeqQueue(SeqQueue* queue)
{

	if(NULL==queue)
	{
		return ;
	}

	free(queue);
}