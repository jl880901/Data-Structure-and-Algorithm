/*
 * Main.cpp
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#include "DataCreator.h"
#include <iostream>
#include "SortAlgorithms.h"
#include "SortAlgorithms.cpp"
#include "BinaryTree.h"
#include "BinaryTree.cpp"
#include "RBTree.h"
#include "RBTree.cpp"
#include <vector>

using namespace std;

int main() {
	cout << "Welcome to Data Structure and Algorithm class." << endl;

	DataCreator *dc = new DataCreator(2000);
	//dc->BuildRandomData(1000); // range 0 - 999;
	//dc->PrintData();
	//dc->WriteToFile("unsort100.txt");

	int idata[] = { 5, 24, 0, 27, 69, 34, 78, 58, 62, 64, 67, 45, 81, 41 };
	vector<int> data(idata, idata + sizeof(idata) / sizeof(int));
	SortAlgorithms<int> sa;
	//sa.BubbleSort(data);
	sa.PrintData(data);

	vector<int> binaryTreeData;
	for (int i = 0; i < 25; i++)
		binaryTreeData.push_back(i + 1);
	/*RBTree<int> rbt;
	rbt.CreateRedBlackTree(data);
	rbt.InOrder(rbt.getRoot());*/
	/*BinaryTree<int> bt;*/
	BinarySearchTree<int> bst;
	bst.CreateBinarySearchTree(data);
	bst.InOrder(bst.GetRoot());
	cout << endl;
	int i = 69;
	BinaryTreeNode<int> *point = bst.Find(i);
	BinaryTreeNode<int> *parent = bst.Parent(point);
	cout << "parent: " << parent->GetVal() << endl;
	bst.DeleteNode(point);
	bst.PostOrder(bst.GetRoot());
	/*bt.CreateCompleteBinaryTreeforDemo(binaryTreeData);
	bt.PreOrder(bt.GetRoot());
	cout << endl;
	bt.PreOrderWithoutRecursion(bt.GetRoot());
	cout << endl;
	bt.PostOrder(bt.GetRoot());
	cout << endl;
	bt.PostOrderWithoutRecursion(bt.GetRoot());
	cout << endl;
	bt.InOrder(bt.GetRoot());
	cout << endl;
	bt.InOrderWithoutRecursion(bt.GetRoot());*/
	cout << "end--" << endl;
}

