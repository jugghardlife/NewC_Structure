#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//���������
typedef struct BINARYNODE
{
	char ch;
	struct BINARYNODE* lchild;
	struct BINARYNODE* rchild;
}BinaryNode;

//����������
void Recoursion(BinaryNode* root)
{
	if(NULL==root)
	{
		return ;
	}

	printf("%c",root->ch);
	//����������
	Recoursion(root->lchild);
	//����������
	Recoursion(root->rchild);
}

//����������
BinaryNode* CopyBinaryTree(BinaryNode* root)
{
	BinaryNode* newnode;
	BinaryNode* lchild;
	BinaryNode* rchild;
	if(NULL==root)
	{
		return NULL;
	}
	//����������
	lchild=CopyBinaryTree(root->lchild);
	//����������
	rchild=CopyBinaryTree(root->rchild);

	//�������
	newnode= (BinaryNode*)malloc(sizeof(BinaryNode));
	newnode->ch=root->ch;
	newnode->lchild=lchild;
	newnode->rchild=rchild;

	return newnode;
}

void GresteBinaryTree()
{
	BinaryNode* root;
	//�������
	BinaryNode node1={'A',NULL,NULL};
	BinaryNode node2={'B',NULL,NULL};
	BinaryNode node3={'C',NULL,NULL};
	BinaryNode node4={'D',NULL,NULL};
	BinaryNode node5={'E',NULL,NULL};
	BinaryNode node6={'F',NULL,NULL};
	BinaryNode node7={'G',NULL,NULL};
	BinaryNode node8={'H',NULL,NULL};
	
	//��������ϵ

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
	//�ͷ�������
	_FreeSpaceBinaryTree(root->lchild);
	//�ͷ�������
	_FreeSpaceBinaryTree(root->rchild);
	//�ͷŵ�ǰ���
	free(root);
}


int main()
{

	GresteBinaryTree();
	system("pause");
	return 0;
}