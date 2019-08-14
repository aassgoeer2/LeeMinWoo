#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)    // bt�� NULL�̸� ��� Ż��! 
		return;

	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

void DeleteTree(BTreeNode * bt)
{
	if (bt->left != NULL)
		DeleteTree(bt->left);

	if (bt->right != NULL)
		DeleteTree(bt->right);

	free(bt);
}

int main(void)
{
	BTreeNode* bt1 = MakeBTreeNode();	// ��� bt1 ����
	BTreeNode* bt2 = MakeBTreeNode();	// ��� bt2 ����
	BTreeNode* bt3 = MakeBTreeNode();	// ��� bt3 ����
	BTreeNode* bt4 = MakeBTreeNode();	// ��� bt4 ����
	BTreeNode* bt5 = MakeBTreeNode();	// ��� bt5 ����
	BTreeNode* bt6 = MakeBTreeNode();
	BTreeNode* bt7 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);
	SetData(bt7, 7);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeLeftSubTree(bt3, bt6);
	MakeRightSubTree(bt3, bt7);


	////bt1�� ���� �ڽ� ����� ������ ���
	//printf("%d \n", GetData(GetLeftSubTree(bt1)));

	////bt1�� ���� �ڽ� ����� ���� �ڽ� ����� ������ ���
	//printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	InorderTraverse(bt1);

	DeleteTree(bt1);

	return 0;
}