#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//二叉树结点
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

//遍历二叉树
void Recoursion(BinaryNode* root)
{
	if(NULL==root)
	{
		return ;
	}

	printf("%c",root->ch);
	//遍历左子树
	Recoursion(root->lchild);
	//遍历右子树
	Recoursion(root->rchild);
}

//拷贝二叉树
BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	BinaryNode* newnode;
	BinaryNode* lchild;
	BinaryNode* rchild;
	if(NULL==root)
	{
		return NULL;
	}
	//拷贝左子树
	lchild=CopyBinaryTree(root->lchild);
	//拷贝右子树
	rchild=CopyBinaryTree(root->rchild);

	//创建结点
	newnode= (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch=root->ch;
	newnode->lchild=lchild;
	newnode->rchild=rchild;

	return newnode;
}

void GresteBinaryTree()
{
	BinaryNode* root;
	//创建结点
	BinaryNode node1={'A',NULL,NULL};
	BinaryNode node2={'B',NULL,NULL};
	BinaryNode node3={'C',NULL,NULL};
	BinaryNode node4={'D',NULL,NULL};
	BinaryNode node5={'E',NULL,NULL};
	BinaryNode node6={'F',NULL,NULL};
	BinaryNode node7={'G',NULL,NULL};
	BinaryNode node8={'H',NULL,NULL};
	
	//建立结点关系

	node1.lchild=&node2;
	node1.rchild=&node6;
	node2.rchild=&node3;
	node3.lchild=&node4;
	node3.rchild=&node5;
	node6.rchild=&node7;
	node7.lchild=&node8;

	root=CopyBinaryTree(&node1);

	Recoursion(root);
	
	_FreeSpaceBinaryTree(root);
	
}

void _FreeSpaceBinaryTree(BinaryNode* root)
{
	if(NULL==root)
	{
		return;
	}
	//释放左子树
	_FreeSpaceBinaryTree(root->lchild);
	//释放右子树
	_FreeSpaceBinaryTree(root->rchild);
	//释放当前结点
	free(root);
}


int main()
{

	GresteBinaryTree();
	system("pause");
	return 0;
}