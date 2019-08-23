#pragma once
#include "BinarySearchTree.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

void printIandsub(BTData data)
{
	printf("%d\n", data);
	//printf("%d\n", GetLeftSubTree());
}

void main()

{
	srand(time(NULL));
	BTreeNode * BSTree = MakeBTreeNode();
	BTreeNode * Node;
	BSTData Data;
	SetData(BSTree, 50);

	//for (int i = 1; i <= 100; i++)
	//	BSTInsert(&BSTree, i);

	//InorderTraverse(BSTree, print);

	for (int i = 1; i <= 100; i++)
	{
		Data = rand() % 100 + 1;
		BSTInsert(&BSTree, Data);
	}

	PreorderTraverse(BSTree, printIandsub);
	_getch();
	return;
}