//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_DEPRECATE
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "LinkStack.h"
//
//typedef struct MYCHAR
//{
//	LinkNode node;
//	char* p;
//}MyChar;
//
////�ж��Ƿ�����
//int IsNumber(char c)
//{
//	return c>='0'&&c<='9';
//}
//
////�ж��ǲ���������
//int IsLeft(char c)
//{
//	return c=='(';
//}
//
////�ж��ǲ���������
//int IsRight(char c)
//{
//	return c==')';
//}
//
////�ж��ǲ����������
//int IsOperator(char c)
//{
//	return c=='+'||c=='-'||c=='*'||c=='/';
//}
//
////��������������ȼ�
//int GetPriorty(char c)
//{
//	if('*'==c||'/'==c)
//	{
//		return 2;
//	}
//
//	if('+'==c||'-'==c)
//	{
//		return 1;
//	}
//
//	return 0;
//}
//
////�����ִӲ���
//void NumberOperate(char* p)
//{
//	printf("%c", *p);
//}
//
////����MyChar
//MyChar* CreateMyChar(char*p)
//{
//	MyChar* mychar=(MyChar*)malloc(sizeof(MyChar));
//	mychar->p=p;
//	return mychar;
//}
//
////�����ŵĲ���
//void LeftOperator(LinkStack* stack,char* p)
//{
//	Push_LinkStack(stack,(LinkNode*)CreateMyChar(p));
//}
//
////�����Ų���
//void RightOperate(LinkStack* stack)
//{
//	//���ж�ջ����û��Ԫ��
//	while(Size_LinkStack(stack)>0)
//	{
//		MyChar* mychar=(MyChar*)Top_LinkStack(stack);
//		//���ƥ�䵽������
//		if(IsLeft(*(mychar->p)))
//		{
//			Pop_LinkStack(stack);
//			break;
//		}
//		//���
//		printf("%c",*(mychar->p));
//		//����
//		Pop_LinkStack(stack);
//		//�ͷ��ڴ�
//		free(mychar);
//	}
//}
//
////������ŵĲ���
//void OperatorOperate(LinkStack* stack,char* p)
//{
//	//��ȡ��ջ������
//	MyChar* mychar=(MyChar*)Top_LinkStack(stack);
//	if(!Size_LinkStack(stack))
//	{
//		Push_LinkStack(stack,(LinkNode*)CreateMyChar(p));
//		return ;
//	}
//	//���ջ�����ȼ����ڵ�ǰ�ַ������ȼ�  ֱ����ջ
//	if(GetPriorty(*(mychar->p))<GetPriorty(*p))
//	{
//		Push_LinkStack(stack,(LinkNode*)CreateMyChar(p));
//		return ;
//	}
//	//���ջ���������ȼ�����
//	else
//	{
//		while(Size_LinkStack(stack)>0)
//		{
//			MyChar* mychar2=(MyChar*)Top_LinkStack(stack);
//
//			//������ȼ��� ��ǰ������ջ
//			if(GetPriorty(*(mychar2->p))<GetPriorty(*p))
//			{
//				Push_LinkStack(stack,(LinkNode*)CreateMyChar(p));
//				break ;
//			}
//
//			//���
//			printf("%c",*(mychar2->p));
//			//����
//			Pop_LinkStack(stack);
//			//�ͷ�
//			free(mychar2);
//		}
//	}
//}
//
//int main()
//{
//	char* str="(8+(3-1))*5";
//	char* p=str;
//
//	//����ջ����
//	LinkStack* stack=Init_LinkStack();
//	
//	while(*p!='\0')
//	{
//
//		//���������
//		if(IsNumber(*p))
//		{
//			NumberOperate(p);
//		}
//		
//		//��������ţ�ֱ�ӽ�ջ
//		if(IsLeft(*p))
//		{	
//			LeftOperator(stack,p);
//		}
//
//		//�����������
//		if(IsRight(*p))
//		{
//			RightOperate(stack);
//		}
//
//		//������������
//		if(IsOperator(*p))
//		{
//			OperatorOperate(stack,p);
//		}
//		p++;
//	}
//
//	
//	while(Size_LinkStack(stack)>0)
//	{
//		MyChar* mychar=(MyChar*)Top_LinkStack(stack);
//		printf("%c",*(mychar->p));
//		//����
//		Pop_LinkStack(stack);
//		//�ͷ��ڴ�
//		free(mychar);	
//	}
//
//	system("pause");
//	return 0;
//}