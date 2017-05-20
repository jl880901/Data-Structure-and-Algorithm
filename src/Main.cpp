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
#include "HashTable.h"
#include <vector>

using namespace std;

int main() {
	cout << "Welcome to Data Structure and Algorithm class." << endl;

	//DataCreator *dc = new DataCreator(2000);
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
	/*--------------hashtable test---------------*/
	HashTable<int, int> testht(50);
	cout << "Initial bucket count:" << testht.bucket_count() << endl;
	cout << "Initial elements number:" << testht.size() << endl;
	cout << "Max bucket count:" << testht.max_bucket_count() << endl;

	testht.insert_unique(0, 1);
	testht.insert_unique(1, 2);
	testht.insert_unique(2, 3);

	for(int i = 0; i < 52; i++){
		testht.insert_unique(i + 3, i + 4);
	}
	cout << "size: " << testht.size() << endl;
	cout << "bucket count: " << testht.bucket_count() << endl;
	HashTable<int, int>::iterator it;
	//cout << "(" << (*it).first << "," << (*it).second << ")\t";
	for(it = testht.begin(); it != testht.end(); ++it){
		cout << "(" << (*it).first << "," << (*it).second << ")\t";
	}

	testht[5] = 10;
	cout << endl;
	it = testht.find(5);
	cout << "find 5: " << (*it).first << "," << (*it).second << endl;
	testht[100] = 100;
	it = testht.find(100);
	cout << "find 100: " << (*it).first << "," << (*it).second << endl;

	/*--------------RB tree test-----------------*/
	/*RBTree<int> rbt;
	rbt.CreateRedBlackTree(data);
	rbt.InOrder(rbt.getRoot());*/

	/*--------------BS tree test-----------------*/
	/*BinarySearchTree<int> bst;
	bst.CreateBinarySearchTree(data);
	bst.InOrder(bst.GetRoot());
	cout << endl;
	int i = 69;
	BinaryTreeNode<int> *point = bst.Find(i);
	BinaryTreeNode<int> *parent = bst.Parent(point);
	cout << "parent: " << parent->GetVal() << endl;
	bst.DeleteNode(point);
	bst.PostOrder(bst.GetRoot());*/

	/*--------------binary tree test--------------*/
	/*BinaryTree<int> bt;*/
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

