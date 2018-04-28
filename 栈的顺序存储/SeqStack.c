#include "SeqStack.h"

//��ʼ��ջ
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
//��ջ
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
//����ջ��Ԫ��
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
//��ջ
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
//�ж��Ƿ�Ϊ��
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
//����ջ��Ԫ�صĸ���
int Size_SeqStack(SeqStack* stack)
{
	return stack->size;
}
//���ջ
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
//����
void FreeSpace_SeqStack(SeqStack* stack)
{

	if(NULL==stack)
	{
		return ;
	}

	free(stack);
}