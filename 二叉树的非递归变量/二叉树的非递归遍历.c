#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "LinkStack.h"

//#define MY_FALSE 0
//#define MY_TRUE 1

//���������
//typedef struct BINARYNODE
//{
//	char ch;
//	struct BINARYNODE* lchild;
//	struct BINARYNODE* rchild;
//}BinaryNode;

//�������ķǵݹ����
//typedef struct BYTREESTACKNODE
//{
//	LinkNode node;
//	BinaryNode* root;
//	int flag;
//}ByTreeStackNode;

//����ջ�еĽڵ�
//ByTreeStackNode* CreateByTreeStackNode(BinaryNode* node,int flag)
//{
//	ByTreeStackNode* newnode=(ByTreeStackNode*)malloc(sizeof(ByTreeStackNode));
//	newnode->root=node;
//	newnode->flag=flag;
//	return newnode;
//}

//�ǵݹ����
//void NonRecursion(BinaryNode* root)
//{
//	ByTreeStackNode* tree;
//
//	//����ջ
//	LinkStack* stack=Init_LinkStack();
//	//�Ѹ�����ӵ�ջ��
//	Push_LinkStack(stack,(LinkNode *)CreateByTreeStackNode(root,MY_FALSE));
//	while(Size_LinkStack(stack))
//	{
//		tree=(ByTreeStackNode*)Top_LinkStack(stack);
//		if(tree->flag)
//		{
//			printf("%c",tree->root->ch);
//			Pop_LinkStack(stack);
//		}
//		else
//		{
//			Push_LinkStack(stack,(LinkNode *)CreateByTreeStackNode(tree->root->rchild,MY_FALSE));
//			Push_LinkStack(stack,(LinkNode *)CreateByTreeStackNode(tree->root->lchild,MY_FALSE));
//			Push_LinkStack(stack,(LinkNode *)CreateByTreeStackNode(root,MY_TRUE));
//		}
//	}
//}
//

//void GresteBinaryTree()
//{
//	BinaryNode* root;
//	//�������
//	BinaryNode node1={'A',NULL,NULL};
//	BinaryNode node2={'B',NULL,NULL};
//	BinaryNode node3={'C',NULL,NULL};
//	BinaryNode node4={'D',NULL,NULL};
//	BinaryNode node5={'E',NULL,NULL};
//	BinaryNode node6={'F',NULL,NULL};
//	BinaryNode node7={'G',NULL,NULL};
//	BinaryNode node8={'H',NULL,NULL};
//	
//	//��������ϵ
//
//	node1.lchild=&node2;
//	node1.rchild=&node6;
//	node2.rchild=&node3;
//	node3.lchild=&node4;
//	node3.rchild=&node5;
//	node6.rchild=&node7;
//	node7.lchild=&node8;
//
//}
//

int main()
{

	
	system("pause");
	return 0;
}