#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//¶þ²æÊ÷½áµã
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

void Recursion(BinaryNode* root)
{
	if(NULL==root)
	{
		return ;
	}

	printf("%c",root->ch);
	Recursion(root->lchild);
	Recursion(root->rchild);
}

BinaryNode* CreateBinaryTree()
{
	char ch;
	BinaryNode* node;
	fflush(stdin);
	scanf("%c",&ch);

	
	if('#'==ch)
	{
		node=NULL;
	}
	else
	{
		node=(BinaryNode*)malloc(sizeof(BinaryNode));
		node->ch=ch;
		node->lchild=CreateBinaryTree();
		node->rchild=CreateBinaryTree();
	}

	return node;
}

int main()
{

	BinaryNode* root=CreateBinaryTree();
	Recursion(root);
	system("pause");
	return 0;
}