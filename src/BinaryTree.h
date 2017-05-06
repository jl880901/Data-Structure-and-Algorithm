/*
 * BinaryTree.h
 *
 *  Created on: 2017Äê4ÔÂ21ÈÕ
 *      Author: lajiao
 */

#ifndef SRC_BINARYTREE_H_
#define SRC_BINARYTREE_H_

#include "BinaryTreeNode.h"
#include "BinaryTreeNode.cpp"
#include <vector>

using namespace std;

template<class T>
class BinaryTree;
template<class T>
class BinarySearchTree;

template<class T>
class BinaryTree {
public:
	BinaryTree();
	virtual ~BinaryTree();

	void CreateTree();
	void CreateTreeHelper(const T& val, BinaryTreeNode<T> &leftChildTree,
			BinaryTreeNode<T> &rightChildTree);

	void CreateCompleteBinaryTreeforDemo(vector<T> data);

	void PreOrder(BinaryTreeNode<T>* root);
	void InOrder(BinaryTreeNode<T>* root);
	void PostOrder(BinaryTreeNode<T>* root);
	void PreOrderWithoutRecursion(BinaryTreeNode<T>* root);
	void InOrderWithoutRecursion(BinaryTreeNode<T>* root);
	void PostOrderWithoutRecursion(BinaryTreeNode<T>* root);
	void LevelOrder(BinaryTreeNode<T>* root);

	BinaryTreeNode<T> * GetRoot() {
		return this->root;
	}
	;

protected:
	BinaryTreeNode<T>* root;
};

template<class T>
class BinarySearchTree: public BinaryTree<T>{
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	void CreateBinarySearchTree(vector<T> data);
	void InsertNode(T processingNode);
	void DeleteNode(BinaryTreeNode<T>* processingNode);
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* childNode);
	BinaryTreeNode<T>* Find(T& val);
};

#endif /* SRC_BINARYTREE_H_ */


