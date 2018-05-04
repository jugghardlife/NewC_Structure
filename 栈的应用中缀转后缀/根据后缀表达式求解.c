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
	case '+':
		ret=left+right;
		break;
	case '-':
		ret=left-right;
		break;
	case '*':
		ret=left*right;
		break;
	case '/':
		if(0==right)
		{
			return -1;
		}
		ret=left/right;
		break;
	default:
		break;
	}

	return ret;
}

int main()
{
	//后缀表达式
	char* str="831-5*+";
	char* p=str;
	int rightNum;
	int leftNum;
	int ret;
	//创建栈容器
	LinkStack* stack=Init_LinkStack();

	while(*p!='\0')
	{
		//如果是数字直接入栈
		if(IsNumber(*p))
		{
			MyNum* num=(MyNum*)malloc(sizeof(MyNum));
			num->val=*p-'0';
			Push_LinkStack(stack,(LinkNode *)num);
		}
		else
		{
			//先从栈中弹出右操作数
			MyNum* num;
			MyNum* left;
			MyNum* right=(MyNum*)Top_LinkStack(stack);
			rightNum=right->val;
			Pop_LinkStack(stack);
			free(right);
			//取出左操作数
			left=(MyNum*)Top_LinkStack(stack);
			leftNum=left->val;
			Pop_LinkStack(stack);
			free(left);
			ret=Caculate(leftNum,rightNum,*p);

			//结果入栈
			num=(MyNum*)malloc(sizeof(MyNum));
			num->val=ret;
			Push_LinkStack(stack,(LinkNode *)num);
		}
		p++;
	}

	if(1==Size_LinkStack(stack))
	{
		MyNum* num=(MyNum*)Top_LinkStack(stack);
		printf("运算结果是：%d",num->val);
		Pop_LinkStack(stack);
		free(num);
	}
	
	//释放栈
	FreeSpace_LinkStack(stack);

	system("pause");
	return 0;
}