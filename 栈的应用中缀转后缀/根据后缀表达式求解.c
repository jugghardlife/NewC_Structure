#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MYNUM
{
	LinkNode node;
	int val;
}MyNum;

int IsNumber(char c)
{
	return c>='0'&&c<='9';
}

int Caculate(int left,int right,char c)
{
	int ret=0;
	switch(c)
	{
	default:
		break;
	}
}

int main()
{
	//后缀表达式
	char* str="831-5*+";
	char* p=str;
	int rightNum;
	int leftNum;
	//创建栈容器
	LinkStack* stack=Init_LinkStack();

	while(*p!='\0')
	{
		//如果是数字直接入栈
		if(IsNumber(*p))
		{
			MyNum* num=(MyNum*)malloc(sizeof(MyNum));
			num->val=*p-'0';
			Push_LinkStack(stack,num);
		}
		else
		{
			//先从栈中弹出右操作数
			rightNum=((MyNum*)Top_LinkStack(stack))->val;
			Pop_LinkStack(stack);
			//取出左操作数
			leftNum=((MyNum*)Top_LinkStack(stack))->val;
			Pop_LinkStack(stack);
		}
		p++
	}

	system("pause");
	return 0;
}