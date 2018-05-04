#include "LinkStack.h"

//��ʼ������
LinkStack* Init_LinkStack()
{
	LinkStack* stack=(LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next=NULL;
	stack->size=0;
	return stack;
}
//��ջ
void Push_LinkStack(LinkStack* stack,LinkNode* data)
{
	if(NULL==stack)
	{
		return ;
	}

	if(NULL==data)
	{
		return ;
	}
	
	data->next=stack->head.next;
	stack->head.next=data;
	stack->size++;

}
//��ջ
void Pop_LinkStack(LinkStack* stack)
{
	/*int i;*/
	// ��ֵָ�����
	//LinkNode* pCurrent=stack->head.next;
	//LinkNode* PopCurrent;
	if(NULL== stack)
	{
		return ;
	}

	if(0==stack->size)
	{
		return ;
	}

	stack->head.next=stack->head.next->next;
	//pCurrent->next=NULL;
	stack->size--;
}	
//����ջ��Ԫ��
LinkNode* Top_LinkStack(LinkStack* stack)
{
	if(NULL==stack)
	{
		return NULL;
	}
	if(0==stack->size)
	{
		return NULL;
	}

	return stack->head.next;
}
//����ջԪ�صĸ���
int Size_LinkStack(LinkStack* stack)
{

	if(NULL==stack)
	{
		return -1;
	}

	return stack->size;
}
//���ջ
void Clear_LinkStack(LinkStack* stack)
{
	if(NULL==stack)
	{
		return ;
	}

	stack->head.next=NULL;
	stack->size=0;
}
//����ջ
void FreeSpace_LinkStack(LinkStack* stack)
{
	if(NULL==stack)
	{
		return ;
	}

	free(stack);
}