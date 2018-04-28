#include "SeqStack.h"

//初始化栈
SeqStack* Init_SeqStack()
{
	int i;
	SeqStack* stack=(SeqStack*)malloc(sizeof(SeqStack));
	for(i=0;i<MAX_SIZE;i++)
	{
		stack->data[i]=NULL;
	}
	stack->size=0;
	return stack;
}
//入栈
void Push_SeqStack(SeqStack* stack,void* data)
{
	if(NULL==stack)
	{
		return ;
	}
	
	if(NULL==data)
	{
		return ;
	}

	if(stack->size==MAX_SIZE)
	{
		return ;
	}
	
	stack->data[stack->size]=data;
	stack->size++;
}
//返回栈顶元素
void* Top_SeqStack(SeqStack* stack)
{
	if(NULL==stack)
	{
		return NULL;
	}
	
	if(0==stack->size)
	{
		return NULL;
	}

	return stack->data[stack->size-1];
}
//出栈
void Pop_SeqStack(SeqStack* stack)
{
	if(NULL==stack)
	{
		return ;
	}

	if(stack->size==0)
	{
		return ;
	}

	stack->data[stack->size-1]=NULL;
	stack->size--;
}
//判断是否为空
int IsEmpty(SeqStack* stack)
{
	if(NULL==stack)
	{
		return -1;
	}

	if(0==stack->size)
	{
		return SEQSTACK_TRUE;
	}

	return SEQSTACK_FALSE;
}
//返回栈中元素的个数
int Size_SeqStack(SeqStack* stack)
{
	return stack->size;
}
//清空栈
void Clear_SeqStack(SeqStack* stack)
{
	int i;
	if(NULL==stack)
	{
		return ;
	}
	
	for(i=0;i<MAX_SIZE;i++)
	{
		stack->data[i]=NULL;
	}

	stack->size=0;
}
//销毁
void FreeSpace_SeqStack(SeqStack* stack)
{

	if(NULL==stack)
	{
		return ;
	}

	free(stack);
}