#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"

typedef struct MyChar
{
	LinkNode node;
	char* pAddres;
	int index;
}MyChar;

int IsLeft(char c)
{
	return c=='(';
}

int IsRight(char c)
{
	return c==')';
}

MyChar* CreatMyChar(char* p)
{
	MyChar* mychar=(MyChar*)malloc(sizeof(MyChar));
	mychar->pAddres=p;
	return mychar;
}

void ShowError(char* str,int pos)
{
	int i;
	printf("%s\n",str);
	for(i=0;i<pos;i++)
	{
		prinft(" ");
	}
	prinft("A");
}

int main()
{
	char* str="1+2+6(dsf)dfsflp((sdfs)";
	//创建栈容器
	LinkStack* stack=Init_LinkStack();

	char* p=str;
	int index=0;
	while(*p !='\0')
	{
		//如果左括号直接进栈
		if(IsLeft(* p))
		{
			Push_LinkStack(stack,(LinkNode*)CreatMyChar(p));
		}
		
		//如果右括号 从栈顶弹出元素 判断是不是左括号
		if(IsRight(* p))
		{
			if(Size_LinkStack(stack)>0)
			{
				MyChar* mychar=(MyChar*)Top_LinkStack(stack);
				if(IsLeft(*(mychar->pAddres)))
				{	
					Pop_LinkStack(stack);
				}
			}
			else
			{
				
			}
		}
	}

	system("pause");
	return 0;
}
