/*
 * RBTree.h
 *
 *  Created on: 2017Äê5ÔÂ2ÈÕ
 *      Author: lajiao
 */

#ifndef SRC_RBTREE_H_
#define SRC_RBTREE_H_

#include <iostream>
#include <vector>
#include "RBTreeNode.h"
#include "RBTreeNode.cpp"

using namespace std;

template<class T>
class RBTree {
public:
	RBTree();
	virtual ~RBTree();

	void CreateRedBlackTree(vector<T> data);
	void LeftRotate(RBTreeNode<T> *node);
	void RightRotate(RBTreeNode<T> *node);

	void InsertNode(T key);
	void DeleteNode(RBTreeNode<T> *node);
	void RBTreeInsertFixup(RBTreeNode<T> *node);

	void PreOrder(RBTreeNode<T>* root);
	void InOrder(RBTreeNode<T>* root);
	void PostOrder(RBTreeNode<T>* root);

	RBTreeNode<T> * Find(T& key);

	RBTreeNode<T>* getRoot() {
		return root;
	}

private:
	RBTreeNode<T> *root;
	RBTreeNode<T> *sentinel;
};

#endif /* SRC_RBTREE_H_ */
