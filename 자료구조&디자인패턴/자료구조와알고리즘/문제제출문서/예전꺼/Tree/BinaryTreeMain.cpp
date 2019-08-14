#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * bt)
{
	if (bt == NULL)    // bt가 NULL이면 재귀 탈출! 
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
	BTreeNode* bt1 = MakeBTreeNode();	// 노드 bt1 생성
	BTreeNode* bt2 = MakeBTreeNode();	// 노드 bt2 생성
	BTreeNode* bt3 = MakeBTreeNode();	// 노드 bt3 생성
	BTreeNode* bt4 = MakeBTreeNode();	// 노드 bt4 생성
	BTreeNode* bt5 = MakeBTreeNode();	// 노드 bt5 생성
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


	////bt1의 왼쪽 자식 노드의 데이터 출력
	//printf("%d \n", GetData(GetLeftSubTree(bt1)));

	////bt1의 왼쪽 자식 노드의 왼쪽 자식 노드의 데이터 출력
	//printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));

	InorderTraverse(bt1);

	DeleteTree(bt1);

	return 0;
}