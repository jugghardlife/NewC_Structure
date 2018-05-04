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
	//��׺���ʽ
	char* str="831-5*+";
	char* p=str;
	int rightNum;
	int leftNum;
	int ret;
	//����ջ����
	LinkStack* stack=Init_LinkStack();

	while(*p!='\0')
	{
		//���������ֱ����ջ
		if(IsNumber(*p))
		{
			MyNum* num=(MyNum*)malloc(sizeof(MyNum));
			num->val=*p-'0';
			Push_LinkStack(stack,(LinkNode *)num);
		}
		else
		{
			//�ȴ�ջ�е����Ҳ�����
			MyNum* num;
			MyNum* left;
			MyNum* right=(MyNum*)Top_LinkStack(stack);
			rightNum=right->val;
			Pop_LinkStack(stack);
			free(right);
			//ȡ���������
			left=(MyNum*)Top_LinkStack(stack);
			leftNum=left->val;
			Pop_LinkStack(stack);
			free(left);
			ret=Caculate(leftNum,rightNum,*p);

			//�����ջ
			num=(MyNum*)malloc(sizeof(MyNum));
			num->val=ret;
			Push_LinkStack(stack,(LinkNode *)num);
		}
		p++;
	}

	if(1==Size_LinkStack(stack))
	{
		MyNum* num=(MyNum*)Top_LinkStack(stack);
		printf("�������ǣ�%d",num->val);
		Pop_LinkStack(stack);
		free(num);
	}
	
	//�ͷ�ջ
	FreeSpace_LinkStack(stack);

	system("pause");
	return 0;
}