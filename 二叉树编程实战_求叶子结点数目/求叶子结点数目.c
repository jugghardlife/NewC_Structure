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


void CaculateLeafNum(BinaryNode* root,int* leafNum)
{
	if(NULL==root)
	{
		return ;
	}

	if(NULL==root->lchild&&NULL==root->rchild)
	{
		(*leafNum)++;
	}
	//左子树叶子结点的数量
	CaculateLeafNum(root->lchild,leafNum);
	//右子树叶子结点的数量
	CaculateLeafNum(root->rchild,leafNum);
}


void GresteBinaryTree()
{
	int leafNum=0;
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

	//递归求叶子结点
	CaculateLeafNum(&node1,&leafNum);
	printf("叶子结点数量为:%d",leafNum);
}


int main()
{

	GresteBinaryTree();

	system("pause");
	return 0;
}