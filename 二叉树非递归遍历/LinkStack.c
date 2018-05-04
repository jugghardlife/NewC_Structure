#include "LinkStack.h"

//初始化函数
LinkStack* Init_LinkStack()
{
	LinkStack* stack=(LinkStack*)malloc(sizeof(LinkStack));
	stack->head.next=NULL;
	stack->size=0;
	return stack;
}
//入栈
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
//出栈
void Pop_LinkStack(LinkStack* stack)
{
	/*int i;*/
	// 赋值指针变量
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
//返回栈顶元素
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
//返回栈元素的个数
int Size_LinkStack(LinkStack* stack)
{

	if(NULL==stack)
	{
		return -1;
	}

	return stack->size;
}
//清空栈
void Clear_LinkStack(LinkStack* stack)
{
	if(NULL==stack)
	{
		return ;
	}

	stack->head.next=NULL;
	stack->size=0;
}
//销毁栈
void FreeSpace_LinkStack(LinkStack* stack)
{
	if(NULL==stack)
	{
		return ;
	}

	free(stack);
}